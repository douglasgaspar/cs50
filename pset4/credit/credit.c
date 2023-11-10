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

    while(copiaCartao > 0){
        int res = copiaCartao /= 10;
        qtDigitos++;
    }

    //34 37 Amex
    //51, 52, 53, 54 ou 55 Master
    //Visa inicia 4

    if(qtDigitos < 13 || qtDigitos > 16){
        printf("INVALID");
    }else{
        char digitos[17];
        sprintf(digitos, "%ld", numCartao);

        for(int i=0 ; i<20 ; i++){
            
            printf("%c ", digitos[i]);
        }
    }



}
