#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "lista.hpp"

class Grafo {
public:
    Grafo(int numVertices); // Construtor que aceita o número de vértices
    ~Grafo(); // Destrutor
    void InsereVertice(); // Função para inserir um vértice no grafo
    void InsereAresta(int v, int w); // Função para inserir uma aresta entre os vértices v e w
    bool ehGuloso(int v, int c); // Função que verifica se um vértice v pode ser colorido com a cor c de forma gulosa
    void adicionaCor(int i, int c); // Função para adicionar a cor c ao vértice i
    int getNumVertices(); // Função para obter o número de vértices no grafo
private:
    ListaAdjacencia vertices; // Estrutura de dados para armazenar os vértices e suas adjacências
};

#endif
