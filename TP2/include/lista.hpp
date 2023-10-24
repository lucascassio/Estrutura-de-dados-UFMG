#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

struct NoLista {
    int vertice;
    int* conexoes;
    int numConexoes; 
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
