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
            if(numeroInicial < 9){
                printf("Número inválido, informe um valor maior ou igual a 9. \n");
            }
        }while (numeroInicial < 9);

        do
        {
            numeroFinal = get_int("Número final de lhamas: ");
            if(numeroFinal < 9 || numeroFinal < numeroInicial){
                printf("Número inválido, informe um valor maior que o inicial. \n");
            }
        }while (numeroFinal < numeroInicial);
    }

    if(numeroFinal == numeroInicial){
        printf("Years: 0");
    }else{
        //nascem n / 3 novas lhamas e n / 4 morrem
        int numeroAnos = 0;
        int populacao = numeroInicial;
        while(populacao <= numeroFinal){
            int nascem = 0;
            int morrem = 0;
            nascem = (int) populacao/3;
            //printf("\nNascem: %d", nascem);
            morrem = (int) populacao/4;
            //printf("\nMorrem: %d", morrem);

            populacao = populacao + nascem - morrem;
            //printf("\nPopulacao: %d", populacao);
            numeroAnos++;
        }

        printf("Years: %i", numeroAnos);
    }
}
