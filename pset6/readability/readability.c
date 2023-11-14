#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void){
    string frase = get_string("Text: ");

    char delimitadores[] = "!?.";

    for (int i = 0 ; i < strlen(frase) ; i++){
        if (islower(s[i])){
            printf("%c", toupper(s[i]));
        }else{
            printf("%c", s[i]);
        }
    }
    printf("\n");

}
