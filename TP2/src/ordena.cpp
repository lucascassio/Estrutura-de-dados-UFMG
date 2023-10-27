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
        swap(array[i], array[min]);
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

void Ordena::mergesort(Vertice* array, int inicio, int fim) {
    if(inicio < fim) {
        int metade = (inicio + fim) / 2;
        mergesort(array, inicio, metade);
        mergesort(array, metade + 1, fim);
        merge(array, inicio, metade, fim);
    }
}

void Ordena::merge(Vertice* array, int inicio, int meio, int fim) {
    int tamanho_esquerda = meio - inicio + 1;
    int tamanho_direita = fim - meio;

    Vertice* temp_esquerda = new Vertice[tamanho_esquerda];
    Vertice* temp_direita = new Vertice[tamanho_direita];

    int i, j, k;

    for(int i = 0; i < tamanho_esquerda; i++) {
        temp_esquerda[i] = array[inicio + i];
    }

    for(int i = 0; i < tamanho_direita; i++) {
        temp_direita[i] = array[meio + 1 + i];
    }

    for(i = 0, j = 0, k = inicio; k <= fim; k++) {
        if((i < tamanho_esquerda) && (j >= tamanho_direita || temp_esquerda[i].c <= temp_direita[j].c)) {
            array[k] = temp_esquerda[i];
            i++;
        } else {
            array[k] = temp_direita[j];
            j++;
        }
    }
}

/*
void Ordena::quicksort(Vertice* array) {
    quicksort_recursao(array, 0, tamanho - 1);
}

void Ordena::quicksort_recursao(Vertice* array, int baixo, int cima) {
    if(baixo < cima) {
    int pivot_index = particao(array, baixo, cima);
    quicksort_recursao(array, baixo, pivot_index - 1);
    quicksort_recursao(array, pivot_index + 1, cima);
    }
}

int particao(Vertice* array, int baixo, int cima) {
    int pivot_valor = array[cima].c;
    int i = baixo;

    for(int j = baixo; j < cima; j++) {
        if(array[j] <= pivot_valor) {
            swap(array[j], array[i]);
            i++;
        }
    }
    
    swap(array[j], array[cima]);
}
*/