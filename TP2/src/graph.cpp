#include <iostream>
#include "../include/graph.hpp"

Grafo::Grafo() {}

Grafo::~Grafo() {
}

void Grafo::InsereVertice() {
    vertices.AdicionarVertice();
}

void Grafo::InsereAresta(int v, int w) {
    vertices.AdicionarAresta(v, w);
}

void Grafo::RetornaVizinhos(int v) {
    vertices.RetornaVizinhos(v);
}

void Grafo::adicionaCor(int v, int c) {
    vertices.adicionarCor(v, c);
}

bool Grafo::ehGuloso(int v, int c) {
    if (c == 1) {
        return true;
    }

    NoLista* atual = vertices.getInicio();
    bool* tdMenores = new bool[c];

    while (v != atual->vertice) {
        atual = atual->prox;
    }

    for (int i = 0; i < atual->numConexoes; i++) {
        int Vvizinho = atual->conexoes[i];

        NoLista* vizinho = vertices.getInicio();
        while (Vvizinho != vizinho->vertice) {
            vizinho = vizinho->prox;
        }

        if (c > vizinho->cor) {
            tdMenores[vizinho->cor] = true;
        }
    }

    for (int i = 1; i <= c - 1; i++) {
        if (!tdMenores[i]) {
            delete[] tdMenores; 
            return false;
        }
    }

    delete[] tdMenores;
    return true;
}



