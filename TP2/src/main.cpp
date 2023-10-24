#include "../include/ordena.hpp"
#include "../include/graph.hpp"
#include <iostream>

using namespace std; 

int main() {

    int o; int v;
    cin >> o >> v;
    Ordena ordena(v);
    Grafo grafo;
    int nVertices;
    cin >> nVertices;

    for (int i = 0; i < nVertices; i++) {
        grafo.InsereVertice();
    }

    for (int i = 0; i < nVertices; i++) {
        int nVizinhos;
        cin >> nVizinhos;

        for (int j = 0; j < nVizinhos; j++) {
            int vizinho;
            cin >> vizinho;
            grafo.InsereAresta(i, vizinho);
        }
    }

    return 0;
}

