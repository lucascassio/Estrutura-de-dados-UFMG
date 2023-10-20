#include "../include/heap.hpp"
#include <iostream>

using namespace std;

Heap::Heap(int maxsize) {
    tamanho = 0;
    data = new Aresta[maxsize]; 
}

Heap::~Heap() {
    delete[] data;
}

void Heap::Inserir(Aresta x) {
    data[tamanho] = x;
    int indice = tamanho;
    int pai = GetAncestral(indice);

    while (data[indice].custo < data[pai].custo) {
        swap(data[indice], data[pai]);

        indice = pai;
        pai = GetAncestral(indice);
    }

    tamanho++;
}

Aresta Heap::Remover() {
    Aresta raiz = data[0];
    data[0] = data[tamanho - 1];
    tamanho--;

    int indice = 0;
    int sucessor1 = GetSucessorEsq(indice);
    int sucessor2 = GetSucessorDir(indice);

    while (sucessor1 < tamanho || sucessor2 < tamanho) {
        int menorsucessor = indice;

        if (data[sucessor1].custo < data[menorsucessor].custo) {
            menorsucessor = sucessor1;
        }
        
        if (data[sucessor2].custo < data[menorsucessor].custo) {
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