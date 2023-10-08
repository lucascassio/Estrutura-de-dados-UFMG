#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

using namespace std;

#include <vector>

struct NoLista {
    int vertice;
    vector<int> conexoes;
    NoLista* prox;
};

class ListaAdjacencia {
public:
    ListaAdjacencia();
    ~ListaAdjacencia();

    void AdicionarVertice();
    void AdicionarAresta(int v, int w);
    void ImprimirVizinhos(int v) ;
    int getVertices();
    NoLista* getInicio();

private:
    NoLista* inicio;
    int numVertices;
};

#endif 
