#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include "../include/pilhaEncadeada.h"
#include <iostream>

struct TipoNo {
    string item;
    TipoNo* esq;
    TipoNo* dir;
};

class ArvoreBinaria {
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(string item);
    void Caminha(int tipo);
    void Limpa();
private:
    void InsereRecursivo(TipoNo* &p, string item); 
    void ApagaRecursivo(TipoNo* p);
    void PorNivel();
    void PreOrdem(TipoNo* p);
    void InOrdem(TipoNo* p);
    void PosOrdem(TipoNo* p);
    TipoNo *raiz;
};

#endif
