# Lógica Computacional: Problemas Clássicos e Variações

Este repositório apresenta duas variantes de problemas clássicos em lógica computacional: a avaliação de expressões lógicas e uma variação do conhecido problema da satisfabilidade. A compreensão e solução desses problemas são fundamentais para o entendimento dos princípios básicos da lógica computacional.

## Problema 1: Avaliação de Expressão Lógica

### Descrição do Problema
O primeiro problema consiste na avaliação de uma expressão lógica, onde devemos determinar se a expressão é verdadeira (true) ou falsa (false) com base nos valores lógicos atribuídos às variáveis envolvidas.

### Como Executar
1. Clone este repositório para sua máquina local.
2. Compile o programa executando o comando: `make all`.
3. Execute o programa de avaliação de expressão lógica fornecendo as variáveis e a expressão lógica. A entrada deve ser pela linha de comando. Deve ser executado usando `./bin/tp1.out -a "<expressaoLogica>" <valoracao>`. Por exemplo: `./bin/tp1.out -a "0 | 1 & 2" 001`.


## Problema 2: Problema da Satisfabilidade (SAT)

### Descrição do Problema
O segundo problema é uma variação do clássico problema da satisfabilidade (SAT), que envolve determinar se existe uma atribuição de valores verdadeiro ou falso às variáveis de uma expressão lógica, de modo a torná-la verdadeira.

Quantificador Universal (∀): Representa "para todo" ou "para cada". Indica que a proposição é verdadeira para todos os valores possíveis da variável. Representado por a.

Quantificador Existencial (∃): Representa "existe" ou "existe pelo menos um". Indica que a proposição é verdadeira para pelo menos um valor possível da variável. Representado por e.

![image](https://github.com/lucascassio/Estrutura-de-dados-UFMG/assets/99884897/acfb8406-3465-48d3-9c26-a60952ac08fa)


### Como Executar
1. Clone este repositório para sua máquina local.
2. Compile o programa executando o comando: `make all`.
3. Execute o programa de avaliação de expressão lógica fornecendo as variáveis e a expressão lógica. A entrada deve ser pela linha de comando. Deve ser executado usando `./bin/tp1.out -s "<expressaoLogica>" <valoracao>`. Por exemplo: `./bin/tp1.out -a "0 | 1 & 2" 0e0`.
