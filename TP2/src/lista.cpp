#include "../include/lista.hpp"
#include <iostream>

// Construtor da classe ListaAdjacencia que aceita o tamanho máximo MAXTAM.
ListaAdjacencia::ListaAdjacencia(int MAXTAM) {
    numVertices = MAXTAM; // Define o número máximo de vértices.
    vertices = new Vertices[MAXTAM]; // Aloca espaço para o array de vértices.
    qtdInseridos = 0; // Inicializa o contador de vértices inseridos.
}

// Destrutor da classe ListaAdjacencia.
ListaAdjacencia::~ListaAdjacencia() {
    for (int i = 0; i < numVertices; i++) {
        Conexao* conexaoAtual = vertices[i].conexoes;

        // Libera a memória das conexões de cada vértice.
        while (conexaoAtual != nullptr) {
            Conexao* proximaConexao = conexaoAtual->proxima;
            delete conexaoAtual;
            conexaoAtual = proximaConexao;
        }
    }

    delete[] vertices; // Libera a memória do array de vértices.
}

// Função para adicionar um vértice à lista de adjacência.
void ListaAdjacencia::AdicionarVertice() {
    vertices[qtdInseridos].vertice = qtdInseridos;
    vertices[qtdInseridos].cor = -1; // Inicializa a cor como -1 (não atribuída).
    vertices[qtdInseridos].conexoes = nullptr; // Inicializa as conexões como nulas.
    qtdInseridos++; // Incrementa o contador de vértices inseridos.
}

// Função para adicionar uma aresta entre os vértices 'v' e 'w'.
void ListaAdjacencia::AdicionarAresta(int v, int w) {
    if (v < numVertices && w < numVertices) {
        Conexao* conexaoAtual = vertices[v].conexoes;

        if (conexaoAtual == nullptr) {
            // Se não houver conexões, cria uma nova conexão.
            Conexao* novaConexaoV = new Conexao();
            novaConexaoV->vizinho = w;
            novaConexaoV->proxima = nullptr;
            vertices[v].conexoes = novaConexaoV;
        } else {
            // Caso contrário, percorre as conexões existentes.
            while (conexaoAtual->proxima != nullptr) {
                // Verifica se a aresta já existe.
                if (conexaoAtual->vizinho == w) {
                    return; // Se existir, não faz nada.
                }
                conexaoAtual = conexaoAtual->proxima;
            }

            // Adiciona a nova conexão.
            Conexao* novaConexaoV = new Conexao();
            novaConexaoV->vizinho = w;
            novaConexaoV->proxima = nullptr;
            conexaoAtual->proxima = novaConexaoV;
        }
    } else {
        std::cerr << "Vértices inválidos!" << std::endl; // Exibe uma mensagem de erro se os vértices forem inválidos.
    }
}

// Função para obter o número de vértices na lista de adjacência.
int ListaAdjacencia::getNumVertices() {
    return numVertices;
}

// Função para obter a matriz de vértices.
Vertices* ListaAdjacencia::getVertices() {
    return vertices;
}

// Função para adicionar uma cor 'c' ao vértice 'v'.
void ListaAdjacencia::adicionarCor(int v, int c) {
    if (v < numVertices) {
        vertices[v].cor = c;
    } else {
        std::cerr << "Vértice inválido!" << std::endl; // Exibe uma mensagem de erro se o vértice for inválido.
    }
}
