#ifndef ORDENA_HPP
#define ORDENA_HPP

struct Vertice {
    int v;
    int c;
};

class Ordena{
    public:

    Ordena(int maxtam);
    ~Ordena();
    void quicksort(Vertice* array);
    void mergesort(Vertice* array, int inicio, int fim);
    void bubblesort(Vertice* array);
    void selectionsort(Vertice* array);
    void insertionsort(Vertice* array);
    void heapsort(Vertice* array);

    private:
    int tamanho;
    void quicksort_recursao(Vertice* array, int baixo, int cima);
    int particao(Vertice* array, int baixo, int cima);
    void merge(Vertice* array, int inicio, int metade, int fim);
    void heapify(Vertice* array, int n, int i);
};

#endif