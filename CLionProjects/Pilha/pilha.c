#include <stdio.h>
#include "pilha.h"

void inicializarPilha(Pilha *pilha){
    pilha->topo = NULL;
}

int lerNumeroDecimal(){
    int numero;
    printf("\nInsira o número decimal para ser convertido: ");
    scanf("%d", &numero);
    return numero;
}

void empilhar(Pilha *pilha, int numero){
    Elemento *novoEemento = malloc(sizeof (Elemento));

    if(novoEemento){
        novoEemento->num = numero;
        novoEemento->proximo = pilha->topo;
        pilha->topo = novoEemento;
        return;
    }
    printf("Erro ao alocar memória!");

}

int desempilhar(Pilha *pilha){
    Elemento *topo;
    int retorno;

    if(pilha->topo != NULL){
        topo = pilha->topo;
        pilha->topo = topo->proximo;
        retorno = topo->num;
        free(topo);
        return retorno;
    }
    printf("Erro: Pilha vazia");
}

void imprimirPilha(Pilha *pilha){
    Elemento *topo;
    topo = pilha->topo;
    while (topo != NULL){
        printf("%d", topo->num);
        topo = topo->proximo;
    }

}