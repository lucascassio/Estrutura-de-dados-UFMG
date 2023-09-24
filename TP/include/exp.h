#ifndef EXP_H
#define EXP_H

#include <iostream>
#include <string>

using namespace std;

int stringPint(string str);
string atribuiVariaveis(string expressao, string valoracao);
bool ehOp(char c);
void atribuirValor(int valoresVariaveis[], const string& expressao, const char* valoracao, int valoracaoLength);
void intPstring(int num, string& str);
int precendencia(char op);
int operacao(int x, int y, char op);
void AvaliaExpressao(string expressao, string valoracao);
void VerficaSatisfabilidade(string expressao, string valoracao);

#endif
