# TP2 - Algoritmo de Coloração Gulosa

## Introdução
Este programa C++ realiza a ordenação de vértices de um grafo e verifica se a coloração dos vértices é válida, utilizando o algoritmo de coloração gulosa.

## Estrutura do Código
O código consiste em várias funções que desempenham papéis específicos:

1. **`inicializarVertices(Grafo& grafo, Vertice*& vertices, int nVertices):`** Aloca memória para os vértices e insere-os no grafo.

2. **`lerVizinhos(Grafo& grafo, int nVertices):`** Lê os vizinhos de cada vértice e insere as arestas correspondentes no grafo.

3. **`atribuirCores(Grafo& grafo, Vertice* vertices, int nVertices):`** Atribui cores aos vértices no grafo com base na entrada.

4. **`aplicarAlgoritmoOrdenacao(Ordena& ordena, Vertice* vertices, char o):`** Aplica um algoritmo de ordenação específico aos vértices. Os caracteres representando cada algoritmo são os seguintes:
   - 'b': Bubblesort
   - 's': Selectionsort
   - 'i': Insertionsort
   - 'm': Mergesort
   - 'p': Heapsort
   - 'q': Quicksort
   - 'y': Algoritmo personalizado (mysort)

5. **`main():`** Função principal que coordena a execução do programa.

## Leitura de Entrada
- O usuário fornece um caractere ('o') representando o tipo de algoritmo de ordenação a ser utilizado.
- O número de vértices no grafo (nVertices) é lido.

## Grafo e Vértices
- Um grafo é representado pela classe `Grafo`.
- A estrutura `Vertice` armazena informações sobre cada vértice, incluindo um identificador (v) e uma cor (c).

## Ordenação e Coloração
- A classe `Ordena` contém métodos para diferentes algoritmos de ordenação.
- Após a ordenação dos vértices, a função verifica se a coloração resultante é válida para todos os vértices usando o método `ehGuloso` da classe `Grafo`.

## Saída
- Se a coloração é válida, o programa imprime "1" seguido pelos índices ordenados dos vértices.
- Se a coloração não é válida, o programa imprime "0" e encerra.

## Uso do Programa
1. Compile o código com `make all`
2. Execute o programa, fornecendo o caractere do algoritmo de ordenação e o número de vértices como entrada.
3. Analise a saída para determinar se a coloração é gulosa ou não.

## Exemplo de Uso
```bash
./tp2.out
m 4
2 1 3
2 0 2
1 3
3 0 1 2
1 0
