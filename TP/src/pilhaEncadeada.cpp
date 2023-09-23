#include "../include/pilhaEncadeada.h"
#include <iostream>

using namespace std;

PilhaEncadeada::PilhaEncadeada() {
    topo = nullptr; 
}

PilhaEncadeada::~PilhaEncadeada() {
    Limpa(); 
}

void PilhaEncadeada::Empilha(string item) {
    Node *novoNo;

    novoNo = new Node();
    novoNo -> item = item;
    novoNo -> prox = topo;
    topo = novoNo;
    tamanho++;
}

string PilhaEncadeada::Desempilha(){ 
    string aux; 
    Node *p;
    if(tamanho == 0) {
        cout << "A pilha está vazia!";
    }
    aux = topo->item;
    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;
    return aux;
};

void PilhaEncadeada::Limpa(){ \
    while(tamanho != 0) {
        Desempilha();
    }
}   

int PilhaEncadeada::getTamanho() {
    return tamanho;
}