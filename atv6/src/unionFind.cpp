#include "../include/unionFind.hpp"
#include <iostream>
using namespace std;

UnionFind::UnionFind(int quantidade_subconjuntos) {
    tamanho = quantidade_subconjuntos;
    subconjuntos = new Subconjunto[tamanho];
}

UnionFind::~UnionFind() {
    delete[] subconjuntos;
}

void UnionFind::Make(int x) {
    subconjuntos[x].representante = x;
    subconjuntos[x].rank = 1;
}

int UnionFind::Find(int x) {
    if(subconjuntos[x].representante == x) {
        return x;
    } else {
        return Find(subconjuntos[x].representante);
    }
}

void UnionFind::Union(int x, int y) {
    if(subconjuntos[x].rank == subconjuntos[y].rank) {
        subconjuntos[x].representante = Find(y);
        subconjuntos[x].rank++;  
    }
    if(subconjuntos[x].rank > subconjuntos[y].rank) {
        subconjuntos[y].representante = Find(x);
        subconjuntos[x].rank++;
    }
    else if(subconjuntos[x].rank < subconjuntos[y].rank) {
        subconjuntos[x].representante = Find(y);
        subconjuntos[y].rank++;
    }

    for(int i = 0; i < tamanho; i++) {
        cout << subconjuntos[i].representante << " ";
    }
    cout << endl;
}

