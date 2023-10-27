#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "lista.hpp"

class Grafo{
    public:
        Grafo();
        ~Grafo();
        void InsereVertice();
        void InsereAresta(int v, int w);
        void RetornaVizinhos(int v);
        bool ehGuloso(int v, int c);
        void adicionaCor(int i, int c);
        
    private:
        ListaAdjacencia vertices;
};

#endif