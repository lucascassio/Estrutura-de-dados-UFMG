# Conjunto de Strings com Operações de Conjuntos e Tabela Hash

Este programa implementa um conjunto de strings com operações básicas de conjuntos, como união, interseção e diferença simétrica. Além disso, utiliza uma tabela hash para armazenar os elementos do conjunto.

## Como usar

1. **Compilar o programa:**
   Execute o comando `make all` para compilar o programa.

2. **Executar o programa:**
   Após a compilação, execute o programa com o seguinte comando:

       ./bin/pa10.out

## Entrada

A entrada do programa consiste em uma série de operações a serem realizadas no conjunto de strings. Cada operação é representada por uma letra seguida por um ou mais parâmetros, quando necessário.

As operações disponíveis são:

- `i <string>`: Inserir a string `<string>` no conjunto.
- `r <string>`: Remover a string `<string>` do conjunto.
- `n <string>`: Verificar se a string `<string>` pertence ao conjunto.
- `u`: Realizar a união entre dois conjuntos. A entrada adicional é um conjunto de strings.
- `t`: Realizar a interseção entre dois conjuntos. A entrada adicional é um conjunto de strings.
- `d`: Calcular a diferença simétrica entre dois conjuntos. A entrada adicional é um conjunto de strings.
- `p`: Imprimir os elementos do conjunto.

Exemplo de entrada:

```plaintext
8
i apple
i banana
i orange
r banana
n orange
u 3 banana apple grape
t 2 orange banana
d 2 banana apple
p


