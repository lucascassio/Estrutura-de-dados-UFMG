#ifndef EXP_H
#define EXP_H

#include <string>

bool ehDigito(char c);
std::string intParaString(int num);
std::string atribuiVariaveis(std::string expressao, std::string valoracao);
bool ehOperador(char c);
int charParaInteiro(char c);
int precedencia(char operador);
int operacao(int x, int y, char operador);
int avaliaExpressao(std::string expressao);
void VerificaSatisfabilidade(std::string expressao, std::string valoracao);

#endif 
