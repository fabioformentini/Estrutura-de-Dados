#ifndef LISTA_LISTA_H
#define LISTA_LISTA_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LIMITENOME 50
#define LIMITETELEFONE 15

typedef struct Contato{
    char nome[LIMITENOME];
    char telefone[LIMITETELEFONE];
    struct Contato *ant, *prox;
}Contato;

typedef struct Lista{
    Contato *inicio, *fim;
}Lista;

void inserirNaListaAlfabeticamente(Lista *lista, Contato *novoContato);
int tamanhoDaLista(Lista *lista);
Lista *criarLista();
Contato *criarContato(char nome[LIMITENOME], char telefone[LIMITETELEFONE]);
Contato *lerContato();
void imprimirLista(Lista *lista);
Contato *buscarContatoPorNome(char nome[LIMITENOME], Lista *lista);
void buscarContatoPorTelefone(char telefone[LIMITETELEFONE], Lista *lista);
void excluirContatoPorNome(char nome[LIMITENOME], Lista *lista);

#endif //LISTA_LISTA_H
