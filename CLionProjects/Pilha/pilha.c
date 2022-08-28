#include <stdio.h>
#include "pilha.h"

//! Função para inicializar a pilha
void inicializarPilha(Pilha *pilha){
    pilha->topo = NULL;
}
//! Função para ler o número que será convertido
int lerNumeroDecimal(){
    int numero;
    printf("\nInsira o número decimal para ser convertido: ");
    scanf("%d", &numero);
    return numero;
}
//! função para empilhar elementos na pilha
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
//! Função para desempilhar os elementos na pilha;
int desempilhar(Pilha *pilha){
    Elemento *remov_elemento;
    if(pilha == NULL)
        return -1;
    remov_elemento = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(remov_elemento);
    return 0;
}
//! Função para imprimir os elementos da pilha
void imprimirPilha(Pilha *pilha){
    Elemento *topo;
    topo = pilha->topo;
    while (topo != NULL){
        printf("%d", topo->num);
        topo = topo->proximo;
        desempilhar(pilha);
    }
}



void somenteImprimir(Pilha *pilha){
    Elemento *topo;
    topo = pilha->topo;
    while (topo != NULL){
        printf("\n%d", topo->num);
        topo = topo->proximo;
    }
}