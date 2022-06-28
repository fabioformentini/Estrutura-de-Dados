#include <stdio.h>
#include "arvoreb.h"
int lerOpcao();
int main() {

    ArvoreBinaria *arvoreContatos = criarArvore();
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
                break;
            case 2:
                break;
            case 3:
                printf("Nome que deseja buscar: ");
                scanf("%s", nomeBuscado);
                break;
            case 4:
                printf("Telefone que deseja buscar: ");
                break;
            case 5:
                printf("Nome do contato que deseja excluir: ");
                scanf("%s", nomeBuscado);
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
