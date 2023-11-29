#ifndef ARVORESEG_HPP
#define ARVORESEG_HPP

// Representa uma matriz 2x2 vazia
struct Matriz {
    long int matriz[2][2];
};

// Nó da árvore de segmentação
struct No {
    No* esq;
    No* dir;
    Matriz matriz;

    // Intervalo do nó
    int l;
    int r;

    // Construtor do nó
    No(int l, int r, Matriz ident);
};

// Classe que implementa a árvore de segmentação
class ArvoreSeg {
    public:
        // Construtor
        ArvoreSeg(int numFolhas);
        // Destrutor
        ~ArvoreSeg();
        // Constroi a árvore
        No* constroi(int l, int r);
        // Atualiza á arvore
        Matriz atualizar(int a, Matriz x, No* no);
        // Consulta um intervalo na árvore
        Matriz consultar(int l, int r, No* no);
        // Retorna a raiz
        No* getRaiz();
    private:
        // Função auxiliar do destrutor
        void destrutor(No* no);
        // Multiplica as matrizes
        Matriz multiplica(Matriz a, Matriz b);
        // Raiz da segtree
        No* raiz;
        // Matriz identidade 
        Matriz ident;
};


#endif