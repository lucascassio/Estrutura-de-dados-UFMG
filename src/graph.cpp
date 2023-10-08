#include <iostream>

#include "../include/lista.hpp"
#include "../include/graph.hpp"

Grafo::Grafo() {}

Grafo::~Grafo() {}

void Grafo::InsereVertice() {
    vertices.AdicionarVertice();
}

void Grafo::InsereAresta(int v, int w) {
    vertices.AdicionarAresta(v, w);
}

int Grafo::QuantidadeVertices() {
    return vertices.getVertices();
}

int Grafo::QuantidadeArestas() {
    int aux = 0;
    NoLista* atual = vertices.getInicio();
    while (atual != nullptr) {
        for (int n : atual->conexoes) {
            aux++;
        }
        atual = atual->prox; 
    }

    return aux / 2;
}

int Grafo::GrauMinimo() {
    int grauMinimo = 1000000;
    int aux = 0;
    NoLista* atual = vertices.getInicio();
    while(atual != nullptr) {
        for(int n : atual->conexoes) {
            aux++;
        }
        if(aux < grauMinimo) {
            grauMinimo = aux;
        }
        atual = atual->prox;
        aux = 0;
    }

    return grauMinimo;
}

int Grafo::GrauMaximo() {
    int grauMaximo = 0;
    int aux = 0;
    NoLista* atual = vertices.getInicio();
    while(atual != nullptr) {
        for(int n : atual->conexoes) {
            aux++;
        }
        if(aux > grauMaximo) {
            grauMaximo = aux;
        }
        atual = atual->prox;
        aux = 0;
    }

    return grauMaximo;
}

void Grafo::ImprimeVizinhos(int v) {
    vertices.ImprimirVizinhos(v);
}
