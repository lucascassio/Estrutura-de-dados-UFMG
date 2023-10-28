#include "../include/ordena.hpp"
#include "../include/graph.hpp"
#include "../include/lista.hpp"


#include <iostream>
#include <chrono>

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
        grafo.adicionaCor(i, c);
    }

    if (o == 'b') {
        ordena.bubblesort(vertices);
    } else if (o == 's') {
        ordena.selectionsort(vertices);
    } else if (o == 'i') {
        ordena.insertionsort(vertices);
    } else if(o == 'm') {
        ordena.mergesort(vertices);
    } else if(o == 'p') {
        ordena.heapsort(vertices);
    } else if(o == 'q') {
        ordena.quicksort(vertices);
    } else if(o == 'y') {
        ordena.bubblesort(vertices);
    }

    for (int i = 0; i < nVertices; i++) {
        if (!grafo.ehGuloso(vertices[i].v, vertices[i].c)) {
            cout << 0 << endl;
            delete[] vertices; 
            return 1;
        }
    }

    cout << 1 << " ";
    for (int i = 0; i < nVertices; i++) {
        cout << vertices[i].v << " ";
    }

    delete[] vertices;
    return 0;
}