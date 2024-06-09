#ifndef ENTRADA_AUTOMATICA_H
#define ENTRADA_AUTOMATICA_H

typedef struct {
  int tamanho;
  int *numeros;
} rand_int_array_t;

rand_int_array_t *geraArrayAleatoria(int tamanho, int valor_aleatorio_maximo);
void imprimeNumeros(int *vet, int tamanho);



#endif