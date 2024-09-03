# Análise Experimental de Algoritmos de Ordenação 📊

Este repositório contém a implementação de diversos métodos de ordenação, como parte de um projeto de análise experimental da disciplina de **Estruturas de Dados**. O objetivo é comparar os métodos de ordenação vistos em sala de aula tanto em termos de eficiência prática quanto em sua complexidade teórica.

## Métodos de Ordenação Implementados

- **Bubble Sort** (Método da bolha)
- **Insertion Sort** (Método da inserção)
- **Selection Sort** (Método da seleção)
- **Merge Sort**
- **Quick Sort**
- **Shell Sort**
- **Counting Sort**
- **Bucket Sort**
- **Radix Sort**

## Objetivos do Projeto

O objetivo principal deste projeto é:

1. **Implementar e comparar experimentalmente** os métodos de ordenação listados.
2. **Analisar a eficiência prática** de cada método em diferentes cenários e contrastar os resultados com a análise de complexidade teórica.

## Cargas de Trabalho

As cargas de trabalho foram projetadas para exercitar as características dos algoritmos sob diferentes dimensões:

- **Tamanho do vetor**: Variando a quantidade de elementos no vetor a ser ordenado.
- **Tamanho do item**: Considerando o tamanho dos itens em bytes.
- **Configuração inicial do vetor**: Testes com vetores ordenados, inversamente ordenados e desordenados, bem como diferentes populações de chaves (p.ex., razão entre o número de chaves e o tamanho do vetor, popularidade das chaves).

Outras dimensões relevantes também podem ser incluídas, como o tamanho das chaves.

## Análise Experimental

Para as cargas de trabalho propostas, realizamos as seguintes análises:

1. **Análise de Tempo de Execução**: Comparando o tempo de execução dos algoritmos em diferentes cenários.
2. **Análise de Uso de Memória**: Avaliando a quantidade de memória utilizada por cada método em diferentes configurações.

Os resultados das análises são apresentados em gráficos que ilustram a eficiência prática dos algoritmos e permitem a comparação direta com as previsões teóricas.

## Como Executar

1. **Compilar**: Compile o código utilizando um compilador C++.
2. **Executar**: Execute o programa passando o vetor a ser ordenado e as configurações desejadas como entrada.

### Exemplo de Uso

```bash
./ordenacao --metodo quicksort --tamanho 1000 --config inverso
