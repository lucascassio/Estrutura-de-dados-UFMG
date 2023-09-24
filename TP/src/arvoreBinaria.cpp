/*#include "../include/arvoreBinaria.h"
#include "../include/pilhaEncadeada.h"

#include <iostream>

using namespace std;

ArvoreBinaria::ArvoreBinaria() {
    raiz = nullptr;
}

ArvoreBinaria::~ArvoreBinaria() {
    Limpa();
}

void ArvoreBinaria::ConstruirArvore(PilhaEncadeada& pilha) {
    if (pilha.getTamanho() == 0) {
        return;
    }

    InsereRecursivo(raiz, pilha);
}

void ArvoreBinaria::InsereRecursivo(Node* &p, PilhaEncadeada& pilha) {
    if (pilha.getTamanho() == 0) {
        return;
    }

    std::string topo = pilha.Desempilha();

    // Verifique se o topo da pilha é um operador ou operando
    bool isOperator = (topo == "|" || topo == "&");

    if (isOperator) {
        p = new Node();
        p->item = topo;

        // Construa a subárvore à esquerda (menor precedência)
        InsereRecursivo(p->esq, pilha);

        // Construa a subárvore à direita (maior precedência)
        InsereRecursivo(p->dir, pilha);
    } else {
        // É um operando
        p = new Node();
        p->item = topo;
        p->esq = nullptr;
        p->dir = nullptr;
    }
}

void ArvoreBinaria::Limpa() {
    ApagaRecursivo(raiz);
    raiz = nullptr;
}

void ArvoreBinaria::ApagaRecursivo(Node* p) {
    if (p != nullptr) {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

void ArvoreBinaria::PosOrdem(Node *p) { 
    if (p != nullptr) {
        PosOrdem(p->esq); 
        PosOrdem(p->dir); 
        cout << p->item << " "; // Imprima ou faça a operação que deseja
    } 
}

void ArvoreBinaria::InOrdem(Node *p) { 
    if (p != nullptr) {
        InOrdem(p->esq);
        cout << p->item << " "; // Imprima ou faça a operação que deseja
        InOrdem(p->dir);
    }
}

void ArvoreBinaria::PreOrdem(Node *p) { 
    if (p != nullptr) {
        cout << p->item << " "; // Imprima ou faça a operação que deseja
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}
*/