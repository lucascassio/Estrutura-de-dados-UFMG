#include "../include/ordena.hpp"
#include "../include/graph.hpp"
#include "../include/lista.hpp"
#include <iostream>

using namespace std;

int main() {
    char o;
    cin >> o; // Lê um caractere que representa o tipo de ordenação a ser usado.
    int nVertices;
    cin >> nVertices; // Lê o número de vértices do grafo.
    Ordena ordena(nVertices); // Cria um objeto da classe Ordena com o número de vértices.
    Grafo grafo(nVertices); // Cria um objeto da classe Grafo com o número de vértices.
    Vertice* vertices = new Vertice[nVertices]; // Aloca espaço para o array de vértices.

    // Loop para inicializar os vértices e inserir no grafo.
    for (int i = 0; i < nVertices; i++) {
        vertices[i].v = i; // Atribui o índice do vértice.
        grafo.InsereVertice(); // Insere um vértice no grafo.
    }

    // Loop para ler as informações de vizinhos e arestas e inserir no grafo.
    for (int i = 0; i < nVertices; i++) {
        int nVizinhos;
        cin >> nVizinhos;

        for (int j = 0; j < nVizinhos; j++) {
            int vizinho;
            cin >> vizinho;
            grafo.InsereAresta(i, vizinho); // Insere uma aresta entre o vértice 'i' e seu vizinho.
        }
    }

    // Loop para ler e atribuir cores aos vértices no grafo.
    for (int i = 0; i < nVertices; i++) {
        int c;
        cin >> c;
        vertices[i].c = c; // Atribui a cor ao vértice.
        grafo.adicionaCor(i, c); // Atribui a cor ao vértice no grafo.
    }

    // Escolhe e aplica o algoritmo de ordenação com base no caractere 'o'.
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

    // Verifica se a coloração é válida para todos os vértices no grafo.
    for (int i = 0; i < nVertices; i++) {
        if (!grafo.ehGuloso(vertices[i].v, vertices[i].c)) {
            cout << 0 << endl;
            return 1; // Se a coloração não é válida, exibe "0" e encerra o programa com erro.
        }
    }

    // Se a coloração é válida, exibe "1" e os índices ordenados dos vértices.
    cout << 1 << " ";
    for (int i = 0; i < nVertices; i++) {
        cout << vertices[i].v << " ";
    }

    delete[] vertices; // Libera a memória alocada para o array de vértices.
    return 0; // Encerra o programa com sucesso.
}
