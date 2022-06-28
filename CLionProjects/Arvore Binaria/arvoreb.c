#include "arvoreb.h"

ArvoreBinaria *criarArvore(){
    ArvoreBinaria *pArvore = (ArvoreBinaria *) malloc(1*(sizeof (ArvoreBinaria)));
    pArvore->raiz = NULL;
    return pArvore;
}

Contato *criarContato(char nome[LIMITENOME], char telefone[LIMITETELEFONE]){
    Contato *pContato = (Contato *) malloc(1 * sizeof(Contato));
    pContato->direita = NULL;
    pContato->esquerda = NULL;
    strcpy(pContato->nome, nome);
    strcpy(pContato->telefone, telefone);
    return pContato;
}

Contato *lerContato(ArvoreBinaria *arvoreBinaria) {
    char nome[LIMITENOME];
    char telefone[LIMITETELEFONE];
    printf("Insira o nome para ser inserido: ");
    scanf("%s", nome);
    printf("Insira o telefone: ");
    scanf("%s", telefone);
    return criarContato(nome, telefone);
}

int compararNomes(char *novoNome, char *nomeExistente){
    int resultado = strcmp(nomeExistente, novoNome);
    return resultado;
}

void inserirNaEsquerda(Contato *contato, Contato *novoContato ){
    if(contato->esquerda == NULL){
        novoContato->esquerda = NULL;
        novoContato->direita = NULL;
        contato->esquerda = novoContato;
        return;
    }
}

void inserirNaDireita(Contato *contato, Contato *novoContato ){

}

void inserirNaArvore(ArvoreBinaria *arvoreBinaria, Contato *novoContato){
    //! Verificando se a raiz é nula. Caso for, ela receberá o novo contato
    if(arvoreBinaria->raiz == NULL){
        arvoreBinaria->raiz = novoContato;
        novoContato->esquerda = NULL;
        novoContato->direita = NULL;
        return;
    }
    //! Caso não for nula...
    int retornoComparacao = strcmp(novoContato->nome, arvoreBinaria->raiz->nome);
    //? se retornoComparacao < 0 = nome do novo contato  < nome do contato que está na raiz
    //? se retornoComparacao > 0 = nome do novo contato > nome do contato que está na raiz
    //? se retornoComparacao = 0 = nome do novo contato é igual ao nome que está na raiz
    //! O contato que será inserido é menor que o que está na raiz, portanto, deve ser inserido na esquerda
    if (retornoComparacao < 0){
        inserirNaEsquerda(arvoreBinaria->raiz, novoContato);
        return;
    }
    //! O contato que será inserido é maior que o que está na raiz, portanto, deve ser inserido na direita
    if (retornoComparacao > 0){
        inserirNaDireita(arvoreBinaria->raiz, novoContato);
        return;
    }
    //! O contato que será inserido é igual ao contato que está na raiz
    if (retornoComparacao == 0){

    }


}

