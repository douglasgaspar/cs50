#include <cs50.h>
#include <stdio.h>

int main(void){
    float troco = get_float("Qual o valor do troco?");
    while(troco <= 0){
        printf("Valor do troco inválido. Digite novamente.\n");
        troco = get_float("Qual o valor do troco?");
    }

    printf("%f", troco);
}
