#ifndef ORDENA_HPP
#define ORDENA_HPP

class Ordena{
    public:

    Ordena(int maxtam);
    ~Ordena();
    void quicksort(int* &array);
    void mergesort(int* &array);
    void bubblesort(int* &array);
    void selectionsort(int* &array);
    void insertionsort(int* &array);
    void heapsort(int* &array);

    private:
    int tamanho;
    int* array;
    void mergesortRecursao(int* array, int l, int r);
    void mergeArray(int* array, int l, int m, int r);
};

#endif