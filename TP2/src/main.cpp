#include "../include/ordena.hpp"
#include "../include/graph.hpp"
#include "../include/lista.hpp"

#include <iostream>

using namespace std;

int main() {
    char o;
    cin >> o;
    int nVertices;
    cin >> nVertices;
    Ordena ordena(nVertices);
    Grafo grafo;

    Vertice* vertices = new Vertice[nVertices];

    for (int i = 0; i < nVertices; i++) {
        vertices[i].v = i;
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
    for (int i = 0; i < nVertices; i++) {
        int c;
        cin >> c;
        vertices[i].c = c;
        grafo.adicionarCor(i, c);
    }

    ordena.bubblesort(vertices);

    for(int i =0; i < nVertices; i++) {
        if(!grafo.ehGuloso(vertices[i].v, vertices[i].c, nVertices)) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }

    
  
    return 0;
}
