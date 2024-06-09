#include "../headers/entrada_automatica.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


rand_int_array_t *geraArrayAleatoria(int tamanho, int valor_aleatorio_maximo) {
  srand(getpid());
  rand_int_array_t *entrada = (rand_int_array_t *)malloc(sizeof(rand_int_array_t));
  if (entrada == NULL)
    fprintf(stderr, "Erro em alocação!"), exit(1);

  // Gera numeros aleatorios entre 2 e MAX
  entrada->tamanho = tamanho;
  entrada->numeros = (int *)calloc(entrada->tamanho, sizeof(int));
  for (int i = 0; i < entrada->tamanho; i++) {
    entrada->numeros[i] = (rand() % valor_aleatorio_maximo) + 1;
  }
  return entrada;
}

void imprimeNumeros(int *vet, int tamanho) {
  printf("Numeros: ");
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n\n");
}
