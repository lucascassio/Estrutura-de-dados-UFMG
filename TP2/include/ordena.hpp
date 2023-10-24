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

    private:
    int tamanho;
    void mergesortRecursao(int* array, int l, int r);
    void mergeArray(int* array, int l, int m, int r);
};

#endif