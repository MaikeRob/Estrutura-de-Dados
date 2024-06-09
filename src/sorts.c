

void insertionSort(int vetor[], int tamanho) {
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