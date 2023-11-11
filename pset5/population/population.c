#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int numeroInicial = 0;
    int numeroFinal = 0;
    do
    {
        numeroInicial = get_int("Número inicial de lhamas: ");
        printf("\n");
    }while (numeroInicial < 9);

    do
    {
        numeroFinal = get_int("Número final de lhamas: ");
        printf("\n");
    }
    numeroInicial = get_int("Número final de lhamas: ");
    while (numeroFinal < 9);
      // TODO: Solicite o valor inicial ao usuário

     // TODO: Solicite o valor final ao usuário

     // TODO: Calcule o número de anos até o limite

     // TODO: Imprima o número de anos

}
