#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){
    float troco = get_float("Qual o valor do troco?");
    while(troco <= 0){
        printf("Valor do troco inválido. Digite novamente.\n");
        troco = get_float("Qual o valor do troco?");
    }

    int centavos = round(troco * 100);
    int qtdeMoedas = 0;

    while(centavos >= 25) {
        centavos -= 25;
        qtdeMoedas++;
    }

    while(centavos >= 10) {
        centavos -= 10;
        qtdeMoedas++;
    }

    while(centavos >= 5) {
        centavos -= 5;
        qtdeMoedas++;
    }

     while(centavos >= 1) {
        centavos -= 1;
        qtdeMoedas++;
    }

    printf("%d\n", qtdeMoedas);
}
