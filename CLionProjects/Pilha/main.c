#include <stdio.h>
#include "pilha.h"
int main() {

    int numeroLido = lerNumeroDecimal();
    int resto;
    Pilha pilha;

    while (numeroLido > 0){
        inicializarPilha(&pilha);

        while(numeroLido > 0){
            resto = numeroLido % 2;
            empilhar(&pilha, resto);
            numeroLido = numeroLido/2;
        }
        printf("Número convertido para binário: ");
        imprimirPilha(&pilha);
        numeroLido = lerNumeroDecimal();
    }

    return 0;
}
