#ifndef PILHA_PILHA_H
#define PILHA_PILHA_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//! Estrutura dos elementos que serão empilhados
typedef struct elemento{
    int num;
    struct elemento *proximo;
}Elemento;
//! Estrutura da pilha
typedef struct pilha{
    Elemento *topo;
}Pilha;
//! Assinatura dos métodos utilizados
void inicializarPilha(Pilha *pilha);
int lerNumeroDecimal();
void empilhar(Pilha *pilha, int numero);
int desempilhar(Pilha *pilha);
void imprimirPilha(Pilha *pilha);
void somenteImprimir(Pilha *pilha);

#endif //PILHA_PILHA_H
