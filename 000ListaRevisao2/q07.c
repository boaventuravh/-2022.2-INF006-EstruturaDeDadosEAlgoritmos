/*7) Que declare uma matriz 5x5  e armazene em um vetor o maior elemento cadastrado em cada coluna da matriz, e em um vetor b o menor elemento cadastrado em cada coluna da matriz e imprima:
a) toda a matrix;
b) o vetor a;
c) o vetor b;
d)(a+b)/2*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void imprimirMatriz(int mat[][TAM]);
void procuraMaior(int mat[][TAM], int vetA[], int vetB[]);

int main()
{
	int mat[TAM][TAM];
	int a[TAM]; // maiores elementos da coluna
	int b[TAM];	// maiores elementos da linha

	for(int linha = 0; linha<TAM;linha++)
		for(int coluna=0;coluna<TAM;coluna++)
			mat[linha][coluna] = rand()%200;  
	/*a matriz sera preenchida por valores aleatorios de 0 a 100*/

	imprimirMatriz(mat);

	procuraMaior(mat, a, b);

	printf("\nEis os maiores elementos de cada coluna:\n");
	for(int posicao=0;posicao<TAM;posicao++)
		printf("%8d", b[posicao]);
	
	printf("\nEis os maiores elementos de cada linha:\n");
		for(int posicao=0;posicao<TAM;posicao++)
			printf("%8d", a[posicao]);
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

void procuraMaior(int mat[][TAM], int vetA[], int vetB[])
{
	int maiorDaLinha = 0;
	int maiorDaColuna = 0;
	int posicao = 0;

	for(int linha = 0; linha<TAM;linha++)
	{
		for(int coluna=0;coluna<TAM;coluna++)
			if(mat[linha][coluna]>maiorDaLinha)
				maiorDaLinha = mat[linha][coluna];
		vetA[posicao] = maiorDaLinha;
		maiorDaLinha = 0;
		posicao++;
	}
		
	
	posicao = 0;
	for(int linha = 0; linha<TAM;linha++)
	{
		for(int coluna=0;coluna<TAM;coluna++)
			if(mat[coluna][linha]>maiorDaColuna)
				maiorDaColuna = mat[coluna][linha];
		vetB[posicao] = maiorDaColuna;
		maiorDaColuna = 0;
		posicao++;
	}

}