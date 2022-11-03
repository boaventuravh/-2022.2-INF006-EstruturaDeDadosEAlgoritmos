/*5) Que leia os elemntos de uma matrix 10x10 e mostre somente os elementos abaixo da diagonal;*/

#include <stdio.h>
#define TAM 10
int main()
{
	int mat[TAM][TAM];

	for(int linha = 0; linha<TAM;linha++)
		for(int coluna=0;coluna<TAM;coluna++)
			{
				printf("\nDigite o valor da posicao %dx%d: ", linha+1, coluna+1);
				scanf("%d", &mat[linha][coluna]);
			}

	printf("\nEis os elementos abaixo da diagonal principal:\n");
	
	for(int linha = 0; linha<TAM;linha++)
	{
		for(int coluna=0;coluna!=linha;coluna++)
			printf("%8d", mat[linha][coluna]);
		printf("\n\n");
	}	
}
