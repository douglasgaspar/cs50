/*
Projete e implemente um programa, o caesar , que criptografa mensagens usando a cifra de César.

Implemente seu programa em um arquivo denominado caesar.c em um diretório denominado caesar .
Seu programa deve aceitar um único argumento de linha de comando, um inteiro não negativo. Vamos chamá-lo de k para fins de discussão.
Se o seu programa for executado sem nenhum argumento de linha de comando ou com mais de um argumento de linha de comando, seu programa deve imprimir uma mensagem de erro de sua escolha (com printf ) e retornar de main um valor de 1 (o que tende a significar um erro ) imediatamente.
Se algum dos caracteres do argumento da linha de comando não for um dígito decimal, seu programa deve imprimir a mensagem Use: ./caesar key e retornar de main o valor 1 .
Não suponha que k será menor ou igual a 26. Seu programa deve funcionar para todos os valores integrais não negativos de k menores que 2 ^ 31 - 26. Em outras palavras, você não precisa se preocupar se seu programa eventualmente quebra se o usuário escolher um valor para k que é muito grande ou quase grande para caber em um int . (Lembre-se de que um int pode estourar.) Mas, mesmo se k for maior que 26, os caracteres alfabéticos na entrada do programa devem permanecer caracteres alfabéticos na saída do programa. Por exemplo, se k é 27, A não deve se tornar [ embora [ esteja a 27 posições de A em ASCII, por http://www.asciichart.com/[asciichart.com]; A deve tornar-se B , já que B esta a 27 posições de A , desde que você revolva em torno de Z a A.
Seu programa deve produzir plaintext: (sem uma nova linha) [texto simples] e então solicitar ao usuário uma string de texto simples (usando get_string ).
Seu programa deve produzir ciphertext: (sem uma nova linha) [texto cifrado] seguido pelo texto cifrado correspondente do texto simples, com cada caractere alfabético no texto simples “girado” por k posições; os caracteres não alfabéticos devem ser reproduzidos inalterados.
Seu programa deve preservar as letras maiúsculas e minúsculas: as letras maiúsculas, embora giradas, devem permanecer letras maiúsculas; as letras minúsculas, embora giradas, devem permanecer em minúsculas.
Após a saída do texto cifrado, você deve imprimir uma nova linha. Seu programa deve então sair retornando 0 de main.
*/

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
                    int posicaoAscii = (int)textoOriginal[i];
                    printf(">%i ", posicaoAscii);
                    if(posicaoAscii >= 65 && posicaoAscii <= 122){
                        printf("%c", chave[posicaoAscii]);
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
