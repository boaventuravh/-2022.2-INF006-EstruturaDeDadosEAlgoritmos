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
void insertionSortListaStrings(char strCopia[][QtdLetras], char strOriginal[][QtdLetras]);
void insertionSortString(char referencia[], char strLista[][QtdLetras], int n);
int maiorString(char listaDeStrings[][QtdLetras]);

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
    insertionSortListaStrings(listaAux, listaNomes);
    
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

void insertionSortListaStrings(char strCopia[][QtdLetras], char strOriginal[][QtdLetras])
{
    char strRef[QtdLetras];
    int maiorStr;

    maiorStr = maiorString(strCopia);

    // no for abaixo, o countChar < 1 faz com que a ordenação ocorra apenas
    // para a primeira letra da lista de strings.
    // Como fazer a ordenação para todas as letras sem que a letra seguinte
    // desfaça a ordenação realizada na letra anterior?
    for(int countChar = 0; countChar < 1; countChar++)
    {
        for(int countNome = 0; countNome < QtdNomes; countNome++)
        {
            strRef[countNome] = strCopia[countNome][countChar];
        }

        insertionSortString(strRef, strOriginal, QtdNomes);

        for (int i = 0; strRef[i] != '\0'; i++)
        {
            strRef[i] = '\0';
        }
        
    }
}

void insertionSortString(char referencia[], char strLista[][QtdLetras], int n)
{
    int i, key, j;
    char keyString[QtdLetras];
    for (i = 1; i < n; i++) 
    {
        key = referencia[i];
        strcpy(keyString, strLista[i]);
        j = i - 1;
 
        while (j >= 0 && referencia[j] > key) 
        {
            referencia[j + 1] = referencia[j];
            strcpy(strLista[j+1], strLista[j]);
            j = j - 1;
        }
        referencia[j + 1] = key;
        strcpy(strLista[j+1], keyString);
    }
}

int maiorString(char listaDeStrings[][QtdLetras]){
    int maior = strlen(listaDeStrings[0]);

    for (int i = 0; i < QtdNomes; i++)
    {
        if(strlen(listaDeStrings[i]) > maior)
            maior = strlen(listaDeStrings[i]);
    }

    return maior;
}