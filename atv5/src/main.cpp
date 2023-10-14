#include "../include/heap.hpp"
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    Heap heap(t);

    int x = 0;

    for(int i = 0; i < t; i++) {
        cin >> x;
        heap.Inserir(x);
        x = 0;
    }

    heap.getHeap();

    for(int i = 0; i < t; i++) {
        cout << heap.Remover() << " ";
    }

    return 0;
}