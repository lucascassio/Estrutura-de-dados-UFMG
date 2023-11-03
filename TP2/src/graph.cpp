#include <iostream>
#include "../include/graph.hpp"

// Construtor da classe Grafo que aceita o número de vértices.
Grafo::Grafo(int numVertices) : vertices(numVertices) {
    // Inicialize a ListaAdjacencia com o número de vértices.
}

// Destrutor da classe Grafo.
Grafo::~Grafo() {
}

// Função para inserir um vértice no grafo.
void Grafo::InsereVertice() {
    vertices.AdicionarVertice();
}

// Função para inserir uma aresta entre os vértices v e w.
void Grafo::InsereAresta(int v, int w) {
    vertices.AdicionarAresta(v, w);
}

// Função para adicionar uma cor 'c' ao vértice 'v'.
void Grafo::adicionaCor(int v, int c) {
    vertices.adicionarCor(v, c);
}

// Função para verificar se um vértice 'v' pode ser colorido com a cor 'c' de forma gulosa.
bool Grafo::ehGuloso(int v, int c) {
    if (c == 1) {
        return true; // Se c for 1, o vértice pode ser colorido.
    }

    int n = vertices.getNumVertices(); // Obtém o número total de vértices.

    bool* tdMenores = new bool[c]; // Cria um array para rastrear cores menores que 'c'.
    Vertices* vert = new Vertices[n]; // Cria um array de vértices.
    vert = vertices.getVertices(); // Obtém a matriz de vértices da ListaAdjacencia.

    Conexao* conexaoAtual = vert[v].conexoes; // Obtém as conexões do vértice 'v'.

    // Percorre as conexões do vértice 'v' para verificar cores menores.
    while (conexaoAtual != nullptr) {
        if (vert[v].cor > vert[conexaoAtual->vizinho].cor) {
            tdMenores[vert[conexaoAtual->vizinho].cor] = true;
        }
        conexaoAtual = conexaoAtual->proxima;
    }

    // Verifica se todas as cores menores que 'c' estão presentes.
    for (int i = 1; i <= c - 1; i++) {
        if (!tdMenores[i]) {
            delete[] tdMenores;
            return false; // Não é possível colorir o vértice 'v' com a cor 'c'.
        }
    }

    delete[] tdMenores;
    return true; // É possível colorir o vértice 'v' com a cor 'c'.
}
