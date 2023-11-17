#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){
    //Primeiro argumento é o nome do executável
    //Segundo argumento é o parâmetro que precisa ser passado
    if (argc == 2){ //Testa se tem o segundo argumento
        if(strlen(argv[1]) == 26){ //Verificar se tem 26 caracteres
            //Testa se algum caracetere é número
            if(strchr(argv[1], '0') == NULL && strchr(argv[1], '1') == NULL && strchr(argv[1], '2') == NULL &&
                strchr(argv[1], '3') == NULL && strchr(argv[1], '4') == NULL && strchr(argv[1], '5') == NULL &&
                    strchr(argv[1], '6') == NULL && strchr(argv[1], '7') == NULL && strchr(argv[1], '8') == NULL &&
                        strchr(argv[1], '9') == NULL){

                //Converte para string para procurar valores repetidos
                string chave = argv[1];
                int count = 0;
                for(int i = 0; i < strlen(chave); i++) {
                    count = 1;

                    for(int j = i+1; j < strlen(chave); j++) {
                        if(chave[i] == chave[j] && chave[i] != ' ') {
                            count++;
                            chave[j] = '0';
                        }
                    }

                    if(count > 1 && chave[i] != '0'){
                        printf("Valores duplicados na chave");
                        return 1;
                    }
                }
                //Passou em todas as validações
                //printf("OK");

                string textoOriginal = get_string("Informe o texto limpo: ");
                printf("ciphertext: ");

                for(int i=0 ; i<strlen(textoOriginal) ; i++){
                    int posicaoAscii = (int)tolower(textoOriginal[i]) - 97;
                    //printf(">%i ", posicaoAscii);
                    if(posicaoAscii >= 0 && posicaoAscii <= 26){
                        if(islower(textoOriginal[i])){
                            printf("%c", tolower(chave[posicaoAscii]));
                        }else{
                            printf("%c", toupper(chave[posicaoAscii]));
                        }
                    }else{
                        printf("%c", textoOriginal[i]);
                    }
                }
                printf("\n");
            }else{
                printf("A chave não deve possuir números");
                return 1;
            }
        }else{
            printf("A chave deve ter 26 caracteres");
            return 1;
        }
    }else{
        printf("Quantidade incorreta de argumentos");
        return 1;
    }
}
