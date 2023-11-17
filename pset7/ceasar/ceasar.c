#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]){
    //Primeiro argumento é o nome do executável
    //Segundo argumento é o parâmetro que precisa ser passado
    if (argc == 2){ //Testa se tem o segundo argumento
        if(isdigit(argv[1]) == 1){ //Verificar se é número
            int chave = atoi(argv[1]);
            

        }else{
            printf("Usage: ./caesar key");
            return 1;
        }
    }else{
        printf("Usage: ./caesar key");
        return 1;
    }
}
