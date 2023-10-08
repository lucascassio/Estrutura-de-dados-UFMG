#include "../include/graph.hpp"
#include "../include/lista.hpp"

#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
    int opt;
    string operacao;

    while ((opt = getopt(argc, argv, "dnk")) != -1) {
        switch (opt) {
            case 'd':
                operacao = "-d";
                break;
            case 'n':
                operacao = "-n";
                break;
            case 'k':
                operacao = "-k";
                break;
            default:
                cerr << "Uso correto: " << argv[0] << " <-d|-n|-k>" << endl;
                return 1;
        }
    }

    if (operacao.empty()) {
        cerr << "Uso correto: " << argv[0] << " <-d|-n|-k>" << endl;
        return 1;
    }

    int nVertices;
    cin >> nVertices;

    Grafo grafo;

    for (int i = 0; i < nVertices; ++i) {
        grafo.InsereVertice();
    }

    for (int i = 0; i < nVertices; ++i) {
        int nVizinhos;
        cin >> nVizinhos;

        for (int j = 0; j < nVizinhos; j++) {
            int vizinho;
            cin >> vizinho;
            grafo.InsereAresta(i, vizinho);
        }
    }

    if (operacao == "-d") {
        cout << grafo.QuantidadeVertices() << endl;
        cout << grafo.QuantidadeArestas() << endl;
        cout << grafo.GrauMinimo() << endl;
        cout << grafo.GrauMaximo() << endl;
    } else if (operacao == "-n") {
        for (int i = 0; i < nVertices; i++) {
            grafo.ImprimeVizinhos(i);
            cout << endl;
        }
    } else if (operacao == "-k") {
        int numVertices = grafo.QuantidadeVertices();
        int numArestasCompleto = (numVertices * (numVertices - 1)) / 2;
        int numArestasAtual = grafo.QuantidadeArestas();
        cout << (numArestasAtual == numArestasCompleto) << endl;
    }

    return 0;
}
