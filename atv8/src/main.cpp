#include <iostream>
using namespace std;
#include "../include/avl.hpp"

int main() {
    Avl arvore;
    TipoNo* no = new TipoNo;
    string palavra;
    int pagina;

    while (cin >> palavra >> pagina) {
        Key indice;
        indice.palavra = palavra, indice.pagina = pagina;
        no = arvore.inserir(no, indice);
    }

    arvore.caminhamentoEmOrdem(no);

    delete no;

    return 0;
}
