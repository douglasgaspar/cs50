#include <cs50.h>
#include <stdio.h>

int main(void){
    int linhas;
    int imprime;

    int qtde = get_int("Quantas linhas?");
    while(qtde <1 || qtde > 8){
        printf("Quantidade inválida, digite novamente a quantidade de linhas\n");
        qtde = get_int("Quantas linhas?");
    }

    for(linhas=1 ; linhas<=qtde ; linhas++){
        for(imprime=qtde-linhas ; imprime>0; imprime--){
            printf(" ");
        }
        for(imprime=0 ; imprime<linhas; imprime++){
            printf("#");
        }
        printf(" ");
        printf(" ");
        for(imprime=0 ; imprime<linhas; imprime++){
            printf("#");
        }
        printf("\n");
    }
}
