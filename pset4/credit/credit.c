/*
Em um arquivo chamado credit.c em um diretório ~/pset1/credit/, escreva um programa que solicite ao usuário um número de cartão de crédito e, em seguida, informe (via printf ) se é um número de cartão American Express, MasterCard ou Visa válido , de acordo com as definições de formato de cada um neste documento. Para que possamos automatizar alguns testes do seu código, pedimos que a última linha de saída do seu programa seja AMEX\n ou MASTERCARD\n ou VISA\n ou INVALID\n , nada mais, nada menos. Para simplificar, você pode assumir que o input do usuário será inteiramente numérica (ou seja, sem hífens, como pode ser impresso em um cartão real). Mas não presuma que o input do usuário caberá em um int ! Melhor usar get_long da biblioteca do CS50 para obter o input dos usuários.
De acordo com o algoritmo de Luhn, você pode determinar se um número de cartão de crédito é (sintaticamente) válido da seguinte maneira:

Multiplique cada segundo digito por 2, começando com o penúltimo dígito do número e, em seguida, some os dígitos desses produtos.
Adicione essa soma à soma dos dígitos que não foram multiplicados por 2.
Se o último dígito do total for 0 (ou, mais formalmente, se o módulo total 10 for congruente com 0), o número é válido!
*/

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
        //printf("Checksum: %d \n", somaDigitosDoisDois);
        if(somaDigitosDoisDois % 10 == 0){
            //34 37 Amex
            //51, 52, 53, 54 ou 55 Master
            //Visa inicia 4
            if(digitos[0] == '3'){
                if(digitos[1] == '4' || digitos[1] == '7'){
                    printf("AMEX\n");
                }else{
                    printf("INVALID\n");
                }
            }
            if(digitos[0] == '4'){
                printf("VISA\n");
            }
            if(digitos[0] == '5'){
                if(digitos[1] == '1' || digitos[1] == '2' || digitos[1] == '3' || digitos[1] == '4' || digitos[1] == '5'){
                    printf("MASTERCARD\n");
                }else{
                    printf("INVALID\n");
                }
            }
        }else{
            printf("INVALID\n");
        }
    }
}
