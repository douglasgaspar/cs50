#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void){
    string origem = get_string("Text: ");
    //número de letras, palavras e frases do texto

    int qtdeFrases = 0;
    int qtdePalavras = 0;
    int qtdeLetras = 0;

    for(int i=0 ; i<strlen(origem) ; i++){
        qtdeLetras++;

        if(origem[i] == '!' || origem[i] == '?' || origem[i] == '.'){
            qtdeFrases++;
        }
        if(origem[i] == ' '){
            qtdePalavras++;
        }
        if(origem[i] == ',' || origem[i] == '\'' || origem[i] == ':' || origem[i] == ';'){
            qtdeLetras--;
        }
    }

    qtdePalavras++;
    qtdeLetras = qtdeLetras - qtdePalavras - qtdeFrases;

    //índice = 0,0588 * L - 0,296 * S - 15,8
    //L contar as letras e dividir pela quantidade de palavras. Multiplicar por 100
    //L é o número médio de letras por 100 palavras
    //S quantidade de frases / quantidade de palavras. Multiplica por 100
    //S é o número médio de sentenças por 100 palavras no texto.

    printf("\nFrases: %d", qtdeFrases);
    printf("\nPalavras: %d", qtdePalavras);
    printf("\nLetras: %d\n", qtdeLetras);

    float S = ((float)qtdeFrases / (float)qtdePalavras) * 100;
    printf("\n%f", S);

    float L = ((float)qtdeLetras / (float)qtdePalavras) * 100;
    printf("\n%f", L);

    float indice = 0.0588 * L - 0.296 * S - 15.8;
    printf("\n%f", indice);

    if(indice < 1){
        printf("Before Grade 1\n");
    }else if(indice > 16){
        printf("Grade 16+\n");
    }else{
        printf("Grade %f\n", indice);
    }
}
