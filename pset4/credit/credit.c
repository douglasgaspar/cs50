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
        sprintf(digitos, "%ld", numCartao); //Converte long para char[]
        int pulaDois = 0;
        int somaMaiorDez = 0;
        int somaDigitosDoisDois = 0;

        for(int i=strlen(digitos) ; i>=0 ; i--){
            if(digitos[i] == '\0'){

            }else{ //Recueprar somente dígitos numéricos válidos
                pulaDois++;
                if(pulaDois % 2 == 0){
                    int dobro = digitos[i] - '0';
                    dobro = dobro * 2;

                    if(dobro > 9){
                        int resto = dobro % 10;
                        int quociente = dobro / 10;

                        somaDigitosDoisDois += (resto + quociente);
                        //printf("Resto: %d ", resto);
                        //printf("Quociente: %d ", quociente);
                    }else{
                        somaDigitosDoisDois += dobro;
                    }
                    //printf(" %d ", dobro);
                }else{
                    //Soma os demais números do cartão
                    int num = digitos[i] - '0';
                    somaDigitosDoisDois += num;
                }
            }
        }
        printf("Checksum: %d \n", somaDigitosDoisDois);
        if(somaDigitosDoisDois)
    }



}
