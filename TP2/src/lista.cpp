#include "../include/lista.hpp"

#include <iostream>

using namespace std;

ListaAdjacencia::ListaAdjacencia() : inicio(nullptr), numVertices(0) {}

ListaAdjacencia::~ListaAdjacencia() {
    NoLista* atual = inicio;
    while (atual != nullptr) {
        NoLista* proximo = atual->prox;
        delete atual;
        atual = proximo;
    }
}


void ListaAdjacencia::AdicionarVertice() {
    NoLista* novoNoLista = new NoLista();
    novoNoLista->vertice = numVertices;
    novoNoLista->conexoes = nullptr;  
    novoNoLista->numConexoes = 0;   
    novoNoLista->prox = nullptr;

    if (inicio == nullptr) {
        inicio = novoNoLista;
    } else {
        NoLista* atual = inicio;
        while (atual->prox != nullptr) {
            atual = atual->prox;
        }
        atual->prox = novoNoLista;
    }

    numVertices++;
}

void ListaAdjacencia::adicionarCor(int v, int c) {
    NoLista* atual = inicio;

    while(v != atual->vertice) {
        atual = atual -> prox;
    }

    atual->cor = c;
}


void ListaAdjacencia::AdicionarAresta(int v, int w) {
    if (v < numVertices && w < numVertices) {
        NoLista* atualV = inicio;
        while (atualV->vertice != v) {
            atualV = atualV->prox;
        }

        if (atualV != nullptr) {
            int* novoArrayConexoes = new int[atualV->numConexoes + 1];
            for (int i = 0; i < atualV->numConexoes; i++) {
                novoArrayConexoes[i] = atualV->conexoes[i];
            }
            novoArrayConexoes[atualV->numConexoes] = w;
            delete[] atualV->conexoes;
            atualV->conexoes = novoArrayConexoes;
            atualV->numConexoes++;
            delete[] novoArrayConexoes;
        } else {
            cerr << "Vértice " << v << " não encontrado!" << endl;
        }
    } else {
        cerr << "Vértices inválidos!" << endl;
    }
}


int* ListaAdjacencia::RetornaVizinhos(int v) {
    if(v < numVertices) {
        NoLista* atual = inicio;
        while(atual->vertice != v) {
            atual = atual->prox;
        }

        if(atual != nullptr) {
            return atual->conexoes;
        }

    } else {
        cerr << "Vértices inválidos!" << endl;
    }
}

int ListaAdjacencia::getVertices() {
    return numVertices;
}

NoLista* ListaAdjacencia::getInicio() {
    return inicio;
}