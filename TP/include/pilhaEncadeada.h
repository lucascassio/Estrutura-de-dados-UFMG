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
    void Empilha(char item);
    char Desempilha();
    void Limpa();
    int getTamanho();
    char Topo() const;
    bool EstaVazia() const;

private:
    int tamanho = 0;
    Node* topo;
};

#endif
