#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

struct NoLista {
    int vertice;
    int* conexoes;
    int cor;
    int numConexoes; 
    NoLista* prox;
};
 

class ListaAdjacencia {
public:
    ListaAdjacencia();
    ~ListaAdjacencia();

    void AdicionarVertice();
    void AdicionarAresta(int v, int w);
    int* RetornaVizinhos(int v);
    int getVertices();
    NoLista* getInicio();
    void adicionarCor(int v, int c);

private:
    NoLista* inicio;
    int numVertices;
};

#endif 
