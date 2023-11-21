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
            int chaveCopia = chave;
            //printf("CHAVE: %i", chave);

            printf("ciphertext: ");

            for(int i=0 ; i<(int)strlen(textoOriginal) ; i++){
                //printf(">>> %i", (int)textoOriginal[i] + chave);
                chave = chaveCopia;

                if(isalpha(textoOriginal[i]) != 0){
                    if(islower(textoOriginal[i])){
                        if(((int)textoOriginal[i] + chave) > 122){
                            chave = ((int)textoOriginal[i] + chave) - 122;
                            printf("%c", 96 + chave);
                        }else{
                            printf("%c", tolower(textoOriginal[i] + chave));
                        }
                    }else{
                        if(((int)textoOriginal[i] + chave) > 90){
                            chave = ((int)textoOriginal[i] + chave) - 90;
                            printf("%c", 64 + chave);
                        }else{
                            printf("%c", toupper(textoOriginal[i] + chave));
                        }
                    }
                }else{
                    printf("%c", textoOriginal[i]);
                }
            }
            printf("\n");
        }else{
            printf("Usage: ./caesar key");
            return 1;
        }
    }else{
        printf("Usage: ./caesar key");
        return 1;
    }
}
