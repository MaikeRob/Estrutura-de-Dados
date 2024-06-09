#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers/sorts.h"
#include "headers/entrada_automatica.h"


int main(void) {

  rand_int_array_t *entrada = geraArrayAleatoria(100, 50);

  imprimeNumeros(entrada->numeros, entrada->tamanho);
  selectionSort(entrada->numeros, entrada->tamanho);
  imprimeNumeros(entrada->numeros, entrada->tamanho);

  return 0;
}