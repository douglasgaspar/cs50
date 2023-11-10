#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main(void){
    long numCartao = 0;

    do{
        printf("Informe o número do cartão: ");
        numCartao = get_long("");
    }while(numCartao <= 0);

    int qtDigitos = 0;
    long copiaCartao = numCartao;
    char digitos[17];

    while(copiaCartao > 0){
        int res = copiaCartao /= 10;
        //digitos[qtDigitos] =
        printf("%d \n", res);
        qtDigitos++;
    }

    char str[20];
    sprintf(str, "%ld", numCartao);

    //34 37 Amex
    //51, 52, 53, 54 ou 55 Master
    //Visa inicia 4

    if(qtDigitos < 13 || qtDigitos > 16){
        printf("INVALID");
    }else{

    }



}
