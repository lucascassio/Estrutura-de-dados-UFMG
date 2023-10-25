#include "../include/ordena.hpp"
#include <iostream>

using namespace std;

Ordena::Ordena(int maxtam) {
    tamanho = maxtam;
}

Ordena::~Ordena() {
}

void Ordena::bubblesort(Vertice* array) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (array[j].c > array[j + 1].c) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void Ordena::selectionsort(Vertice* array) {
    int min;
    for (int i = 0; i < tamanho - 1; i++) {
        min = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (array[j].c < array[min].c) {
                min = j;
            }
        }
        swap(array[i], array[min]); // Moved outside the inner loop
    }
}

void Ordena::insertionsort(Vertice* array) {
    for(int i = 1; i < tamanho; i++) {
        int aux = array[i].c;
        int j = i - 1;
        while(j >= 0 && array[j].c > aux) {
            array[j + 1].c = array[j].c;
            j = j - 1;
        }
        array[j + 1].c = aux;
    }
}


