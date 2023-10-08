## Atividade Manipulação de Grafos

Este programa em C++ é uma aplicação para realizar operações básicas em grafos, incluindo a obtenção de dados básicos, vizinhanças de vértices e verificar se o grafo é completo.

## Execução

Execute na linha de comando:

    make all

Posteriormente, execute:

    ./bin/pa6.out "operaçao escolhida (-d, -n ou -k)"

As operações podem ser:

“-d” Dados básicos: Deve imprimir na tela, um valor por linha: a quantidade de vértices e de arestas do grafo, o grau mínimo e o máximo.


“-n” Vizinhanças: Deve imprimir os vizinhos de cada um dos vértices. Todos os vizinhos de um vértice devem estar na mesma linha separados por um espaço em branco e encerrando com uma quebra de linha.


“-k” : Deve imprimir 1 caso o grafo de entrada seja um grafo completo e 0 caso contrário

A leitura dos dados do grafo se dará da seguinte forma:

Um inteiro n indicando quantos vértices o grafo possui.

As próximas n linhas contém as vizinhos de cada vértice. Um inteiro m indicando quantos vizinhos o vértice possui seguidos de m inteiros indicando cada vizinho.

Exemplo:

6


2 2 5


3 2 4 5


3 0 1 4


1 5


2 1 2

3 0 1 3


