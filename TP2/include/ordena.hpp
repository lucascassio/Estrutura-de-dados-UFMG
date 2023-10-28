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
    void mergesort(Vertice* array);
    void bubblesort(Vertice* array);
    void selectionsort(Vertice* array);
    void insertionsort(Vertice* array);
    void heapsort(Vertice* array);
    void treesort(Vertice* array);

    private:
    int tamanho;
    void Swap(int a, int b, Vertice* array);
    void quicksort_recursao(Vertice* array, int baixo, int cima);
    int particao(Vertice* array, int baixo, int cima);
    void mergesort_recursao(Vertice* array, int meio, int inicio);
    void merge(Vertice* array, int inicio, int metade, int fim);
    void heapify(Vertice* array, int n, int i);
};

#endif