#include "../include/exp.hpp"
#include "../include/pilhaEncadeada.hpp"
#include "../include/arvoreBinaria.hpp"
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

    if(problema == "-a") {
        string expressaoLogicaBinaria = substituiValoresVariaveis(expressaoLogica, valoracao);
        cout << avaliaExpressao(expressaoLogicaBinaria) << endl;
    } else if(problema == "-s") {
        verificaSatisfatibilidade(expressaoLogica, valoracao);
    }
    return 0;
}