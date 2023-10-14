#include "../include/heap.hpp"
#include <iostream>

using namespace std;

Heap::Heap(int maxsize) {
    tamanho = 0;
    data = new int[maxsize]; 
}

Heap::~Heap() {
    delete[] data;
}

void Heap::Inserir(int x) {
    data[tamanho] = x;
    int indice = tamanho;
    int pai = GetAncestral(indice);

    while (data[indice] < data[pai]) {
        swap(data[indice], data[pai]);

        indice = pai;
        pai = GetAncestral(indice);
    }

    tamanho++;
}

int Heap::Remover() {
    int raiz = data[0];
    data[0] = data[tamanho - 1];
    tamanho--;

    int indice = 0;
    int sucessor1 = GetSucessorEsq(indice);
    int sucessor2 = GetSucessorDir(indice);

    while (sucessor1 < tamanho || sucessor2 < tamanho) {
        int menorsucessor = indice; // Inicializa com o índice atual

        if (data[sucessor1] < data[menorsucessor]) {
            menorsucessor = sucessor1;
        }
        
        if (data[sucessor2] < data[menorsucessor]) {
            menorsucessor = sucessor2;
        }

        if (menorsucessor != indice) {
            swap(data[indice], data[menorsucessor]);
            indice = menorsucessor;
            sucessor1 = GetSucessorEsq(indice);
            sucessor2 = GetSucessorDir(indice);
        } else {
            break;
        }
    }

    return raiz;
}


bool Heap::Vazio() {
    if(tamanho == 0) {
        return true;
    } else {
        return false;
    }
}
 
int Heap::GetAncestral(int i){
    return (i-1)/2;
}

int Heap::GetSucessorEsq(int i){
    return 2 * i + 1;
}

int Heap::GetSucessorDir(int i){
    return 2 * i + 2;
}

void Heap::getHeap() {
    for(int i = 0; i < tamanho; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}