#include "../include/ordena.hpp"
#include <iostream>

using namespace std;

Ordena::Ordena(int maxtam) {
    tamanho = maxtam;
    array = new int[maxtam];
}

Ordena::~Ordena() {
    delete[] array;
}

void Ordena::bubblesort(int* &array) {
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; tamanho - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

void Ordena::selectionsort(int* &array) {
    int min;
    for(int i = 0; i < tamanho - 1; i++) {
        min = i;
        for(int j = i + 1; j < tamanho; j++) {  
            if(array[j] < array[min]) {
                min = j;
            }
        swap(array[i], array[min]);
        }
    }
}

void Ordena::insertionsort(int* &array) {
    for(int i = 1; i < tamanho; i++) {
        int aux = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > aux) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = aux;
    }
}

void Ordena::mergesort(int* &array) {
    mergesortRecursao(array, 0, tamanho -1);
}

void Ordena::mergesortRecursao(int* array, int l, int r) {
    int m = l + (r - 1) / 2;
}

void Ordena::quicksort(int* &array) {
    
}

void Ordena::heapsort(int* &array) {

}


