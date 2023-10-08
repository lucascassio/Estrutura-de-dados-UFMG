#include "../include/lista.hpp"

#include <iostream>
#include <vector>

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

void ListaAdjacencia::AdicionarAresta(int v, int w) {
    if (v < numVertices && w < numVertices) {
        NoLista* atualV = inicio;
        while (atualV->vertice != v) {
            atualV = atualV->prox;
        }

        if (atualV != nullptr) {
            atualV->conexoes.push_back(w);
        } else {
            cerr << "Vértice " << v << " não encontrado!" << endl;
        }
    } else {
        cerr << "Vértices inválidos!" << endl;
    }
}

void ListaAdjacencia::ImprimirVizinhos(int v) {
    if(v < numVertices) {
        NoLista* atual = inicio;
        while(atual->vertice != v) {
            atual = atual->prox;
        }

        if(atual != nullptr) {
            for(int n : atual->conexoes) {
                cout << n << " ";
            }
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