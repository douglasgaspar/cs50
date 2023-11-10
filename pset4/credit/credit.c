#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void){
    char[] numCartao = get_long("Informe o número do cartão: ");
    int qtdeDigitos = strlen(numCartao);

    printf("%d", qtdeDigitos);

}
