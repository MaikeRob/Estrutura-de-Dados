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

É um dos mais eficientes, funciona dividindo o problema em problemas menores e os resolvendo independentemente, e combinando tudo para conseguir a solução final.

Tem três passos:

**Passo 1: Escolha do Pivô**

O primeiro passo do Quicksort é escolher um elemento como pivô. O pivô é uma referência usada para dividir a lista em duas partes. Idealmente, o pivô é escolhido de modo que divida a lista em duas partes aproximadamente iguais. Uma escolha comum é selecionar o primeiro elemento da lista.

**Passo 2: Particionamento**

Após a escolha do pivô, a lista é reorganizada de modo que todos os elementos menores que o pivô estejam à sua esquerda e todos os elementos maiores estejam à sua direita. Este processo é chamado de particionamento.

O algoritmo utiliza dois índices, um para percorrer a lista da esquerda para a direita e outro da direita para a esquerda. Eles se movem em direção um ao outro, trocando elementos desordenados até que se cruzem. Quando os índices se encontram, o pivô é colocado em sua posição final na lista, com todos os elementos menores à sua esquerda e todos os elementos maiores à sua direita.

**Passo 3: Recursão**

Após o particionamento, a lista é dividida em duas partes, com o pivô em sua posição final. O Quicksort é então aplicado recursivamente às sublistas à esquerda e à direita do pivô. Isso significa que o processo de escolha do pivô e particionamento é repetido em cada metade da lista até que toda a lista esteja ordenada.

![Alt Text](https://d2m498l008ebpa.cloudfront.net/2016/12/quicksort.gif)

#### Complexidade:
Melhor caso: O(n log n)
Pior caso: O(n²)

*Não estável*

Tem o melhor desempenho da média, eficiente em listas grandes e aleatórias


```c
void trocar(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionamento(int vetor[], int inicio, int fim){
    int pivo = vetor[fim];
    int i = (inicio - 1);
    for (int j = inicio; j <= fim - 1; j++){
        if (vetor[j] < pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);
    return (i + 1);
} 

void quickSort(int vetor[], int inicio, int fim){
    if(inicio < fim){
    int pivo = particionamento(vetor, inicio, fim);
    quickSort(vetor, inicio, pivo - 1);
    quickSort(vetor, pivo + 1, fim);
    }
}
```

## Merge Sort

O algoritmo Merge Sort é um algoritmo de ordenação eficiente e divide para conquistar. Ele funciona dividindo repetidamente a lista não classificada pela metade, até que cada sublista contenha apenas um elemento. Em seguida, ele combina essas sub-listas de forma ordenada, até que toda a lista esteja ordenada.

![Alt Text](https://d2m498l008ebpa.cloudfront.net/2016/12/merge-sort.gif)

#### Complexidade:

O(n log n) para todos os casos

*Estável*

Eficiente em quase todos os casos
Custo de memoria alto


```c
void merge(int arr[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1; // Tamanho do primeiro subarray
    int n2 = fim - meio;        // Tamanho do segundo subarray

    // Cria subarrays temporários
    int L[n1], R[n2];

    // Copia os dados para os subarrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    // Mescla os subarrays temporários de volta em arr[inicio..fim]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = inicio; // Índice inicial do array mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia o que sobrou em L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia o que sobrou em R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        merge(arr, inicio, meio, fim);
    }
}

```

## Bubble Sort

O algoritmo Bubble Sort é um dos algoritmos de ordenação mais simples. Ele funciona comparando repetidamente os elementos adjacentes e trocando-os se estiverem na ordem errada. Esse processo é repetido várias vezes até que a lista esteja ordenada

![Alt Text]()

#### Complexidade:

Melhor Caso: O(n)
Pior Caso:  O(n²)

*Estável*

Simples
Ruim para listas grandes


```c

```
