#ifndef ARVORE_BINARIA_ARVOREB_H
#define ARVORE_BINARIA_ARVOREB_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LIMITENOME 50
#define LIMITETELEFONE 15

typedef struct contato{
    char nome[LIMITENOME];
    char telefone[LIMITETELEFONE];
    struct contato *esquerda, *direita;
}Contato;

typedef struct{
    Contato *raiz;
}ArvoreBinaria;

ArvoreBinaria *criarArvore();



















#endif //ARVORE_BINARIA_ARVOREB_H
