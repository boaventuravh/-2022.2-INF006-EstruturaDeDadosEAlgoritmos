/*1 – Faça um programa que leia n nomes
inserindo-os em uma lista de forma ordenada
utilizando a ideia do algoritmo da inserção. No
final, o programa deve mostrar todos os nomes
ordenados alfabeticamente.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QtdNomes 5
#define QtdLetras 255

void normalizarMinimizar(char str[]);
void insertionSortParaStrings(char strCopia[][QtdLetras], char strOriginal[][QtdLetras], int qtNomes);

// elemento de um array de strings: lista[indiceNome][indiceLetras]

int main () {
    
    char listaNomes[QtdNomes][QtdLetras] = {"Suzano Almeida da Paz Correa", "Jonas Gaivota", "Alberto Herrera", "Gilberto Gil", "Cassandra Oliveira Ramos"};
    char listaAux[QtdNomes][QtdLetras];
    // fazer uma cópia de todos os nomes em um vetor auxiliar
    for(int i = 0; i < QtdNomes; i++)
    {
        strcpy(listaAux[i], listaNomes[i]);
    }
    
    // normalizar e transformar as iniciais em minúsculas no vetor auxiliar
    for(int i = 0; i < QtdNomes; i++)
    {
        normalizarMinimizar(listaAux[i]);
    }
    
    // fazer as comparações e trocas no vetor auxiliar, 
    // todo índice trocado no auxiliar também deve ser trocado no principal simultaneamente
    insertionSortParaStrings(listaAux, listaNomes, QtdNomes);
    for(int i = 0; i < QtdNomes; i++) //teste
    {
        printf("\n%s", listaNomes[i]);    
    }
    
}


void normalizarMinimizar(char str[]){

    //removemos os espaços no laço abaixo
    for (int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
        {
            for(int j = i; str[j+1] != '\0'; j++)
            {
                str[j] = str[j+1];
            }

            str[strlen(str) - 1] = '\0'; // essa linha evita a repetição da última letra no final da string
        }
    }

    //no laço abaixo, as letras maiúsculas se tornam minúsculas
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] += 32;
        }
    }
}

void insertionSortParaStrings(char strCopia[][QtdLetras], char strOriginal[][QtdLetras], int qtNomes)
{
    // Não está funcionando ainda, as strings não trocam de posição
    // Talvez a função strcpy não seja a mais adequada, preciso testar com outra
    // ou mudar as strings de posição sem utilizar funções da biblioteca string.h
    int i, j;
    char key[QtdLetras];
    char keyOriginal[QtdLetras];
    for (i = 1; i < qtNomes; i++) 
    {
	strcpy(key, strCopia[i]); // key = strCopia[i];
	strcpy(keyOriginal, strOriginal[i]);
        j = i - 1;
 
        /* Move elementos de strCopia[0..i-1], que são
          maiores que key, para uma posição à frente
          da posição atual*/
        while (j >= 0 && strCopia[i][j] > key[j])
        {
            strcpy(strCopia[j + 1], strCopia[j]);  //strCopia[j + 1] = strCopia[j];
	    strcpy(strOriginal[j + 1], strOriginal[j]);
            j = j - 1;
        }
        strcpy(strCopia[j + 1], key); //strCopia[j + 1] = key;
	strcpy(strOriginal[j + 1], keyOriginal);
    }
}