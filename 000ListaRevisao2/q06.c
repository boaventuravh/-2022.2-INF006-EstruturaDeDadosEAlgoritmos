/*6)  Que leia e armazene os elemntos de uma matriz inteira (10,10) e imprima. depois troque os
dados da segunda linha pela oitava. da quarta pela decima, a diagonal principal pela diagonal
segundaria.*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void trocaDeLinha(int mat[][TAM], int lin1, int lin2);
void imprimirMatriz(int mat[][TAM]);
void trocaDiagonal(int mat[][TAM]);
int main()
{
	int mat[TAM][TAM];

	for(int linha = 0; linha<TAM;linha++)
		for(int coluna=0;coluna<TAM;coluna++)
			mat[linha][coluna] = rand()%100;  
	/*a matriz sera preenchida por valores aleatorios de 0 a 100*/

	imprimirMatriz(mat);

	trocaDeLinha(mat, 2, 8);

	trocaDeLinha(mat, 4, 10);

	trocaDiagonal(mat);

	imprimirMatriz(mat);	

	return 0;
}

void imprimirMatriz(int mat[][TAM])
{
	printf("\n\tEis a matriz:\n");
	
	for(int linha = 0; linha<TAM;linha++)
	{
		for(int coluna=0;coluna<TAM;coluna++)
			printf("%8d", mat[linha][coluna]);
		printf("\n\n");
	}
}

void trocaDeLinha(int mat[][TAM], int lin1, int lin2)
{
	lin1--;
	lin2--;
	/*as subtrações acima são necessárias pra respeitar os índices da matriz 
	(a posição x de um vetor tem índice x - 1)*/
	int aux;
	for(int col = 0; col<TAM; col++)
		{
			aux = mat[lin1][col];
			mat[lin1][col] = mat[lin2][col];
			mat[lin2][col] = aux;
		}
}

void trocaDiagonal(int mat[][TAM])
{
	int aux;
	for(int lin=0, diagPrin=0, diagSec=TAM-1;lin<TAM;lin++, diagPrin++, diagSec--)
		if(diagSec != diagPrin)
		{
			aux = mat[lin][diagPrin];
			mat[lin][diagPrin] = mat[lin][diagSec];
			mat[lin][diagSec] = aux;
		}
}
