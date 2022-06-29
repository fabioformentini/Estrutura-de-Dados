#include "arvoreb.h"

//! Função para inicializar a árvore;
ArvoreBinaria *criarArvore() {
    ArvoreBinaria *pArvore = (ArvoreBinaria *) malloc(1 * (sizeof(ArvoreBinaria)));
    pArvore->raiz = NULL;
    return pArvore;
}

//! Função para criar o contato que será inserido na árvore
Contato *criarContato(char nome[LIMITENOME], char telefone[LIMITETELEFONE]) {
    Contato *pContato = (Contato *) malloc(1 * sizeof(Contato));
    pContato->direita = NULL;
    pContato->esquerda = NULL;
    strcpy(pContato->nome, nome);
    strcpy(pContato->telefone, telefone);
    return pContato;
}

//! Função para ler o contato e criá-lo posteriormente
Contato *lerContato() {
    char nome[LIMITENOME];
    char telefone[LIMITETELEFONE];
    printf("Insira o nome para ser inserido: ");
    scanf("%s", nome);
    printf("Insira o telefone: ");
    scanf("%s", telefone);
    return criarContato(nome, telefone);
}

void inserirNaArvore(ArvoreBinaria *arvoreBinaria, Contato *novoContato) {
    //! Verificando se a raiz é nula. Caso for, ela receberá o novo contato
    if (arvoreBinaria->raiz == NULL) {
        arvoreBinaria->raiz = novoContato;
        novoContato->esquerda = NULL;
        novoContato->direita = NULL;
        return;
    }
    //! Caso não for nula...
    int retornoComparacao = strcmp(novoContato->nome, arvoreBinaria->raiz->nome);
    //! O contato que será inserido é menor que o que está na raiz, portanto, deve ser inserido na esquerda
    if (retornoComparacao < 0) {
        inserirNaEsquerda(arvoreBinaria->raiz, novoContato);
        return;
    }
    //! O contato que será inserido é maior que o que está na raiz, portanto, deve ser inserido na direita
    if (retornoComparacao > 0) {
        inserirNaDireita(arvoreBinaria->raiz, novoContato);
        return;
    }
    //! O contato que será inserido é igual ao contato que está na raiz
    if (retornoComparacao == 0) {
        printf("\nO contato já existe!\n");
        return;
    }

}

void inserirNaEsquerda(Contato *contato, Contato *novoContato) {
    //! verificando se o contato apontado à esquerda é nulo, caso for, receberá o contato que está sendo inserido
    if (contato->esquerda == NULL) {
        novoContato->esquerda = NULL;
        novoContato->direita = NULL;
        contato->esquerda = novoContato;
        return;
    }
    int retornoComparacao = strcmp(novoContato->nome, contato->esquerda->nome);
    //! Se o contato que eu quero inserir for alfabeticamente inferior ao contato da esquerda
    if (retornoComparacao < 0) {
        inserirNaEsquerda(contato->esquerda, novoContato);
        return;
    }
    //! Se o contato que eu quero inserir for alfabeticamente superior ao contato da esquerda
    if (retornoComparacao > 0) {
        inserirNaDireita(contato->esquerda, novoContato);
        return;
    }
    //! Se o nome que eu quero inserir for igual ao buscado:
    if (retornoComparacao == 0) {
        printf("\nO contato já existe!\n");
        return;
    }


}

void inserirNaDireita(Contato *contato, Contato *novoContato) {
    //! verificando se o contato apontado à direita é nulo, caso for, receberá o contato que está sendo inserido
    if (contato->direita == NULL) {
        novoContato->esquerda = NULL;
        novoContato->direita = NULL;
        contato->direita = novoContato;
        return;
    }

    int retornoComparacao = strcmp(novoContato->nome, contato->direita->nome);
    //! Se o contato que eu quero inserir for alfabeticamente superior ao contato da direita
    if (retornoComparacao > 0) {
        inserirNaDireita(contato->direita, novoContato);
        return;
    }
    //! Se o contato que eu quero inserir for alfabeticamente inferior ao contato da direita
    if (retornoComparacao < 0) {
        inserirNaEsquerda(contato->direita, novoContato);
        return;
    }
    if (retornoComparacao == 0) {
        printf("\nO contato já existe!\n");
        return;
    }
}

//! Função para imprimir a árvore percorrendo seus elementos a partir da raiz que é passada
void imprimirArvore(Contato *raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esquerda);
        printf("\nNome: %s\n", raiz->nome);
        printf("Telefone: %s\n", raiz->telefone);
        imprimirArvore(raiz->direita);
    }

}

void buscarContatoPorNome(Contato *raiz, char nome[LIMITENOME]) {
    //! Caso o nome buscado não seja encontrado
    if (raiz == NULL) {
        printf("\nO Contato não foi encontrado!\n");
        return;
    }
    //! Nome encontrado:
    if (raiz->nome == nome) {
        printf("\nO Contato buscado foi encontrado, seu telefone é: %s\n", raiz->telefone);
        return;
    }
    //! Comparando o nome buscado com o que está sendo verificado
    int retornoComparacao = strcmp(nome, raiz->nome);
    //! Caso sejam iguais:
    if (retornoComparacao == 0) {
        printf("\nO contato buscado foi encontrado, seu telefone é: %s\n", raiz->telefone);
        return;
    }
    //! Caso o contato buscado seja alfabeticamente inferior ao que está sendo verificado:
    if (retornoComparacao < 0) {
        return buscarContatoPorNome(raiz->esquerda, nome);
    }
    //! Caso o contato buscado seja alfabeticamente superior ao que está sendo verificado:
    if (retornoComparacao > 0) {
        return buscarContatoPorNome(raiz->direita, nome);
    }

}

void buscarContatoPorTelefone(Contato *raiz, char telefone[LIMITETELEFONE]){
    if (raiz == NULL) {
        printf("\nO Contato não foi encontrado!\n");
        return;
    }
    if (raiz->telefone == telefone) {
        printf("O telefone buscado foi encontrado, seu portador é: %s", raiz->nome);
        return;
    }

    int retornoComparacao = strcmp(telefone, raiz->telefone);

    if (retornoComparacao == 0) {
        printf("O telefone buscado foi encontrado, seu portador é: %s", raiz->nome);
        return;
    }
    if (retornoComparacao < 0) {
        return buscarContatoPorTelefone(raiz->esquerda, telefone);
    }
    if (retornoComparacao > 0) {
        return buscarContatoPorTelefone(raiz->direita, telefone);
    }
}

Contato* removerDaArvore(Contato *raiz, char nome[LIMITENOME]){
    //! Caso a raiz seja nula:
    if (raiz == NULL){
        printf("O contato não foi encontrado");
        return NULL;
    }
    //! Caso não seja:
    int retornoComparacao = strcmp(nome, raiz->nome);
    //! Caso o contato que eu estou buscando seja igual ao contato percorrido:
    if (retornoComparacao == 0){
        removerContatoEncontrado(raiz, nome);
    }
    //! Caso o contato que eu estou buscando seja alfabeticamente menor que o contato percorrido:
    if (retornoComparacao < 0){
        raiz->esquerda = removerDaArvore(raiz->esquerda, nome);
        return raiz;
    }
    //! Caso o contato que eu estou buscando seja alfabeticamente maior que o contato percorrido:
    if (retornoComparacao > 0){
        raiz->direita = removerDaArvore(raiz->direita, nome);
        return raiz;
    }

}

Contato* removerContatoEncontrado(Contato *raiz, char nome[LIMITENOME]){
    //! caso o elemento seja um nó folha, ou seja, não possui elementos à esquerda e à direita
    if(raiz->esquerda == NULL && raiz->direita == NULL){
        free(raiz);
        return NULL;
    }
    Contato *salvarFilho;
    //! Caso o elemento possua filho à esquerda e à direita
    if(raiz->direita != NULL && raiz->esquerda != NULL){
        Contato *aux = raiz->esquerda;
        while (aux->direita != NULL) {
            aux = aux->direita;
        }
        Contato *inversao = criarContato(raiz->nome, raiz->telefone);
        strcpy(raiz->nome, aux->nome);
        strcpy(raiz->telefone, aux->telefone);
        strcpy(aux->nome, inversao->nome);
        strcpy(aux->telefone, inversao->telefone);

        raiz->esquerda = removerDaArvore(raiz->esquerda, inversao->nome);
        return raiz;
    }
    //! filho à esquerda
    if(raiz->esquerda != NULL){
        salvarFilho = raiz->esquerda;
        return salvarFilho;
    }
    //! filho à direita:
    if(raiz->direita != NULL){
        salvarFilho = raiz->direita;
        return salvarFilho;
    }
}
