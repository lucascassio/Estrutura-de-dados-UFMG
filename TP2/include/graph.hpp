#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "lista.hpp"
#include "ordena.hpp"

class Grafo{
    public:
        Grafo();
        ~Grafo();
        void InsereVertice();
        void InsereAresta(int v, int w);
        int QuantidadeVertices();
        int QuantidadeArestas();
        int GrauMinimo();
        int GrauMaximo();
        void RetornaVizinhos(int v);
        bool ehGuloso(int v, int c);
        void adicionarCor(int i, int c);
        
    private:
        ListaAdjacencia vertices;
};

#endif