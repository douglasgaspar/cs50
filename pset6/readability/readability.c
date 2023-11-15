#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void){
    string origem = get_string("Text: ");
    //número de letras, palavras e frases do texto

    char delimitadores[] = "!?.";
    int qtdeFrases = 0;

    char espaco[] = " ";
    int qtdePalavras = 0;

    char * frases = strtok(origem, delimitadores);
    while(frases != NULL){
        qtdeFrases++;
        frases = strtok(NULL, delimitadores);
    }

    char * palavras = strtok(origem, espaco);
    while(palavras != NULL){
        qtdePalavras++;
        palavras = strtok(NULL, espaco);
    }

    //índice = 0,0588 * L - 0,296 * S - 15,8
    //L contar as letras e dividir pela quantidade de palavras. Multiplicar por 100
    //L é o número médio de letras por 100 palavras
    //S quantidade de frases / quantidade de palavras. Multiplica por 100
    //S é o número médio de sentenças por 100 palavras no texto.

    printf("\nFrases: %d", qtdeFrases);
    printf("\nPalavras: %d", qtdePalavras);

    float S = (qtdeFrases / qtdePalavras) * 100;
    printf("\n%f", S);


    // for (int i = 0 ; i < strlen(frase) ; i++){
    //     if (islower(s[i])){
    //         printf("%c", toupper(s[i]));
    //     }else{
    //         printf("%c", s[i]);
    //     }
    // }
    printf("\n");

}
