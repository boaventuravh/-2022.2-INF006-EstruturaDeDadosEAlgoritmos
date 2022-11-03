/*4) Que armazene 10 numeros em um vetor. Na entrada de dados, o numero ja deve ser armazenado na sua posição definitiva em ordem decrescente. imprimir o vetor logo apos a entrada de dados;*/

#include <stdio.h>
#define QTDE 10

int main(){

	int vet[QTDE];

	for (int i = 0; i < QTDE; ++i)
		vet[i]=0;

	for(int count=0;count<QTDE;count++)
	{
		printf("\nDigite o %do valor: ", count+1);
		scanf("%d", &vet[count]);
		for (int i = 0; i < QTDE; ++i)
		 {
			
		   	for (int j = i + 1; j < QTDE; ++j)
		   	{
				if (vet[i] < vet[j])
				    {
				     int a = vet[i];
				     vet[i] = vet[j];
				     vet[j] = a;
				   	}
		  	}
		 }
		printf("\nOrdem decrescente:\n");
			if(vet[count] != 0)
				for(int k=0;k<count+1;k++)
					printf("%8d", vet[k]);
	}

 	
	
	
	return 0;
}