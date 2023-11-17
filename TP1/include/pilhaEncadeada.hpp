#ifndef PILHAENCADEADA_H
#define PILHAENCADEADA_H

struct Node {
    char item;
    Node* prox;
};

class PilhaEncadeada {
public:
    PilhaEncadeada();
    ~PilhaEncadeada();
    void empilha(char item);
    char desempilha();
    void limpa();
    int getTamanho();
    bool estaVazia();
    char topo();

private:
    int tamanho;
    Node* Topo;
};

#endif