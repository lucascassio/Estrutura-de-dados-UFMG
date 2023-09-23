#ifndef PILHAENCADEADA_H
#define PILHAENCADEADA_H

#include <string>

using namespace std;

struct Node {
    string item;
    Node* prox;
};

class PilhaEncadeada {
    public:
    PilhaEncadeada();
    virtual ~PilhaEncadeada();
    void Empilha(string item); 
    string Desempilha();
    void Limpa();
    int getTamanho();

    private:
        int tamanho = 0;
        Node* topo;
    };

#endif
