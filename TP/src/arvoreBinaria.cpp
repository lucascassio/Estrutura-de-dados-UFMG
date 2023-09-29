#include "../include/arvoreBinaria.h"
#include "../include/pilhaEncadeada.h"
#include "../include/exp.h"
#include "../src/expop.cpp"

#include <iostream>

using namespace std;

ArvoreBinaria::ArvoreBinaria() {
    raiz = nullptr;
}

ArvoreBinaria::~ArvoreBinaria() {
    Limpa();
}

void ArvoreBinaria::ConstroiArvore(string item){
    ConstroiRecursivo(raiz,item,0);
}

void ArvoreBinaria::ConstroiRecursivo(TipoNo* &p, std::string item, int pos) {
    if (item[pos] == '\0') {
        p = new TipoNo();
        p->item = item;
        p->esq = nullptr;
        p->dir = nullptr;
        return;
    }

    p = new TipoNo();
    p->item = item;

    char c = item[pos];
    if (c == 'a' || c == 'e') {
        item[pos] = '0';
        ConstroiRecursivo(p->esq, item, pos + 1);

        item[pos] = '1';
        ConstroiRecursivo(p->dir, item, pos + 1);
    } else {
        ConstroiRecursivo(p, item, pos + 1);
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
        cout << p->item << " "; 
    } 
}

void ArvoreBinaria::InOrdem(TipoNo *p) { 
    if (p != nullptr) {
        InOrdem(p->esq);
        cout << p->item << " "; 
        InOrdem(p->dir);
    }
}

TipoNo* ArvoreBinaria::getRaiz() {
    return raiz;
}

void ArvoreBinaria::PreOrdem(TipoNo *p) { 
    if (p != nullptr) {
        cout << p->item << " "; 
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

string ArvoreBinaria::CaminhaEInsere(string expressao, TipoNo *p) {
    int paraTodos = 0;
    string valorFinal;
    if(p == nullptr) {
    if(p->esq == nullptr && p->dir == nullptr) {
        string expressaoLogicaBinaria = atribuiVariaveis(expressao, p->item);
        if(AvaliaExpressao(expressaoLogicaBinaria) == 1) {
            return p->item;
        } else {
            return "0";
        }
    } else {
        CaminhaEInsere(expressao,p->esq);
        CaminhaEInsere(expressao,p->dir);
    }
    }
}
void ArvoreBinaria::Caminha(int tipo) {
    switch (tipo) {
        case 1: 
            PreOrdem(raiz);
            break;
        case 2: 
            InOrdem(raiz);
            break;
        case 3: 
            PosOrdem(raiz);
            break;
        default:
            std::cerr << "Tipo de caminhamento inválido!" << std::endl;
    }
}
