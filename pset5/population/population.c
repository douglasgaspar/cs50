#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int numeroInicial = 0;
    int numeroFinal = 0;

    while(numeroFinal <= numeroInicial){
        do
        {
            numeroInicial = get_int("Número inicial de lhamas: ");
            printf("\n");
            if(numeroInicial < 9){
                printf("Número inválido, informe um valor maior ou igual a 9. \n");
            }
        }while (numeroInicial < 9);

        do
        {
            numeroFinal = get_int("Número final de lhamas: ");
            printf("\n");
            if(numeroFinal < 9 || numeroFinal < numeroInicial){
                printf("Número inválido, informe um valor maior que o inicial. \n");
            }
        }while (numeroFinal < numeroInicial);
    }

    //nascem n / 3 novas lhamas e n / 4 morrem
    int numeroAnos = 1;
    int populacao = numeroInicial;
    while(populacao <= numeroFinal){
        populacao /= 4;
        populacao
    }







     // TODO: Calcule o número de anos até o limite

     // TODO: Imprima o número de anos

}
