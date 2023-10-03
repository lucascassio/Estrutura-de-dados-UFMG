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

void ArvoreBinaria::ConstroiArvore(string item){
    ConstroiRecursivo(raiz,item,0);
}

// Constroi a Arvore Recursivamente. Código garante que a arvore seja balanceada, para que as valoracoes sempre fique nas folhas
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

// Codigo responsavel por caminhar na arvore binaria, interessado apenas nas folhas, onde estao todas as
void ArvoreBinaria::CaminhaEAvaliaRecursivo(string expressao, TipoNo *p, bool& algumNoResultado1, int& aux, string& valoracao) {
    if (p == nullptr) {
        cout << "Ponteiro para nó é nulo." << endl;
        return;
    }
    if (p->esq == nullptr && p->dir == nullptr) {
        string expressaoLogicaBinaria = atribuiVariaveis(expressao, p->item);
        int result = avaliaExpressao(expressaoLogicaBinaria);
        if (result == 1) {
            valoracao = p->item;
            algumNoResultado1 = true;
            aux++;
        }
    } else {
        CaminhaEAvaliaRecursivo(expressao, p->esq, algumNoResultado1, aux, valoracao);
        CaminhaEAvaliaRecursivo(expressao, p->dir, algumNoResultado1, aux, valoracao);
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
