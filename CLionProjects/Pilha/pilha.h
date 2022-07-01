#ifndef PILHA_PILHA_H
#define PILHA_PILHA_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct elemento{
    int num;
    struct elemento *proximo;
}Elemento;

typedef struct pilha{
    Elemento *topo;
}Pilha;

void inicializarPilha(Pilha *pilha);
int lerNumeroDecimal();
void empilhar(Pilha *pilha, int numero);
int desempilhar(Pilha *pilha);
void imprimirPilha(Pilha *pilha);





#endif //PILHA_PILHA_H
