#include "../include/heap.hpp" 
#include "../include/unionFind.hpp" 

#include <iostream>

using namespace std;

int main() {
    int cont = 0;
    int custo = 0;
    int v, a; cin >> v >> a;
    Heap arestas(a);

    for(int i = 0; i < a; i++) {
        int v, u, c;

        cin >> v >> u >> c;
        Aresta aresta; 
        aresta.u = u;
        aresta.v = v;
        aresta.custo = c;
        arestas.Inserir(aresta);
    }

    UnionFind grafo(v);

    for(int i = 0; i < v; i++) {
        grafo.Make(i);
    }

    for(int i = 0; i < a; i++) {
        Aresta ar = arestas.Remover();
        int a1 = grafo.Find(ar.u);
        int a2 = grafo.Find(ar.v);
        grafo.Union(ar.u, ar.v);
        if(a1 != a2) {
            custo += ar.custo;
        }
    }

    cout << custo << endl;

    return 0;
}