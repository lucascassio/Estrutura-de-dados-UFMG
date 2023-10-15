#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include <iostream>

using namespace std;

struct TipoNo {
    string item;
    TipoNo* esq;
    TipoNo* dir;
};

class ArvoreBinaria {
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void constroiArvore(string item);
    void caminha(int tipo);
    void limpa();
    void caminhaEAvalia(string expressao, TipoNo *p, int& aux, int& aux2, string& valoracao);
    TipoNo* getRaiz();
    int contarNosPenultimoNivel(TipoNo* p);
private:
    void constroiRecursivo(TipoNo* &p, string item, int pos); 
    void apagaRecursivo(TipoNo* p);
    TipoNo *raiz;
};

#endif