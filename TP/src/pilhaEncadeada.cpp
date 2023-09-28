#include "../include/pilhaEncadeada.h"
#include <iostream>

PilhaEncadeada::PilhaEncadeada() {
    topo = nullptr;
    tamanho = 0;
} 

PilhaEncadeada::~PilhaEncadeada() {
    Limpa();
}

void PilhaEncadeada::Empilha(char item) {
    Node* novoNo = new Node();
    novoNo->item = item;
    novoNo->prox = topo;
    topo = novoNo;
    tamanho++;
}

char PilhaEncadeada::Topo() const {
    if (topo != nullptr) {
        return topo->item;
    } else {
        std::cout << "A pilha está vazia, não há topo.\n";
        return '\0';
    }
}

bool PilhaEncadeada::EstaVazia() const {
    return tamanho == 0;
}

char PilhaEncadeada::Desempilha() {
    char aux = '\0'; 
    if (tamanho != 0) {
        aux = topo->item;
        Node* p = topo;
        topo = topo->prox;
        delete p;
        tamanho--;
    } else {
        std::cout << "A pilha está vazia!" << std::endl;
    }
    return aux;
}

void PilhaEncadeada::Limpa() {
    while (tamanho != 0) {
        Desempilha();
    }
}

int PilhaEncadeada::getTamanho() {
    return tamanho;
}
 