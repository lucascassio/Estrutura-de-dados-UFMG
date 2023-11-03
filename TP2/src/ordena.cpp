#include "../include/ordena.hpp"
#include <iostream>
using namespace std;

// Construtor da classe Ordena que aceita o tamanho máximo (maxtam) para o array de Vertice.
Ordena::Ordena(int maxtam) {
    tamanho = maxtam; // Inicializa o tamanho do array.
}

// Destrutor da classe Ordena.
Ordena::~Ordena() {
}

// Função auxiliar para trocar dois elementos no array.
void Ordena::Swap(int a, int b, Vertice* array) {
    Vertice temp = array[b];
    array[b] = array[a];
    array[a] = temp;
}
 
// Método de ordenação bubblesort.
void Ordena::bubblesort(Vertice* array) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (array[j].c > array[j + 1].c) {
                Swap(j, j + 1, array);
            }
        }
    }
}

// Método de ordenação selectionsort.
void Ordena::selectionsort(Vertice* array) {
    int i, j, min_idx;
    for (i = 0; i < tamanho; i++) {
        min_idx = i;
        for (j = i + 1; j < tamanho; j++) {
            // Primeiro critério de ordenação: array[i].c
            if (array[j].c < array[min_idx].c) {
                min_idx = j;
            }
            // Em caso de empate, ordenar por array[i].v
            else if (array[j].c == array[min_idx].c && array[j].v < array[min_idx].v) {
                min_idx = j;
            }
        }
        Swap(min_idx, i, array);  
    }
}

// Método de ordenação insertionsort.
void Ordena::insertionsort(Vertice* array) {
    for (int i = 1; i < tamanho; i++) {
        Vertice aux = array[i];
        int j = i - 1;
        while (j >= 0 && array[j].c > aux.c) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = aux;
    }
}

// Método de ordenação mergesort.
void Ordena::mergesort(Vertice* array) {
    mergesort_recursao(array, 0, tamanho - 1);
}

// Função auxiliar para o mergesort.
void Ordena::mergesort_recursao(Vertice* array, int inicio, int fim) {
    if (inicio < fim) {
        int metade = (inicio + fim) / 2;
        mergesort_recursao(array, inicio, metade);
        mergesort_recursao(array, metade + 1, fim);
        merge(array, inicio, metade, fim);
    }
}

// Função auxiliar do mergesort, merge
void Ordena::merge(Vertice* array, int inicio, int meio, int fim) {
    int tamanho_esquerda = meio - inicio + 1;
    int tamanho_direita = fim - meio;

    Vertice* temp_esquerda = new Vertice[tamanho_esquerda];
    Vertice* temp_direita = new Vertice[tamanho_direita];

    int i, j, k;

    for (i = 0; i < tamanho_esquerda; i++) {
        temp_esquerda[i] = array[inicio + i];
    }

    for (i = 0; i < tamanho_direita; i++) {
        temp_direita[i] = array[meio + 1 + i];
    }

    for (i = 0, j = 0, k = inicio; k <= fim; k++) {
        if ((i < tamanho_esquerda) && (j >= tamanho_direita || (temp_esquerda[i].c < temp_direita[j].c || (temp_esquerda[i].c == temp_direita[j].c)))) {
            array[k] = temp_esquerda[i];
            i++;
        } else {
            array[k] = temp_direita[j];
            j++;
        }
    }

    delete[] temp_esquerda;
    delete[] temp_direita;
}

// Método de ordenação heapsort
void Ordena::heapsort(Vertice* array) {
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(array, tamanho, i);
    }

    for (int i = tamanho - 1; i > 0; i--) {
        Swap(0, i, array);

        heapify(array, i, 0);
    }
}

// Função auxiliar do heapsort, heapify
void Ordena::heapify(Vertice* array, int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && (array[esquerda].c > array[maior].c || (array[esquerda].c == array[maior].c && array[esquerda].v > array[maior].v))) {
        maior = esquerda;
    }

    if (direita < n && (array[direita].c > array[maior].c || (array[direita].c == array[maior].c && array[direita].v > array[maior].v))) {
        maior = direita;
    }

    if (maior != i) {
        Swap(i, maior, array);

        heapify(array, n, maior);
    }
}
// Método de ordenação quicksort.
void Ordena::quicksort(Vertice* array) {
    quicksort_recursao(array, 0, tamanho - 1);
}

// Função auxiliar para o quicksort, que divide e conquista.
void Ordena::quicksort_recursao(Vertice* array, int baixo, int cima) {
    if (baixo < cima) {
        int pivot_index = particao(array, baixo, cima);
        quicksort_recursao(array, baixo, pivot_index - 1);
        quicksort_recursao(array, pivot_index + 1, cima);
    }
}

// Função auxiliar do quicksort, que realiza a partição.
int Ordena::particao(Vertice* array, int baixo, int cima) {
    int pivot_valor = array[cima].c;
    int i = (baixo - 1);

    for (int j = baixo; j <= cima; j++) {
        if (array[j].c < pivot_valor || (array[j].c == pivot_valor && array[j].v < array[cima].v)) {
            i++;
            Swap(i, j, array);
        }
    }

    Swap(i + 1, cima, array);
    return (i + 1);
}

// Estrutura 'cont' para auxiliar na ordenação personalizada.
struct cont {
    int cont;
    int* vertice; 
    int cor;
};

// Método de ordenação personalizada mysort.
void Ordena::mysort(Vertice* array) {
    int MAX = obtemMax(array);

    cont* aux = new cont[MAX + 1]();

    for (int i = 0; i <= MAX; i++) {
        aux[i].vertice = new int[MAX];
    }

    // Conta quantos vértices têm cada cor e associa seus índices.
    for (int i = 0; i < tamanho; i++) {
        aux[array[i].c].cont++;
        aux[array[i].c].vertice[aux[array[i].c].cont - 1] = array[i].v;
        aux[array[i].c].cor = array[i].c;
    }

    int idx = 0;

    // Reconstrói o array original ordenando os vértices por cor.
    for (int i = 0; i <= MAX; i++) {
        int cont = aux[i].cont;
        for (int j = 0; j < cont; j++) {
            array[idx].v = aux[i].vertice[j];
            array[idx].c = aux[i].cor;
            idx++;
        }
    }

    // Libera a memória alocada.
    for (int i = 0; i <= MAX; i++) {
        delete[] aux[i].vertice;
    }
    
    delete[] aux;
}

// Função auxiliar para obter o valor máximo de 'c' no array de Vertice.
int Ordena::obtemMax(Vertice* array) {
    int aux = 0;
    for(int i = 0; i < tamanho; i++) {
        if(array[i].c > aux) {
            aux = array[i].c;
        }
    }
    return aux;
}
