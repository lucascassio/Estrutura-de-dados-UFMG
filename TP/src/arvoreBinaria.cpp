#include "../include/arvoreBinaria.hpp"
#include "../include/pilhaEncadeada.hpp"
#include "../include/exp.hpp"

#include <iostream>

using namespace std;

ArvoreBinaria::ArvoreBinaria() {
    raiz = nullptr;
}

ArvoreBinaria::~ArvoreBinaria() {
    limpa();
}

void ArvoreBinaria::constroiArvore(string item){
    constroiRecursivo(raiz, item, 0);
}

void ArvoreBinaria::constroiRecursivo(TipoNo* &p, std::string item, int pos) {
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
        constroiRecursivo(p->esq, item, pos + 1);

        item[pos] = '1';
        constroiRecursivo(p->dir, item, pos + 1);
    } else {
        constroiRecursivo(p, item, pos + 1);
    }
}

void ArvoreBinaria::limpa() {
    apagaRecursivo(raiz);
    raiz = nullptr;
}

void ArvoreBinaria::apagaRecursivo(TipoNo* p) {
    if (p != nullptr) {
        apagaRecursivo(p->esq);
        apagaRecursivo(p->dir);
        delete p;
    }
}

void ArvoreBinaria::posOrdem(TipoNo *p) { 
    if (p != nullptr) {
        posOrdem(p->esq); 
        posOrdem(p->dir); 
        cout << p->item << " "; 
    } 
}

void ArvoreBinaria::inOrdem(TipoNo *p) { 
    if (p != nullptr) {
        inOrdem(p->esq);
        cout << p->item << " "; 
        inOrdem(p->dir);
    }
}

TipoNo* ArvoreBinaria::getRaiz() {
    return raiz;
}

void ArvoreBinaria::preOrdem(TipoNo *p) { 
    if (p != nullptr) {
        cout << p->item << " "; 
        preOrdem(p->esq);
        preOrdem(p->dir);
    }
}

void ArvoreBinaria::caminhaEAvalia(string expressao, TipoNo *p, bool& algumNoResultado1, int& aux, string& valoracao) {
    if (p == nullptr) {
        cout << "A raiz é NULA!! Impossivel prosseguir." << endl;
        return;
    }
    if (p->esq == nullptr && p->dir == nullptr) {
        string expressaoLogicaBinaria = substituiValoresVariaveis(expressao, p->item);
        int result = avaliaExpressao(expressaoLogicaBinaria);
        if (result == 1) {
            valoracao = p->item;
            algumNoResultado1 = true;
            aux++;
        }
    } else {
        caminhaEAvalia(expressao, p->esq, algumNoResultado1, aux, valoracao);
        caminhaEAvalia(expressao, p->dir, algumNoResultado1, aux, valoracao);
    }
}

void ArvoreBinaria::caminha(int tipo) {
    switch (tipo) {
        case 1: 
            preOrdem(raiz);
            break;
        case 2: 
            inOrdem(raiz);
            break;
        case 3: 
            posOrdem(raiz);
            break;
        default:
            std::cerr << "Tipo de caminhamento invalido" << std::endl;
    }
}