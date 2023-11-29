#include "../include/arvoreSeg.hpp"
#include <iostream>

using namespace std;

// Função para ler uma matriz 2x2 a partir da entrada padrão
Matriz leMatriz() {
    Matriz m;
    int elemento;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> elemento;
            m.matriz[i][j] = elemento;
        }
    }
    return m;
}

// Função para ler um ponto (matriz 2x1) a partir da entrada padrão
Matriz lePonto() {
    Matriz m;
    cin >> m.matriz[0][0] >> m.matriz[1][0];
    return m;
}

// Função para imprimir um ponto (matriz 2x1) na saída padrão
void Imprime(Matriz ponto) {
    for (int i = 0; i < 2; i++) {
        cout << ponto.matriz[i][0] << " ";
    }
    cout << endl;
}

// Função para multiplicar uma matriz 2x2 por um ponto (matriz 2x1)
Matriz multiplicaPonto(Matriz matriz, Matriz ponto) {
    Matriz mResultado;
    for (int i = 0; i < 2; i++) {
        long int x = 0;
        for (int j = 0; j < 2; j++) {
            x += matriz.matriz[i][j] * ponto.matriz[j][0];
        }
        mResultado.matriz[i][0] = x % 100000000;
    }
    return mResultado;
}

int main() {
    int numFolhas;
    int numOp;

    // Leitura do número de folhas e número de operações
    cin >> numFolhas;
    cin >> numOp;

    // Inicialização da árvore de segmentação com o número de folhas
    ArvoreSeg arvoreSeg(numFolhas);
    No* raiz = arvoreSeg.getRaiz();

    // Loop para processar as operações
    while(numOp > 0) {
        char op;
        cin >> op;

        if(op == 'u') {
            // Operação de atualização
            int posicao;
            cin >> posicao;
            Matriz m;
            m = leMatriz();
            raiz = arvoreSeg.getRaiz();
            arvoreSeg.atualizar(posicao, m, raiz);
        }

        else if(op == 'q') {
            // Operação de consulta
            int t0;
            int td;
            cin >> t0 >> td;
            Matriz p;
            p = lePonto();
            Matriz m;
            raiz = arvoreSeg.getRaiz();
            m = arvoreSeg.consultar(t0, td, raiz);
            Matriz resultado = multiplicaPonto(m, p);
            Imprime(resultado);
        }
        numOp--;
    }

    return 0;
}
