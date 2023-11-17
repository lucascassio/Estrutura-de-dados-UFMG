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

TipoNo* ArvoreBinaria::getRaiz() {
    return raiz;
}

int ArvoreBinaria::contarNosPenultimoNivel(TipoNo* p) {
    if (p == nullptr || (p->esq == nullptr && p->dir == nullptr)) {
        return 0;
    }

    int cont = 0;

    // Se o nó tem filhos no penúltimo nível, incrementa o contador
    if (p->esq != nullptr && (p->esq->esq == nullptr && p->esq->dir == nullptr)) {
        cont++;
    }

    if (p->dir != nullptr && (p->dir->esq == nullptr && p->dir->dir == nullptr)) {
        cont++;
    }

    // Recursivamente conta nos filhos
    cont += contarNosPenultimoNivel(p->esq);
    cont += contarNosPenultimoNivel(p->dir);

    return cont;
}


void ArvoreBinaria::caminhaEAvalia(string expressao, TipoNo *p, int& aux, int& aux2, string& valoracao) {
    if(p == nullptr) {
        cout << "Raiz nula!! Impossível prosseguir" << endl;
        return;
    }
    if((p->dir->dir == nullptr && p->dir->esq == nullptr) || (p->esq->dir == nullptr && p->esq->esq == nullptr)) {
        for (char c : p->item) {
            if (c == 'e') {

                string expressaoLogicaEsq = substituiValoresVariaveis(expressao, p->esq->item);
                string expressaoLogicaDir = substituiValoresVariaveis(expressao, p->dir->item);    

                int resultEsq = avaliaExpressao(expressaoLogicaEsq);
                int resultDir = avaliaExpressao(expressaoLogicaDir);

                if (resultEsq == 1 && resultDir == 1) {
                    valoracao = p->item;
                    aux = 2;
                    aux2++;
                }

                if (resultEsq == 1 && resultDir == 0) {
                    valoracao = p->esq->item;
                    aux = 1;
                    return;
                }

                if (resultEsq == 0 && resultDir == 1) {
                    valoracao = p->dir->item;
                    aux = 1;
                    return;
                }
                
                if (resultEsq == 0 && resultDir == 0) {
                    valoracao = p->dir->item;
                    aux = 0;
                    return;
                }
                

            } else if(c == 'a') {

                string expressaoLogicaEsq = substituiValoresVariaveis(expressao, p->esq->item);
                string expressaoLogicaDir = substituiValoresVariaveis(expressao, p->dir->item);      

                int resultEsq = avaliaExpressao(expressaoLogicaEsq);
                int resultDir = avaliaExpressao(expressaoLogicaDir);

                if (resultEsq == 1 && resultDir == 1) {
                    valoracao = p->item;
                    aux = 2;
                    aux2++;
                }

                if (resultEsq == 1 && resultDir == 0) {
                    aux = 0;
                    return;
                }

                if (resultEsq == 0 && resultDir == 1) {
                    aux = 0;
                    return;
                }
                if (resultEsq == 0 && resultDir == 0) {
                    aux = 0;
                    return;
                }
        } 
    }
    } else {
        caminhaEAvalia(expressao, p->esq, aux, aux2, valoracao);
        caminhaEAvalia(expressao, p->dir, aux, aux2, valoracao);
    } 
}