#include "../include/unionFind.hpp"

UnionFind::UnionFind(int quantidade_subconjuntos) {
    tamanho = quantidade_subconjuntos;
    subconjuntos = new Subconjunto[tamanho];
}

UnionFind::~UnionFind() {
    delete[] subconjuntos;
}

void UnionFind::Make(int x) {
    subconjuntos[x].representante = x;
}

int UnionFind::Find(int x) {
    return subconjuntos[x].representante;
}

void UnionFind::Union(int x, int y) {
    if(Find(x) != Find(y)) {
        subconjuntos[x].representante = subconjuntos[y].representante;
    }
}

