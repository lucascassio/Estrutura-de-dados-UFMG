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

    if(problema == "-a") {
        string expressaoLogicaBinaria = atribuiVariaveis(expressaoLogica, valoracao);
        cout << AvaliaExpressao(expressaoLogicaBinaria) << endl;
    } else if(problema == "-s") {
        ArvoreBinaria arvoreDeValoracao;
        arvoreDeValoracao.ConstroiArvore(valoracao);
        TipoNo* raiz = arvoreDeValoracao.getRaiz();
        string result = arvoreDeValoracao.CaminhaEInsere(expressaoLogica, raiz);
        if(result == "") {
            cout << 0;
        } else {
            cout << 1 << " " << result << endl;
        }
    }
    return 0;
}
