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
Contato *criarContato(char nome[LIMITENOME], char telefone[LIMITETELEFONE]);
Contato *lerContato();
void inserirNaEsquerda(Contato *contato, Contato *novoContato);
void inserirNaDireita(Contato *contato, Contato *novoContato );
void inserirNaArvore(ArvoreBinaria *arvoreBinaria, Contato *novoContato);
void imprimirArvore(Contato *raiz);
void buscarContatoPorNome(Contato *raiz, char nome[LIMITENOME]);
void buscarContatoPorTelefone(Contato *raiz, char telefone[LIMITETELEFONE]);
Contato* removerDaArvore(Contato *raiz, char nome[LIMITENOME]);
Contato* removerContatoEncontrado(Contato *raiz, char nome[LIMITENOME]);


#endif //ARVORE_BINARIA_ARVOREB_H
