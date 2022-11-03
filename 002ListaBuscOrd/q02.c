/*2 – Crie um programa que dado uma string,
coloque as letras dela em ordem crescente pelo
algoritmo da bolha.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubbleSort(char str[], int tamanho);

int main (){
    char str[] = "ihgfedcba";

    printf("\nString original: %s", str);
    
    bubbleSort(str, strlen(str));

    printf("\nEis a string reordenada: %s", str);
}

void bubbleSort(char str[], int tamanho) {
 int i, j;
 for(i=1; i<tamanho; i++)
     for(j=0; j<tamanho-i; j++)
        if( str[j]>str[j+1] ) 
        {
             int aux = str[j];
             str[j] = str[j+1];
             str[j+1] = aux;
        }
}