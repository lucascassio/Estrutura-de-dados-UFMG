#ifndef EXP_H
#define EXP_H

#include <string>

bool caractereEhDigito(char c);
std::string inteiroParaString(int num);
std::string substituiValoresVariaveis(std::string expressao, std::string valoracao);
bool caractereEhOperador(char c);
int caractereParaInteiro(char c);
int obtemPrecedenciaOperador(char operador);
int realizaOperacao(int x, int y, char operador);
int avaliaExpressao(std::string expressao);
void verificaSatisfatibilidade(std::string expressao, std::string valoracao);

#endif 