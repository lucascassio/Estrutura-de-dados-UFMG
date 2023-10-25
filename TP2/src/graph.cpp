#include <iostream>
#include "../include/lista.hpp"
#include "../include/graph.hpp"

const long long MAXTAM = 1e12;

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
    int totalArestas = 0;
    NoLista* atual = vertices.getInicio();
    while (atual != nullptr) {
        totalArestas += atual->numConexoes;
        atual = atual->prox;
    }
    return totalArestas / 2;  
}

int Grafo::GrauMinimo() {
    long long grauMinimo = MAXTAM; 
    NoLista* atual = vertices.getInicio();
    while (atual != nullptr) {
        if (atual->numConexoes < grauMinimo) {
            grauMinimo = atual->numConexoes;
        }
        atual = atual->prox;
    }
    return grauMinimo;
}

int Grafo::GrauMaximo() {
    long long grauMaximo = 0;
    NoLista* atual = vertices.getInicio();
    while (atual != nullptr) {
        if (atual->numConexoes > grauMaximo) {
            grauMaximo = atual->numConexoes;
        }
        atual = atual->prox;
    }
    return grauMaximo;
}

void Grafo::RetornaVizinhos(int v) {
    vertices.RetornaVizinhos(v);
}

bool Grafo::ehGuloso(int v, int c) {
    NoLista* atual = vertices.getInicio();
    bool* tdMenores = new bool[c - 1];
    while(v != atual -> vertice) {
        atual = atual -> prox;
    }
    
    for(int i = 0; i < atual->numConexoes; i++) {
        int Vvizinho = atual->conexoes[i];

        NoLista* vizinho = vertices.getInicio();
        while(Vvizinho != vizinho -> vertice) {
            vizinho = vizinho -> prox;
        }

        if(c > vizinho -> cor) {
            tdMenores[vizinho->vertice] = true;
        }

    }

    for(int i = 1; i < c - 1; i++) {
        if(tdMenores[i] == false) {
            return false;
        }
    }

    return true;
}

void Grafo::adicionarCor(int v, int c) {
    vertices.adicionarCor(v, c);
}


