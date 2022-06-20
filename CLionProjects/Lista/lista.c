#include "lista.h"

//Função para inicializar a lista
Lista *criarLista() {
    Lista *pLista = (Lista *) malloc(1 * sizeof(Lista));
    pLista->inicio = NULL;
    pLista->fim = NULL;
    return pLista;
}

//Função para criar o contato e retorná-lo para ser utilizado
Contato *criarContato(char nome[LIMITENOME], char telefone[LIMITETELEFONE]) {
    Contato *pContato = (Contato *) malloc(1 * sizeof(Contato));
    pContato->ant = NULL;
    pContato->prox = NULL;
    strcpy(pContato->nome, nome);
    strcpy(pContato->telefone, telefone);
    return pContato;
}

//Função para ler o nome e telefone do contato que será criado posteriormente;
Contato *lerContato(Lista *lista) {
    char nome[LIMITENOME];
    char telefone[LIMITETELEFONE];
    printf("Insira o nome para ser inserido: ");
    scanf("%s", nome);
    printf("Insira o telefone: ");
    scanf("%s", telefone);
    return criarContato(nome, telefone);
}

//Função que verifica o tamanho da lista, recebe a lista e declara um contador para somar 1 a cada elemento percorrido da lista,
//A lista só para de ser percorrida quando o ponteiro aponta para NULL, ou seja, o ponteiro chegou no último elemento
int tamanhoDaLista(Lista *lista) {
    int tamanho = 0;
    Contato *gancho = lista->inicio;
    while (gancho != NULL) {
        tamanho++;
        gancho = gancho->prox;
    }
    return tamanho;
}

//A Função recebe a lista, o ponteiro de contato aponta para o início da lista para percorrê-la imprimindo seus valores(nome e telefone)
void imprimirLista(Lista *lista) {
    Contato *contato = lista->inicio;
    while (contato != NULL) {
        printf("\nNome: %s\n", contato->nome);
        printf("Telefone: %s\n\n", contato->telefone);
        contato = contato->prox;
    }

}

//Função para inserir o contato na lista em ordem alfabéticas
//Casos possíveis: lista vazia, inserir no final, inserir no inicio, inserir no meio;
void inserirNaListaAlfabeticamente(Lista *lista, Contato *novoContato) {
    //Verificando se a lista está vazia, caso esteja, o contato que está sendo inserido será o primeiro e o último, e o início e fim da lista
    if (tamanhoDaLista(lista) == 0) {
        lista->inicio = novoContato;
        lista->fim = novoContato;
        novoContato->prox = NULL;
        novoContato->ant = NULL;
        return;
    }
    Contato *contatoLista = lista->inicio;
    int retornoComparacao = strcmp(novoContato->nome, contatoLista->nome);

    //Se o contatoLista for diferente de NULL, ou seja, estiver apontando para alguém, e o retorno da comparação das strings for maior
    //que 0, o laço percorre a lista comparando o elemento que está sendo inserido com os elementos atuais, até sair do laço.
    while (contatoLista != NULL && retornoComparacao > 0) {
        contatoLista = contatoLista->prox;
        if (contatoLista != NULL) {
            retornoComparacao = strcmp(novoContato->nome, contatoLista->nome);
        }
    }

    //Caso o contato lista esteja apontando pra null, significa que ele é o último elemento e o novo será inserido no final;
    if (contatoLista == NULL) {
        lista->fim->prox = novoContato;
        novoContato->ant = lista->fim;
        lista->fim = novoContato;
        return;
    }

    //Caso o anterior de contatoLista seja NULL, significa que ele é o primeiro da lista, portanto o novo deve ser inserido em seu lugar;
    if (contatoLista->ant == NULL) {
        contatoLista->ant = novoContato;
        novoContato->prox = contatoLista;
        lista->inicio = novoContato;
        return;
    }

    //Caso o retorno da comparação dos nomes seja 0, significa que os nomes são iguais e um mensagem de alerta deve ser exibida;
    if (retornoComparacao == 0) {
        printf("\nO contato a ser inserido já existe, seu telefone é: %s\n", contatoLista->telefone);
        return;
    }

    //Caso o retorno da comparação seja menor que 0, indica que o meu novo contato será inserido no meio de dois elementos da lista
    //Portanto, o ponteiro próximo do anterior de contatoLista apontará para meu novo contato, o anterior do novoContato apontará
    //para o anterior da lista, o próximo de novo contato apontará para contato maior e seu anterior apontará para o novo contato
    if (retornoComparacao < 0) {
        contatoLista->ant->prox = novoContato;
        novoContato->ant = contatoLista->ant;
        novoContato->prox = contatoLista;
        contatoLista->ant = novoContato;
        return;
    }

}


//Funções que irão buscar por nome ou telefone, é passado a lista e o nome que o usuário deseja buscar, a lista é percorrida com o laço
//Até achar algum nome ou telefone que seja igual ao digitado pelo usuário;
Contato *buscarContatoPorNome(char nome[LIMITENOME], Lista *lista) {
    Contato *contatoBuscado;
    contatoBuscado = lista->inicio;
    while (contatoBuscado != NULL && strcmp(nome, contatoBuscado->nome) > 0) {
        contatoBuscado = contatoBuscado->prox;
    }
    if (contatoBuscado != NULL && strcmp(nome, contatoBuscado->nome) == 0) {
        printf("\nO telefone do contato é: %s\n\n", contatoBuscado->telefone);
        return contatoBuscado;
    }
    printf("\nNão existe um contato com o nome solicitado\n\n");
    return NULL;
}

//Função para buscar o contato por telefone, é feito um laço para percorrer a lista até achar, ou não, o elemento;
void buscarContatoPorTelefone(char telefone[LIMITETELEFONE], Lista *lista) {
    Contato *contatoBuscado;
    contatoBuscado = lista->inicio;
    while (contatoBuscado != NULL && strcmp(telefone, contatoBuscado->telefone) != 0) {
        contatoBuscado = contatoBuscado->prox;
    }
    if (contatoBuscado != NULL) {
        printf("\nO nome do contato é: %s\n\n", contatoBuscado->nome);
        return;
    }
    printf("\nNão existe um contato com o telefone solicitado\n\n");
}

//Função para excluir o contato pelo nome, é verificado se a lista é nula, se o contato buscado foi encontrado, se é o primeiro elemento,
//se é o último elemento, se está entre dois elementos
void excluirContatoPorNome(char nome[LIMITENOME], Lista *lista){
    if(tamanhoDaLista(lista) == 0){
        printf("Não há nenhum contato na lista\n");
        return;
    }
    Contato *contatoBuscado = buscarContatoPorNome(nome, lista);
    if(contatoBuscado == NULL){
        printf("O contato não foi encontrado \n");
        return;
    }
    if(contatoBuscado->prox == NULL && contatoBuscado->ant == NULL){
        lista->inicio = NULL;
        lista->fim = NULL;
        printf("O Contato de %s foi excluído com sucesso\n", contatoBuscado->nome );
        free(contatoBuscado);
        return;
    }
    if(contatoBuscado->prox == NULL){
        contatoBuscado->ant->prox = NULL;
        lista->fim = contatoBuscado->ant;
        printf("O Contato de %s foi excluído com sucesso\n", contatoBuscado->nome );
        free(contatoBuscado);
        return;
    }
    if(contatoBuscado->ant == NULL){
        contatoBuscado->prox->ant = NULL;
        lista->inicio = contatoBuscado->prox;
        printf("O Contato de %s foi excluído com sucesso\n", contatoBuscado->nome );
        free(contatoBuscado);
        return;
    }

    printf("O Contato de %s foi excluído com sucesso\n", contatoBuscado->nome );
    contatoBuscado->prox->ant = contatoBuscado ->ant;
    contatoBuscado->ant->prox = contatoBuscado ->prox;
    free(contatoBuscado);

}


