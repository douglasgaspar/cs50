#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){
    long numCartao = get_long("Informe o número do cartão: ");
    while(numCartao <= 0){
        printf("Valor do troco inválido. Digite novamente.\n");
        troco = get_float("Qual o valor do troco?");
    }
}
