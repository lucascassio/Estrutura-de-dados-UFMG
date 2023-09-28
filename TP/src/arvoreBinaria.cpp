#include "../include/arvoreBinaria.h"
#include "../include/pilhaEncadeada.h"
#include "../include/exp.h"

#include <iostream>

using namespace std;

ArvoreBinaria::ArvoreBinaria() {
    raiz = nullptr;
}

ArvoreBinaria::~ArvoreBinaria() {
    Limpa();
}

void ArvoreBinaria::Insere(string item){
    InsereRecursivo(raiz,item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, string item){
    if(p==NULL){
        p = new TipoNo();
        p->item = item;
    } else {
        if(item < p->item) {
            InsereRecursivo(p->esq, item);
        } else {
            InsereRecursivo(p->dir, item);
        }
    }
}

void ArvoreBinaria::Limpa() {
    ApagaRecursivo(raiz);
    raiz = nullptr;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo* p) {
    if (p != nullptr) {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

void ArvoreBinaria::PosOrdem(TipoNo *p) { 
    if (p != nullptr) {
        PosOrdem(p->esq); 
        PosOrdem(p->dir); 
        cout << p->item << " "; // Imprima ou faça a operação que deseja
    } 
}

void ArvoreBinaria::InOrdem(TipoNo *p) { 
    if (p != nullptr) {
        InOrdem(p->esq);
        cout << p->item << " "; // Imprima ou faça a operação que deseja
        InOrdem(p->dir);
    }
}

void ArvoreBinaria::PreOrdem(TipoNo *p) { 
    if (p != nullptr) {
        cout << p->item << " "; // Imprima ou faça a operação que deseja
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

void ArvoreBinaria::Caminha(int tipo) {
    switch (tipo) {
        case 1: // Pré-ordem
            PreOrdem(raiz);
            break;
        case 2: // Em ordem
            InOrdem(raiz);
            break;
        case 3: // Pós-ordem
            PosOrdem(raiz);
            break;
        default:
            std::cerr << "Tipo de caminhamento inválido!" << std::endl;
    }
}
