#include "../include/exp.h"
#include "../include/pilhaEncadeada.h"
#include "../include/arvoreBinaria.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    if (argc < 4) {
        cout << "Argumentos invalidos !!!";
        return 1;
    }

    string problema = argv[1];
    string expressaoLogica = argv[2];
    string valoracao = argv[3];

    string expressaoLogicaBinaria = atribuiVariaveis(expressaoLogica, valoracao);
    if(problema == "-a") {
        AvaliaExpressao(expressaoLogicaBinaria, valoracao);
    }
    return 0;
}
