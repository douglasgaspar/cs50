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

        //printf("%i\n", isdigit(char1));
        if(isdigit(char1) != 0){ //Verificar se é número
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
        }else{
            printf("Usage: ./caesar key");
            return 1;
        }
    }else{
        printf("Usage: ./caesar key");
        return 1;
    }
}
