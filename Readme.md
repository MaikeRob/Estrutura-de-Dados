# Algoritimos de Busca

## Inserction Sort

Funciona construindo uma sublista de itens ordenados um elemento de cada vez, movendo cada novo elemento para sua posição correta entre os elementos já ordenados.

![Alt Text](https://d2m498l008ebpa.cloudfront.net/2016/12/insertion-sort-animation-2-1.gif)

#### Complexidade:
Melhor caso: O(n)
Pior caso: O(n²)

*Estável*

Util em listas pequenas ou quase ordenadas.
Não eficiente em listas muito grandes.


```c
  void insertionSort(int *vetor, int tamanho) {
    int i, j, aux;
    for (i = 1; i < tamanho; i++) {
        aux = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > aux) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
    }
}
```



## Selection Sort

Funciona selecionando repetidamente o menor elemento da lista não ordenada e o movendo para o começo da lista 

![Alt Text](https://d2m498l008ebpa.cloudfront.net/2016/12/selection-sort-animation-2-1.gif)

#### Complexidade:

O(n²) em qualquer caso

*Não estável*

Util em listas pequenas ou quando se tem pouca memoria.
Não eficiente em listas grandes por ter complexidade n²



```c
void selectionSort(int vetor[], int tamanho) {
  int i, j, menor_indice, temp;
  for (i = 0; i < tamanho-1; i++){
    // Assume que o menor elemento está na posição i
    menor_indice = i; 
    // Percorre a lista a partir da posição i+1 para encontrar o menor elemento
    for(j = i+1; j < tamanho; j++){
      if(vetor[j] < vetor[menor_indice]){ 
      menor_indice = j;
      }
    }
    // Troca o menor elemento encontrado com o elemento na posição i
    temp = vetor[i];
    vetor[i] = vetor[menor_indice];
    vetor[menor_indice] = temp;
  }
}
```

## Quick Sort



![Alt Text](https://d2m498l008ebpa.cloudfront.net/2016/12/quicksort.gif)

#### Complexidade:
Melhor caso: O(n log n)
Pior caso: O(n²)

*Não estável*

Tem o melhor desempenho da média, eficiente em listas grandes e aleatórias


```c

```
