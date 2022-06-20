#include <stdio.h>

int main() {

//    int num;
//    num = 10;
//    int *pX;
//    pX = &num;
//    printf("%i\n", *pX);
//----------------------------------------------------------
//    int x = 10; //declara X que vale 10
//    int *pX; // declara um pX
//    pX = &x; // aponta o pX pro endereço de X
//
//    int y = 20; // declara y que vale 20
//    *pX = y; // o pX apontou para o endereço de memória de X que recebeu o valor de y (20)
//
//    printf("%i %i\n", x, y);
//-----------------------------------------------------------
//    int x = 10;
//    double y = 20.50;
//    char z = 'a';
//
//    int *pX = &x;
//    double *pY = &y;
//    char *pZ = &z;
//
//    double soma = *pX + *pY;
//
//    int *resultado;
//    resultado = &x;
//
//    printf("Endereço x = %i - Valor x = %i\n", pX, *pX);
//    printf("Endereço y = %i - Valor y = %.2f\n", pY, *pY);
//    printf("Endereço z = %i - Valor z = %c\n", pZ, *pZ);
//    printf("Soma de X e Y: %.2f\n", soma);
//    printf("Valor resultado: %i\n", *resultado);
//------------------------------------------------------

//    typedef struct Horario{ //definindo struct horário
//        int hora;
//        int minuto;
//        int segundo;
//
//    }Horario;
//
//    int somatorio = 100;
//    Horario agora, antes, *depois; // nomeando a struct para 'agora' e criando um ponteiro 'depois' que aponta pra essa struct
//    depois = &agora;
//
//    depois -> hora = 20;
//    depois -> minuto = 80;
//    depois -> segundo = 50;
//
//    antes.hora = somatorio + depois ->segundo;
//    antes.minuto = agora.hora - depois->minuto;
//    antes.segundo = depois->minuto + depois ->segundo;
//
//
//    printf("Horário: %i:%i:%i", antes.hora, antes.minuto, antes.segundo);

//------------------------------------------------------------------------------

//    typedef struct Horario{
//        int *pHora;
//        int *pMinuto;
//        int *pSegundo;
//    }Horario;
//
//    Horario hoje;
//
//    int hora = 100;
//    int minuto = 200;
//    int segundo = 300;
//
//    hoje.pHora = &hora;
//    hoje.pMinuto = &minuto;
//    hoje.pSegundo = &segundo;
//
//    printf("Hora: %i\n", *hoje.pHora);
//    printf("Minuto: %i\n", *hoje.pMinuto);
//    printf("Segundo: %in\n", *hoje.pSegundo);

//----------------------------------------------------------------------
// --------------------FUNCOES COM PONTEIROS DE PARAMETRO---------------
//    void testeVariavel(int x);
//    void testePonteiro(int *pX);
//    int teste = 1;
//    int *pTeste = &teste;
//
//    // testeVariavel(teste);
//    testePonteiro(pTeste);
//
//    printf("%i\n", teste);
//----------------------------------------------------------------------------

    typedef struct Lista{
        int valor;
        struct Lista *prox;
    }Lista;

    Lista membro1, membro2, membro3;

    Lista *gancho = &membro1; // Falando que o primeiro elemento estará apontando pro endereço do meu membro 1

    membro1.valor = 10;
    membro2.valor = 20;
    membro3.valor = 30;

    membro1.prox = &membro2;
    membro2.prox = &membro3;
    membro3.prox = NULL;

    while (gancho != NULL){
        printf("Valor: %i\n", gancho->valor);
        gancho = gancho -> prox;
    }

    return 0;
}

//void testeVariavel(int x){
//    ++x;
//}
//void testePonteiro(int *pX){
//    ++*pX;
//}
