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
string substituiValoresVariaveis(string expressao, string valoracao) {
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
    if (operador == '~') {
        return !x;
    }
    return 0;
}

// Função para realizar operações dentro de um parêntese
void processarOperacoes(PilhaEncadeada& binarios, PilhaEncadeada& operacoes) {
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
                processarOperacoes(binarios, operacoes);
            }
            operacoes.desempilha();
        } 
        
        else if (c == '~') {
            operacoes.empilha(c);
        } 
        
        // Realiza as operações com base na precedência dos operadores
        else if (caractereEhOperador(c)) {
            while (!operacoes.estaVazia() && obtemPrecedenciaOperador(operacoes.topo()) >= obtemPrecedenciaOperador(c)) {
                processarOperacoes(binarios, operacoes);
            }
            operacoes.empilha(c);
        }
        
    }

    // Realiza as operações pendentes após percorrer toda a expressão, se caso existirem.
    while (!operacoes.estaVazia()) {
        processarOperacoes(binarios, operacoes);
    }

    int resultado = binarios.desempilha();
    binarios.limpa();
    operacoes.limpa();

    return resultado;
}


// Função para verificar a satisfatibilidade da expressão dada uma valoração
// Função para verificar a satisfatibilidade da expressão dada uma valoração
void verificaSatisfatibilidade(string expressao, string valoracao) {
    ArvoreBinaria arvoreDeValoracao;
    arvoreDeValoracao.constroiArvore(valoracao); // Constrói a árvore de valorações
    TipoNo* raiz = arvoreDeValoracao.getRaiz();

    if (raiz != nullptr) {
        // Check if the root contains only digits
        bool isRootDigits = true;
        for (char c : raiz->item) {
            if (!caractereEhDigito(c)) {
                isRootDigits = false;
                break;
            }
        }

        if (isRootDigits) {
            int resultado = avaliaExpressao(valoracao);
            if (resultado == 1)
                cout << 1 << " " << valoracao << endl;
            else
                cout << 0 << endl;
            return;
        }

        int aux = 0;
        int aux2 = 0;
        string val;

        bool raizSemE = true;

        for (char c : raiz->item) {
            if (c == 'e') {
                raizSemE = false;
                break;
            }
        }

        arvoreDeValoracao.caminhaEAvalia(expressao, raiz, aux, aux2, val);

        if (raizSemE) {
            int numNosPenultimoNivel = arvoreDeValoracao.contarNosPenultimoNivel(raiz);
            if (numNosPenultimoNivel > 2 && aux2 != numNosPenultimoNivel) {
                cout << 0 << endl;
                return;
            }
        }

        if (aux == 1) {
            cout << 1 << " " << val << endl;
            return;
        } else if (aux > 1) {  
            if (aux2 > 1) {
                for (char &c : raiz->item) {
                    if (c == 'e') {
                        c = 'a';
                    } else if (c == 'a') {
                        c = 'a';
                    }
                }
                cout << 1 << " " << raiz->item << endl;
                return;
            }
            for (char &c : val) {
                if (c == 'e') {
                    c = 'a';
                } else if (c == 'a') {
                    c = 'a';
                }
            }
            cout << 1 << " " << val << endl;
            return;
        } else {
            cout << 0 << endl;
            return;
        }
    } else {
        cout << "Raiz da árvore é nula. Não é possível prosseguir." << endl;
    }
}
