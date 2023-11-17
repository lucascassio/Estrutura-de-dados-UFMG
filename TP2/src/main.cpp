#include "../include/ordena.hpp"
#include "../include/graph.hpp"
#include "../include/lista.hpp"
#include <iostream>

using namespace std;

// Inicializa os vértices no grafo.
void inicializarVertices(Grafo& grafo, Vertice*& vertices, int nVertices) {
    vertices = new Vertice[nVertices];

    for (int i = 0; i < nVertices; i++) {
        vertices[i].v = i;
        grafo.InsereVertice();
    }
}

// Lê os vizinhos de cada vértice e insere as arestas no grafo.
void lerVizinhos(Grafo& grafo, int nVertices) {
    for (int i = 0; i < nVertices; i++) {
        int nVizinhos;
        cin >> nVizinhos;

        for (int j = 0; j < nVizinhos; j++) {
            int vizinho;
            cin >> vizinho;
            grafo.InsereAresta(i, vizinho);
        }
    }
}

// Atribui cores aos vértices no grafo.
void atribuirCores(Grafo& grafo, Vertice* vertices, int nVertices) {
    for (int i = 0; i < nVertices; i++) {
        int c;
        cin >> c;
        vertices[i].c = c;
        grafo.adicionaCor(i, c);
    }
}

// Aplica o algoritmo de ordenação com base no caractere 'o'.
void aplicarAlgoritmoOrdenacao(Ordena& ordena, Vertice* vertices, char o) {
    if (o == 'b') {
        ordena.bubblesort(vertices);
    } else if (o == 's') {
        ordena.selectionsort(vertices);
    } else if (o == 'i') {
        ordena.insertionsort(vertices);
    } else if (o == 'm') {
        ordena.mergesort(vertices);
    } else if (o == 'p') {
        ordena.heapsort(vertices);
    } else if (o == 'q') {
        ordena.quicksort(vertices);
    } else if (o == 'y') {
        ordena.mysort(vertices);
    }
}

int main() {
    char o;
    cin >> o;
    int nVertices;
    cin >> nVertices;

    Ordena ordena(nVertices);
    Grafo grafo(nVertices);
    Vertice* vertices;

    inicializarVertices(grafo, vertices, nVertices);
    lerVizinhos(grafo, nVertices);
    atribuirCores(grafo, vertices, nVertices);

    aplicarAlgoritmoOrdenacao(ordena, vertices, o);

    for (int i = 0; i < nVertices; i++) {
        // Verifica se a coloração é válida para todos os vértices no grafo.
        if (!grafo.ehGuloso(vertices[i].v, vertices[i].c)) {
            cout << 0 << endl;
            delete[] vertices;
            return 1;
        }
    }

    // Se a coloração é válida, exibe "1" e os índices ordenados dos vértices.
    cout << 1 << " ";
    for (int i = 0; i < nVertices; i++) {
        cout << vertices[i].v << " ";
    }

    delete[] vertices;
    return 0;
}
