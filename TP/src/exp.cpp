#include "../include/exp.hpp"
#include "../include/pilhaEncadeada.hpp"
#include "../include/arvoreBinaria.hpp"

#include <iostream>
#include <string>

using namespace std;

// Função para verificar se um caractere é um dígito
bool caractereEhDigito(char c) {
    return c >= '0' && c <= '9';
}

// Função para converter um inteiro para uma string
string inteiroParaString(int num) {
    string resultado;
    while (num > 0) {
        char digito = '0' + (num % 10);
        resultado = digito + resultado;
        num /= 10;
    }
    return resultado;
}

// Função para substituir valores das variáveis na expressão com base em uma valoração
std::string substituiValoresVariaveis(string expressao, string valoracao) {
    string expressaoValorada = "";
    int val = 0;
    int i = 0;

    while (expressao[i] != '\0') {
        if (!caractereEhDigito(expressao[i])) {
            expressaoValorada += expressao[i];
            val = 0;
        } else if (caractereEhDigito(expressao[i])) {
            val = (val * 10) + (expressao[i] - '0');
            if (expressao[i + 1] != '\0' && caractereEhDigito(expressao[i + 1])) {
                val = (val * 10) + (expressao[i + 1] - '0');
                i++;
            }
            expressaoValorada += valoracao[val];
        }
        i++;
    }

    return expressaoValorada;
}


// Função para verificar se um caractere é um operador
bool caractereEhOperador(char c) {
    return c == '&' || c == '|' || c == '~';
}

// Função para converter um caractere para um inteiro
int caractereParaInteiro(char c) {
    return c - '0';
}

// Função para determinar a precedência do operador
int obtemPrecedenciaOperador(char operador) {
    if (operador == '&') return 2;
    if (operador == '|') return 1;
    if (operador == '~') return 3;
    return 0;
}

// Função para executar operações binárias com base no operador
int realizaOperacaoBinaria(int x, int y, char operador) {
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

// Função para realizar operações dentro de um parêntese
void realizarOperacoes(PilhaEncadeada& binarios, PilhaEncadeada& operacoes) {
    char operador = operacoes.desempilha();
    if (operador == '~') {
        int val1 = binarios.desempilha();
        binarios.empilha(realizaOperacaoBinaria(val1, 0, operador));
    } else {
        int val1 = binarios.desempilha();
        int val2 = binarios.desempilha();
        binarios.empilha(realizaOperacaoBinaria(val1, val2, operador));
    }
}

// Função para avaliar uma expressão dada
int avaliaExpressao(string expressao) {
    PilhaEncadeada binarios;
    PilhaEncadeada operacoes;

    // Percorre a expressão para avaliar as operações
    for (char c : expressao) {
        if (c == ' ')
            continue;

        if (c == '(') {
            operacoes.empilha(c);
        } 
        
        else if (caractereEhDigito(c)) {
            binarios.empilha(caractereParaInteiro(c));
        } 
                
        // Realiza as operações dentro de um parêntese
        else if (c == ')') {
            while (operacoes.topo() != '(') {
                realizarOperacoes(binarios, operacoes);
            }
            operacoes.desempilha();
        } 
        
        else if (c == '~') {
            operacoes.empilha(c);
        } 
        
        // Realiza as operações com base na precedência dos operadores
        else if (caractereEhOperador(c)) {
            while (!operacoes.estaVazia() && obtemPrecedenciaOperador(operacoes.topo()) >= obtemPrecedenciaOperador(c)) {
                realizarOperacoes(binarios, operacoes);
            }
            operacoes.empilha(c);
        }
        
    }

    // Realiza as operações pendentes após percorrer toda a expressão, se caso existirem.
    while (!operacoes.estaVazia()) {
        realizarOperacoes(binarios, operacoes);
    }

    int resultado = binarios.desempilha();
    binarios.limpa();
    operacoes.limpa();

    return resultado;
}


// Função para verificar a satisfatibilidade da expressão dada uma valoração
void verificaSatisfatibilidade(string expressao, string valoracao) {
    ArvoreBinaria arvoreDeValoracao;
    arvoreDeValoracao.constroiArvore(valoracao); // Constrói a árvore de valorações
    TipoNo* raiz = arvoreDeValoracao.getRaiz();

    if (raiz != nullptr) {
        bool algumNoResultado1 = false;
        int aux = 0;
        string val;
        // Caminha e avalia as folhas (valorações) na árvore
        arvoreDeValoracao.caminhaEAvalia(expressao, raiz, algumNoResultado1, aux, val);

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
