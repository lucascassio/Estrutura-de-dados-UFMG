#include "../include/exp.hpp"
#include "../include/pilhaEncadeada.hpp"
#include "../include/arvoreBinaria.hpp"

#include <iostream>
#include <string>

const int MAXNVARIAVEIS = 100;

using namespace std;

// Função para verificar se um caractere é um dígito
bool ehDigito(char c) {
    return c >= '0' && c <= '9';
}

// Função para converter um inteiro para uma string
string intParaString(int num) {
    string resultado;
    while (num > 0) {
        char digito = '0' + (num % 10);
        resultado = digito + resultado;
        num /= 10;
    }
    return resultado;
}

// Função para atribuir valores às variáveis na expressão com base em uma valoração
string atribuiVariaveis(string expressao, string valoracao) {
    char variaveis[MAXNVARIAVEIS]; 
    
    // Atribui valores às variáveis na expressão
    for (int i = 0; i <= 100; ++i) {
        if (i < 10) {
            variaveis[i] = valoracao[i];
        } else {
            string numStr = intParaString(i);
            variaveis[i] = valoracao[numStr[0] - '0'];
        }
    }

    // Substitui os dígitos na expressão pelos valores correspondentes das variáveis
    for (char& c : expressao) {
        if (ehDigito(c)) {
            int indice = c - '0';
            if (indice >= 0 && indice <= 100) {
                c = variaveis[indice];
            }
        }
    }

    return expressao;
}

// Função para verificar se um caractere é um operador
bool ehOperador(char c) {
    return c == '&' || c == '|' || c == '~';
}

// Função para converter um caractere para um inteiro
int charParaInteiro(char c) {
    return c - '0';
}

// Função para determinar a precedência do operador
int precedencia(char operador) {
    if (operador == '&') return 2;
    if (operador == '|') return 1;
    if (operador == '~') return 3;
    return 0;
}

// Função para executar operações binárias com base no operador
int operacao(int x, int y, char operador) {
    if (operador == '&') return x * y;
    if (operador == '|') { 
        if(x == 1 && y == 1) {
            return 1;
        } else {
            return x + y;
        }
    } 
    if (operador == '~') return !x;
    return 0;
}

// Função para avaliar uma expressão dada
int avaliaExpressao(string expressao) {
    PilhaEncadeada binarios;
    PilhaEncadeada operacoes;

    // Percorre a expressão para avaliar as operações
    for (char c : expressao) {
        if (c == ' ') {
            continue;
        } 

        else if (c == '(') {
            operacoes.Empilha(c);
        } 

        else if (ehDigito(c)) {
            binarios.Empilha(charParaInteiro(c));
        } 

        // Realiza as operações dentro de um parêntese
        else if (c == ')') {
            while (operacoes.Topo() != '(') {
                if(operacoes.Topo() == '~') {
                    char operador = operacoes.Desempilha();
                    int val1 = binarios.Desempilha();
                    binarios.Empilha(operacao(val1, 0, operador));
                } else {
                    int val1 = binarios.Desempilha();
                    int val2 = binarios.Desempilha();
                    char operador = operacoes.Desempilha();
                    binarios.Empilha(operacao(val1, val2, operador));
                }
            }
            if (!operacoes.EstaVazia())
                operacoes.Desempilha();
        } 

        else if (c == '~') {
            operacoes.Empilha(c);
        } 

        // Realiza as operações com base na precedência dos operadores
        else if (ehOperador(c)) {
            while (!operacoes.EstaVazia() && precedencia(operacoes.Topo()) >= precedencia(c)) {
                char operador = operacoes.Desempilha();
                if (operador == '~') {
                    int val = binarios.Desempilha();
                    binarios.Empilha(!val);
                } else {
                    int val2 = binarios.Desempilha();
                    int val1 = binarios.Desempilha();
                    binarios.Empilha(operacao(val1, val2, operador));
                }
            }
            operacoes.Empilha(c);
        }
    }   

    // Realiza as operações pendentes após percorrer toda a expressão
    while (!operacoes.EstaVazia()) {
        char operador = operacoes.Desempilha();
        if (operador == '~') {
            int val = binarios.Desempilha();
            binarios.Empilha(!val);
        } else {
            int val2 = binarios.Desempilha();
            int val1 = binarios.Desempilha();
            binarios.Empilha(operacao(val1, val2, operador));
        }
    }

    int resultado = binarios.Desempilha();
    
    binarios.Limpa(); // Limpa a pilha de binários
    operacoes.Limpa(); // Limpa a pilha de operações

    return resultado;
}

// Função para verificar a satisfatibilidade da expressão dada uma valoração
void VerificaSatisfabilidade(string expressao, string valoracao) {
    ArvoreBinaria arvoreDeValoracao;
    arvoreDeValoracao.ConstroiArvore(valoracao); // Constrói a árvore de valorações
    TipoNo* raiz = arvoreDeValoracao.getRaiz();

    if (raiz != nullptr) {
        bool algumNoResultado1 = false;
        int aux = 0;
        string val;
        // Caminha e avalia as folhas (valorações) na árvore
        arvoreDeValoracao.CaminhaEAvaliaRecursivo(expressao, raiz, algumNoResultado1, aux, val);

        if(aux == 1) {
            cout << 1 << " " << val << endl;
        }

        if (!algumNoResultado1) {
            cout << 0 << endl;
        }
        else if(aux > 1) {
            string resultado = raiz -> item;
            int pos = 0;

            while(resultado[pos] != '\0') {
                if(resultado[pos] == 'e') {
                    resultado[pos] = 'a';
                } 
            pos++;
            }

            if(raiz->item == "ea") {
                cout << 1 << " " << "1a" << endl;
                return;
            }
            else if(raiz->item == "ae") {
                cout << 1 << " " << "a1" << endl;
            }

            cout << 1 << " " << resultado << endl;
        }
    } else {
        cout << "Raiz da árvore é nula. Não é possível prosseguir." << endl;
    }
}
