#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]){
    //Primeiro argumento é o nome do executável
    //Segundo argumento é o parâmetro que precisa ser passado
    if (argc == 2){ //Testa se tem o segundo argumento
        char char1 = argv[1][0];

        for(int i=0 ; i<strlen(argv[1]) ; i++){
            if(isdigit(argv[1][i]) == 0){
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        string textoOriginal = get_string("plaintext: ");
        int chave = atoi(argv[1]);

        printf("ciphertext: ");

        for(int i=0 ; i<(int)strlen(textoOriginal) ; i++){
            if(isalpha(textoOriginal[i]) != 0){
                if(islower(textoOriginal[i])){
                    printf("%c", (textoOriginal[i] - 97 + chave) % 26 + 97);
                }else if(isupper(textoOriginal[i])){
                    printf("%c", (textoOriginal[i] - 65 + chave) % 26 + 65);
                }else{
                    printf("%c", textoOriginal[i]);
                }
            }
        }
        printf("\n");

    }else{
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
