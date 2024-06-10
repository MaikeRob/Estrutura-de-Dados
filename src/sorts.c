

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

void bubbleSort(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam - i - 1; j++){
            if(vet[j] > vet[j+1]){
            trocar(&vet[j], &vet[j + 1]);
            }
        }
    }
}