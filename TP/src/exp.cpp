#include "../include/exp.h"
#include "../include/pilhaEncadeada.h"
#include "../include/arvoreBinaria.h"

#include <iostream>
#include <string>

using namespace std;

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

string atribuiVariaveis(string expressao, string valoracao) {
    for (char& c : expressao) {
        if (isDigit(c)) {
            int index = c - '0';
            c = valoracao[index]; 
        }
    }
    return expressao;
}

bool ehOp(char c) {
    return c == '&' || c == '|' || c == '~';
}

int charToInt(char c) {
    return c - '0';
}

int precedencia(char op) {
    if (op == '&') return 2;
    if (op == '|') return 1;
    if (op == '~') return 3;
    return 0;
}

int operacao(int x, int y, char op) {
    if (op == '&') return x * y;
    if (op == '|') { 
        if(x == 1 && y == 1) {
            return 1;
        } else {
            return x + y;
        }
    } 
    if (op == '~') return !x;
    return 0;
}

int AvaliaExpressao(string expressao, string valoracao) {
    PilhaEncadeada binarios;
    PilhaEncadeada operacoes;

    for (char c : expressao) {
        if (c == ' ') {
            continue;
        } 

        else if (c == '(') {
            operacoes.Empilha(c);
        } 

        else if (isDigit(c)) {
            binarios.Empilha(charToInt(c));
        } 

        else if (c == ')') {
            while (operacoes.Topo() != '(') {
                if(operacoes.Topo() == '~') {
                    char op = operacoes.Desempilha();
                    int val1 = operacoes.Desempilha();
                    binarios.Empilha(operacao(val1, 0, op));
                } else {
                    int val1 = binarios.Desempilha();
                    int val2 = binarios.Desempilha();
                    char op = operacoes.Desempilha();
                    binarios.Empilha(operacao(val1, val2, op));
                }

            }
            if (!operacoes.EstaVazia())
                operacoes.Desempilha();
        } 

        else if (c == '~') {
            operacoes.Empilha(c);
        } 

        else if (ehOp(c)) {
            while (!operacoes.EstaVazia() && precedencia(operacoes.Topo()) >= precedencia(c)) {
                char op = operacoes.Desempilha();
                if (op == '~') {
                    int val = binarios.Desempilha();
                    binarios.Empilha(!val);
                } else {
                    int val2 = binarios.Desempilha();
                    int val1 = binarios.Desempilha();
                    binarios.Empilha(operacao(val1, val2, op));
                }
            }
            operacoes.Empilha(c);
        }

    }

    while (!operacoes.EstaVazia()) {
        char op = operacoes.Desempilha();
        if (op == '~') {
            int val = binarios.Desempilha();
            binarios.Empilha(!val);
        } else {
            int val2 = binarios.Desempilha();
            int val1 = binarios.Desempilha();
            binarios.Empilha(operacao(val1, val2, op));
        }
    }

    int result = binarios.Desempilha();
    
    binarios.Limpa();
    operacoes.Limpa();

    return result;
}

string getExpressao(string expressao) {
    return expressao;
}

void VerificaSatisfabilidade(string expressao, string valoracao);
