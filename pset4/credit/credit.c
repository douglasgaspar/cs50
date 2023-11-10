#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    long numCartao = 0;

    do{
        printf("Informe o número do cartão: ");
        numCartao = get_long();
    }while(numCartao <= 0);

    int qtDigitos = 0;
    long copiaCartao = numCartao;

    while(copiaCartao > 0){
        copiaCartao /= 10;
        qtDigitos++;
    }

    printf("%d ", qtDigitos);

    //34 37 Amex
    //51, 52, 53, 54 ou 55 Master
    //Visa inicia 4

    printf("\n%d", qtdeDigitos);

}
