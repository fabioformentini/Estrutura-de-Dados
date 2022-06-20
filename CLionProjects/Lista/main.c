#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int lerOpcao();

int main() {

    Lista *listaContatos = criarLista();
    int opcao = -1;
    char *nomeBuscado = (char*)malloc(LIMITENOME * sizeof(char));
    char *telefoneBuscado = (char*) malloc(LIMITETELEFONE * sizeof(char));


    while (opcao != 0) {
        opcao = lerOpcao();
        switch (opcao) {
            case 0:
                printf("Programa finalizado");
                break;
            case 1:
                inserirNaListaAlfabeticamente(listaContatos, lerContato());
                break;
            case 2:
                imprimirLista(listaContatos);
                break;
            case 3:
                printf("Nome que deseja buscar: ");
                scanf("%s", nomeBuscado);
                buscarContatoPorNome(nomeBuscado, listaContatos);
                break;
            case 4:
                printf("Telefone que deseja buscar: ");
                scanf("%s", telefoneBuscado);
                buscarContatoPorTelefone(telefoneBuscado, listaContatos);
                break;
            case 5:
                printf("Nome do contato que deseja excluir: ");
                scanf("%s", nomeBuscado);
                excluirContatoPorNome(nomeBuscado, listaContatos);
                break;
        }
    }


    return 0;
}

int lerOpcao() {
    int opcao = 0;
    printf("\nSair do programa - 0 \n");
    printf("Inserir Contato - 1 \n");
    printf("Imprimir Lista - 2 \n");
    printf("Buscar por nome - 3 \n");
    printf("Buscar por telefone - 4 \n");
    printf("Excluir por nome - 5 \n");
    printf("\nOpção: ");


    scanf("%d", &opcao);
    return opcao;
};