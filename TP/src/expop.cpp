#include "../include/exp.hpp"
#include "../include/pilhaEncadeada.hpp"
#include "../include/arvoreBinaria.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>  // Adiciona a biblioteca para medição de tempo

using namespace std;
using namespace std::chrono;  // Para usar as funções de medição de tempo

string lerArquivo(const string& caminho) {
    ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        cerr << "Não foi possível abrir o arquivo: " << caminho << endl;
        exit(1);
    }

    string conteudo((istreambuf_iterator<char>(arquivo)), (istreambuf_iterator<char>()));
    return conteudo;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        cout << "Argumentos inválidos !!!" << endl;
        return 1;
    }

    string problema = argv[1];
    string caminhoExpressao = argv[2];
    string caminhoValoracao = argv[3];

    // Ler conteúdo dos arquivos
    string expressaoLogica = lerArquivo(caminhoExpressao);
    string valoracao = lerArquivo(caminhoValoracao);

    auto start = high_resolution_clock::now();  // Inicia a contagem do tempo

    if (problema == "-a") {
        string expressaoLogicaBinaria = substituiValoresVariaveis(expressaoLogica, valoracao);
        cout << avaliaExpressao(expressaoLogicaBinaria) << endl;
    } else if (problema == "-s") {
        verificaSatisfatibilidade(expressaoLogica, valoracao);
    }

    auto stop = high_resolution_clock::now();  // Para a contagem do tempo

    auto duration = duration_cast<milliseconds>(stop - start);  // Calcula a duração em milissegundos
    cout << "Tempo de execução: " << duration.count() << " milliseconds" << endl;

    return 0;
}
