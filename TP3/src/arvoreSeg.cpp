#include "../include/arvoreSeg.hpp"
#include <iostream>
using namespace std;

No::No(int l, int r, Matriz ident) {
    esq = nullptr;
    dir = nullptr;
    matriz = ident;
    this->l = l;
    this->r = r;
}

// CONSTRUTOR - Define matriz identidade e chama a construção da árvore
ArvoreSeg::ArvoreSeg(int numFolhas) : raiz(nullptr) {
    if (numFolhas <= 0) {
        cerr << "Erro: O número de folhas deve ser maior que zero." << endl;
    } else {
        ident.matriz[0][0] = 1;
        ident.matriz[0][1] = 0;
        ident.matriz[1][0] = 0;
        ident.matriz[1][1] = 1;
        raiz = constroi(0, numFolhas - 1);
    }
}

// DESTRUTOR - Chama a função auxiliar que desaloca a memória da árvore
ArvoreSeg::~ArvoreSeg() {
    destrutor(raiz);
}

// Função auxiliar do destrutor
void ArvoreSeg::destrutor(No* no) {
    if (no != nullptr) {
        if (no->dir != nullptr) {
            destrutor(no->dir);
        }
        if (no->esq != nullptr) {
            destrutor(no->esq);
        }
        delete no;
    }
}

// Multiplica matrizes
Matriz ArvoreSeg::multiplica(Matriz a, Matriz b) {
    Matriz mResultado;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            long int x = 0;
            for(int k = 0; k < 2; k++) {
                x += (a.matriz[i][k] * b.matriz[k][j]);
            }
            mResultado.matriz[i][j] = x % 100000000;
        }
    }
    return mResultado;
}

// Constroi á arvore de segmentação
No* ArvoreSeg::constroi(int l, int r) {
    No* novoNo = new No(l, r, ident);
    if (l != r) { // Se l != r, então eu uso a recursão pra construir os sucessores do intervalo
        int m = (l + r) / 2;
        novoNo->esq = constroi(l, m);
        novoNo->dir = constroi(m + 1, r);
    }
    return novoNo;
}

// Atualiza a árvore de segmentação
Matriz ArvoreSeg::atualizar(int a, Matriz x, No* no) {
    // Se o índice 'a' está fora do intervalo coberto pelo nó atual,
    // retorna a matriz associada a esse nó sem efetuar alterações.
    if (a < no->l || no->r < a) {
        return no->matriz;
    }

    // Se o nó atual é uma folha, atualiza sua matriz com a nova matriz
    // e retorna o resultado da atualização.
    if (no->l == no->r) {
        return no->matriz = x;
    }

    // Use recursão para atualizar um nó ancestral multiplicando os resultados
    // da atualização nas subárvores esquerda e direita.
    return no->matriz = multiplica(atualizar(a, x, no->esq), atualizar(a, x, no->dir));
}

// Consulta um intervalo na árvore de segmentação
Matriz ArvoreSeg::consultar(int l, int r, No* no) { 
    // Se o intervalo [l, r] está completamente à esquerda ou à direita do nó atual,
    // então retorna a matriz identidade.
    if (r < no->l || no->r < l) {
        return ident;
    }
    
    // Se o intervalo [l, r] está completamente dentro do intervalo coberto pelo nó atual,
    // então retorna a matriz associada a esse nó.
    if (l <= no->l && no->r <= r) {
        return no->matriz;
    }

    // Divide o intervalo [l, r] no ponto médio m.
    int m = (no->l + no->r) / 2;

    // Se o intervalo [l, r] está completamente à esquerda de m,
    // consulta apenas na subárvore esquerda.
    if (r < m + 1) {
        return consultar(l, r, no->esq);
    } 
    // Se o intervalo [l, r] está completamente à direita de m,
    // consulta apenas na subárvore direita.
    else if (l >= m + 1) {
        return consultar(l, r, no->dir);
    }

    // Se o intervalo [l, r] se sobrepõe ao ponto médio m,
    // realiza a consulta em ambas as subárvores e multiplica os resultados.
    return multiplica(consultar(l, m, no->esq), consultar(m + 1, r, no->dir));
}

// Retorna a raiz da árvore
No* ArvoreSeg::getRaiz() {
    return raiz;
}