#include<cs50.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    long numCartao = 0;

    do{
        printf("Informe o número do cartão: ");
        numCartao = get_long("");
    }while(numCartao <= 0);

    int qtDigitos = 0;
    long copiaCartao = numCartao;

    while(copiaCartao > 0){
        int res = copiaCartao /= 10;
        qtDigitos++;
    }

    //34 37 Amex
    //51, 52, 53, 54 ou 55 Master
    //Visa inicia 4

    if(qtDigitos < 13 || qtDigitos > 16){
        printf("\nINVALID\n");
    }else{
        char digitos[17];
        sprintf(digitos, "%ld", numCartao);
        int inicioPenultimo = 0;
        int pulaDois = 0;

        for(int i=strlen(digitos) ; i>=0 ; i--){
            if(digitos[i] == '\0'){
                inicioPenultimo = i;
            }else{
                pulaDois++;
                if(pulaDois % 2 == 0){
                    int dobro = atoi(digitos[i]);
                    printf(" %d ", (dobro*2));
                }

            }
        }
    }



}
