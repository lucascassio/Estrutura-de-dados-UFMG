# TP3 - Operações de Transformações Lineares com Segtree

## Objetivo
O objetivo deste programa em C++ é realizar operações de transformações lineares em um conjunto de pontos usando uma estrutura de dados chamada Segtree (Árvore de Segmentação). Ele aceita operações de atualização e consulta, permitindo a aplicação de transformações lineares em um conjunto de pontos em um intervalo específico.

## Estrutura do Código
O código é composto por funções para leitura de matrizes, pontos e implementação de operações de transformações lineares. Utiliza a classe `ArvoreSeg` para representar a Segtree.

## Leitura de Entrada
- O programa inicia lendo o número de folhas e o número de operações a serem realizadas.
- Cada operação é representada por um caractere ('u' para atualização e 'q' para consulta).

## Operações
### Atualização ('u')
- Atualiza uma posição específica da Segtree com uma matriz fornecida.

### Consulta ('q')
- Consulta a Segtree para obter uma matriz resultante de operações lineares em um intervalo de folhas. 
- Multiplica essa matriz pelo ponto fornecido e imprime o resultado na saída padrão.

## Uso do Programa
1. Compile o código.
2. Execute o programa e forneça o número de folhas e o número de operações.
3. Para cada operação, forneça o caractere ('u' ou 'q') seguido dos parâmetros necessários.
   - Para operações de atualização ('u'), forneça a posição e os elementos da matriz.
   - Para operações de consulta ('q'), forneça os limites do intervalo e o ponto.

## Exemplo de Uso
```bash
./seu_programa
4 5
u 1 1 0 0 1
q 2 4 2 3
u 3 2 1 0 1
q 1 3 1 2
q 2 4 2 3
