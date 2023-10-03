#include "../include/pilhaEncadeada.h"
#include <iostream>

// Construtor da classe PilhaEncadeada
PilhaEncadeada::PilhaEncadeada() {
    topo = nullptr;  // Inicializa o topo como nulo
    tamanho = 0;     // Inicializa o tamanho como 0
}

// Destrutor da classe PilhaEncadeada
PilhaEncadeada::~PilhaEncadeada() {
    Limpa();  // Chama o método Limpa() para liberar a memória da pilha
} 

// Método para empilhar um item
void PilhaEncadeada::Empilha(char item) {
    Node* novoNo = new Node();  // Cria um novo nó
    novoNo->item = item;  // Define o item do nó
    novoNo->prox = topo;  // O próximo do novo nó aponta para o antigo topo
    topo = novoNo;  // Atualiza o topo para o novo nó
    tamanho++;  // Incrementa o tamanho da pilha
} 

// Método para obter o elemento no topo da pilha
char PilhaEncadeada::Topo() const {
    if (topo != nullptr) {
        return topo->item;  // Retorna o item do topo
    } else {
        std::cout << "A pilha está vazia, não há topo.\n";
        return '\0';  // Retorna um caractere nulo se a pilha estiver vazia
    }
}

// Método para verificar se a pilha está vazia
bool PilhaEncadeada::EstaVazia() const {
    return tamanho == 0;  // Retorna true se o tamanho for 0, indicando pilha vazia
}

// Método para desempilhar um item
char PilhaEncadeada::Desempilha() {
    char aux = '\0';  // Inicializa um caractere nulo auxiliar
    if (tamanho != 0) {
        aux = topo->item;  // Armazena o item do topo a ser removido
        Node* p = topo;  // Armazena o endereço do topo
        topo = topo->prox;  // Atualiza o topo para o próximo nó
        delete p;  // Libera a memória do nó a ser removido
        tamanho--;  // Decrementa o tamanho da pilha
    } else {
        std::cout << "A pilha está vazia!" << std::endl;
    }
    return aux;  // Retorna o item desempilhado (ou caractere nulo se a pilha estiver vazia)
} 

// Método para limpar a pilha e liberar memória
void PilhaEncadeada::Limpa() {
    while (tamanho != 0) {
        Desempilha();  // Desempilha até que a pilha esteja vazia
    }
}

// Método para obter o tamanho da pilha
int PilhaEncadeada::getTamanho() {
    return tamanho;  // Retorna o tamanho da pilha
}
