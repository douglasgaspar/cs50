#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void){
    string origem = get_string("Text: ");
    //número de letras, palavras e frases do texto

    char delimitadores[] = "!?.";

    char * frases = strtok(origem, delimitadores);



    for (int i = 0 ; i < strlen(frase) ; i++){
        if (islower(s[i])){
            printf("%c", toupper(s[i]));
        }else{
            printf("%c", s[i]);
        }
    }
    printf("\n");

}
