/*3) Que  entre com dados num vetor VET do tipo inteiro com 20 poisições, onde podem existir varios elementos
repetidos. Gere um vetor VET1 que tambem será ordenado e terá somente os elementos do vetor VET que não sao repetidos.*/

#include <stdio.h>
#define QTDE 20


int main()
{
    int vet1[QTDE], vet2[QTDE], indiceRepeat[QTDE];
    
    for (int i = 0; i<QTDE; i++)
        indiceRepeat[i]=0;
    
    for(int i = 0; i<QTDE; i++)
    {
        printf("\nDigite o %do valor: ", i+1);
        scanf("%d", &vet1[i]);
    }

   
    for(int i=0; i<QTDE; i++)
	{
		for(int j = i+1; j<QTDE; j++)
            if(indiceRepeat[i] == 0)
            {
                if (vet1[i] == vet1[j])
				{
					indiceRepeat[i]++;
					if(indiceRepeat[j] == 0)
						indiceRepeat[j]++;
				}
            }
	}
	
	int qtdeVet2 = 0; // contagem da quantidade de elementos de vet2
	
	// i percorre o vetor indiceRepeat, j percorre vet1
	for(int i=0, j=0; i<QTDE; i++) 
		if(indiceRepeat[i] == 0)
		{
			vet2[j]=vet1[i];
			j++;
			qtdeVet2++;
		}
	
	for(int i = 1;i<qtdeVet2;i++)
		for(int j = 0, aux=0;j<qtdeVet2-1;j++)
			if(vet2[j]>vet2[j+1])
			{
				aux = vet2[j];
				vet2[j] = vet2[j+1];
				vet2[j+1] = aux;
			}

	printf("\nEis o vetor 2 ordenado: ");

	for(int i = 0;i<qtdeVet2;i++)
		printf("%8d", vet2[i]);
	
    return 0;
}
