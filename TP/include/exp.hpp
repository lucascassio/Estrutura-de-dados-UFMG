#ifndef EXP_H
#define EXP_H

#include <string>
using namespace std;

bool caractereEhDigito(char c);
string inteiroParaString(int num);
string substituiValoresVariaveis(string expressao, string valoracao);
bool caractereEhOperador(char c);
int caractereParaInteiro(char c);
int obtemPrecedenciaOperador(char operador);
int realizaOperacao(int x, int y, char operador);
int avaliaExpressao(string expressao);
void verificaSatisfatibilidade(string expressao, string valoracao);

#endif 
