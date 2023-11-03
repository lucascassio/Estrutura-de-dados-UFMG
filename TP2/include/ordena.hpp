#ifndef ORDENA_HPP
#define ORDENA_HPP

// Define a estrutura de dados para representar um vértice com valores 'v' e 'c'.
struct Vertice {
    int v; // Valor 'v' do vértice.
    int c; // Valor 'c' do vértice.
};

// Classe Ordena é responsável por implementar diferentes algoritmos de ordenação.
class Ordena {
public:
    Ordena(int maxtam); // Construtor que aceita o tamanho máximo.
    ~Ordena(); // Destrutor
    void quicksort(Vertice* array); // Método para realizar o algoritmo de ordenação quicksort.
    void mergesort(Vertice* array); // Método para realizar o algoritmo de ordenação mergesort.
    void bubblesort(Vertice* array); // Método para realizar o algoritmo de ordenação bubblesort.
    void selectionsort(Vertice* array); // Método para realizar o algoritmo de ordenação selectionsort.
    void insertionsort(Vertice* array); // Método para realizar o algoritmo de ordenação insertionsort.
    void heapsort(Vertice* array); // Método para realizar o algoritmo de ordenação heapsort.
    void mysort(Vertice* array); // Método personalizado de ordenação.

private:
    int tamanho; // Tamanho máximo para o array de vértices.

    // Função privada para realizar a troca de elementos em um array.
    void Swap(int a, int b, Vertice* array);

    // Funções privadas para implementação do quicksort.
    void quicksort_recursao(Vertice* array, int baixo, int cima);
    int particao(Vertice* array, int baixo, int cima);

    // Funções privadas para implementação do mergesort.
    void mergesort_recursao(Vertice* array, int meio, int inicio);
    void merge(Vertice* array, int inicio, int metade, int fim);

    // Função privada para transformar um array em um heap.
    void heapify(Vertice* array, int n, int i);

    // Função privada para obter o valor da coloração máxima. Usado no mysort.
    int obtemMax(Vertice* array);
};

#endif
