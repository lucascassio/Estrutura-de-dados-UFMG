#include "../include/pilhaEncadeada.hpp"
#include <iostream>

using namespace std;

PilhaEncadeada::PilhaEncadeada() {
    Topo = nullptr;  // Inicializa o Topo como nulo
    tamanho = 0;     // Inicializa o tamanho como 0
}

PilhaEncadeada::~PilhaEncadeada() {
    limpa();  // Chama o método limpa() para liberar a memória da pilha
} 

void PilhaEncadeada::empilha(char item) {
    Node* novoNo = new Node();  // Cria um novo nó
    novoNo->item = item;  // Define o item do nó
    novoNo->prox = Topo;  // O próximo do novo nó aponta para o antigo Topo
    Topo = novoNo;  // Atualiza o Topo para o novo nó
    tamanho++;  // Incrementa o tamanho da pilha
} 

char PilhaEncadeada::topo() {
    if (Topo != nullptr) {
        return Topo->item;  // Retorna o item do Topo
    } else {
        cout << "A pilha está vazia, não há Topo.\n";
        return '\0';  // Retorna um caractere nulo se a pilha estiver vazia
    }
}

bool PilhaEncadeada::estaVazia() {
    return tamanho == 0;  // Retorna true se o tamanho for 0, indicando pilha vazia
}

char PilhaEncadeada::desempilha() {
    char aux = '\0';  // Inicializa um caractere nulo auxiliar
    if (tamanho != 0) {
        aux = Topo->item;  // Armazena o item do Topo a ser removido
        Node* p = Topo;  // Armazena o endereço do Topo
        Topo = Topo->prox;  // Atualiza o Topo para o próximo nó
        delete p;  // Libera a memória do nó a ser removido
        tamanho--;  // Decrementa o tamanho da pilha
    } else {
        cout << "A pilha está vazia!" << endl;
    }
    return aux;  // Retorna o item desempilhado (ou caractere nulo se a pilha estiver vazia)
} 

void PilhaEncadeada::limpa() {
    while (tamanho != 0) {
        desempilha();  // Desempilha até que a pilha esteja vazia
    }
}

int PilhaEncadeada::getTamanho() {
    return tamanho;  // Retorna o tamanho da pilha
}