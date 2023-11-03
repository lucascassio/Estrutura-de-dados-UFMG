#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

// Define uma estrutura de dados para representar uma conexão entre vértices.
struct Conexao {
    int vizinho; // Armazena o índice do vértice vizinho.
    Conexao* proxima; // Ponteiro para a próxima conexão.
};

// Define uma estrutura de dados para representar vértices.
struct Vertices {
    int vertice; // Armazena o índice do vértice.
    int cor; // Armazena a cor atribuída ao vértice.
    Conexao* conexoes; // Ponteiro para as conexões com outros vértices.
};

// Classe ListaAdjacencia representa uma estrutura de lista de adjacência.
class ListaAdjacencia {
public:
    ListaAdjacencia(int numVertices); // Construtor que aceita o número de vértices.
    ~ListaAdjacencia(); // Destrutor
    void AdicionarVertice(); // Adiciona um vértice à lista de adjacência.
    void AdicionarAresta(int v, int w); // Adiciona uma aresta entre os vértices v e w.
    void adicionarCor(int v, int c); // Define a cor do vértice v.

    int getNumVertices(); // Método para obter o número de vértices na lista de adjacência.
    Vertices* getVertices(); // Método para obter a matriz de vértices.

private:
    int qtdInseridos; // Armazena o número de vértices inseridos.
    int numVertices; // Armazena o número total de vértices.
    Vertices* vertices; // Ponteiro para a matriz de vértices.
};

#endif
