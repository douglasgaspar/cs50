/*
Projete e implemente um programa, readability, que calcule o índice Coleman-Liau do texto.

Implemente seu programa em um arquivo denominado readability.c em um diretório denominado readability.
Seu programa deve solicitar ao usuário uma string de texto (usando get_string ).
Seu programa deve contar o número de letras, palavras e frases do texto. Você pode assumir que uma letra é qualquer caractere minúsculo de a a z ou qualquer caractere maiúsculo de A a Z , qualquer sequência de caracteres separados por espaços deve contar como uma palavra e que qualquer ocorrência de um ponto final, ponto de exclamação ou ponto de interrogação indica o final de uma frase.
Seu programa deve imprimir como saída "Grade X", onde X é o nível de grau calculado pela fórmula de Coleman-Liau, arredondado para o número inteiro mais próximo.
Se o número do índice resultante for 16 ou superior (equivalente ou superior ao nível de leitura de graduação sênior), seu programa deve produzir "Grade 16+" em vez de fornecer o número do índice exato. Se o número do índice for menor que 1, seu programa deve imprimir "Before Grade 1" .
*/
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

    qtdeLetras++;
    //printf("\nFrases: %d", qtdeFrases);
    //printf("\nPalavras: %d", qtdePalavras);
    //printf("\nLetras: %d\n", qtdeLetras);


    float S = ((float)qtdeFrases / (float)qtdePalavras) * 100;
    //printf("\n%f", S);

    float L = ((float)qtdeLetras / (float)qtdePalavras) * 100;
    //printf("\n%f", L);

    float indice = 0.0588 * L - 0.296 * S - 15.8;
    //printf("\n%i", ceil(indice));

    int indiceInt = round(indice);

    if(indiceInt < 1){
        printf("Before Grade 1\n");
    }else if(indiceInt > 16){
        printf("Grade 16+\n");
    }else{
        printf("Grade %i\n", indiceInt);
    }
}
