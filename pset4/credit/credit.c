#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void){
    char numCartao[16];
    printf("Informe o número do cartão: ");
    scanf("%s", numCartao);

    int qtdeDigitos = strlen(numCartao);
    while(qtdeDigitos < 13 || qtdeDigitos > 16){
        printf("Valor inválido, informe novamente: ");
        scanf("%s", numCartao);
        qtdeDigitos = strlen(numCartao);
    }

    //34 37 Amex
    //51, 52, 53, 54 ou 55 Master
    //Visa inicia 4


    printf("%d", qtdeDigitos);

}
