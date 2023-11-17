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
        printf("%c\n", char1);

        printf("%i\n", isdigit(char1));
        if(isdigit(char1) == 1){ //Verificar se é número
            string textoOriginal = get_string("plaintext: ");
            int chave = atoi(argv[1]);
            printf("%i", chave);

            printf("ciphertext: ");

            for(int i=0 ; i<strlen(textoOriginal) ; i++){
                int posicaoAscii = (int)tolower(textoOriginal[i]) - 97;
                //printf(">%i ", posicaoAscii);
                if(posicaoAscii >= 0 && posicaoAscii <= 26){
                    if(islower(textoOriginal[i])){
                        printf("%c", tolower(textoOriginal[posicaoAscii + chave]));
                    }else{
                        printf("%c", toupper(textoOriginal[posicaoAscii + chave]));
                    }
                }else{
                    printf("%c", textoOriginal[i]);
                }
            }
        }else{
            printf("Usage: ./caesar key numero");
            return 1;
        }
    }else{
        printf("Usage: ./caesar key qtde");
        return 1;
    }
}
