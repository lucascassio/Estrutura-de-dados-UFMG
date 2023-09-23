#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include "../include/pilhaEncadeada.h"
#include <iostream>

struct Node {
    std::string item;
    Node* esq;
    Node* dir;
};

class ArvoreBinaria {
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void ConstruirArvore(PilhaEncadeada& pilha);
    void Caminha(int tipo);
    void Limpa();

private:
    void InsereRecursivo(Node* &p, PilhaEncadeada& pilha);
    void ApagaRecursivo(Node* p);
    void PreOrdem(Node* p);
    void InOrdem(Node* p);
    void PosOrdem(Node* p);

    Node* raiz;
};

#endif
