#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include "../include/pilhaEncadeada.h"
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
    void ConstroiArvore(string item);
    void Caminha(int tipo);
    void Limpa();
    void CaminhaEAvaliaRecursivo(string expressao, TipoNo *p, bool& algumNoResultado1, int& aux, string& valoracao);
    TipoNo* getRaiz();
private:
    void ConstroiRecursivo(TipoNo* &p, string item, int pos); 
    void ApagaRecursivo(TipoNo* p);
    void PorNivel();
    void PreOrdem(TipoNo* p);
    void InOrdem(TipoNo* p);
    void PosOrdem(TipoNo* p);
    TipoNo *raiz;
};

#endif
