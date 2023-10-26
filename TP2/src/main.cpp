#include "../include/ordena.hpp"
#include "../include/graph.hpp"
#include "../include/lista.hpp"


#include <iostream>
#include <chrono>

using namespace std;

int main() {
    auto start = std::chrono::high_resolution_clock::now();
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
    }

    for (int i = 0; i < nVertices; i++) {
        if (!grafo.ehGuloso(vertices[i].v, vertices[i].c)) {
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            cout << "Tempo de execução: " << duration.count() << " microssegundos" << endl;
            cout << 0 << endl;
            delete[] vertices; 
            return 1;
        }
    }

    cout << 1 << " ";
    for (int i = 0; i < nVertices; i++) {
        cout << vertices[i].v << " ";
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    delete[] vertices;
    return 0;
}