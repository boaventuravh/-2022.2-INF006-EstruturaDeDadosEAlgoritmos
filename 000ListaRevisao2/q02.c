/*2) Que dado dois vetores de 10 posições, efetue operações basicas aritmeticas, indicadas por um terceiro vetor
cujos dados tambem são fornecidos pelo usuario, gerando e imprimindo um quarto vetor.*/

#include <stdio.h>
#define TAM 10

int main()
{
    int i;
    float num1[TAM], num2[TAM], final[TAM];
    char opera[TAM];
    for(i=0;i<TAM;i++)
    {
        fflush(stdin);
        printf("\nDigite o valor 1: ");
        scanf("%f", &num1[i]);
        printf("\nAgora digite o valor 2: ");
        scanf("%f", &num2[i]);
        getchar();
        printf("\nDigite a operacao entre eles(*, /, + ou -): ");
        scanf("%c", &opera[i]);
        while(opera[i] != '*' && opera[i] != '-' && opera[i] != '+'&& opera[i] != '/')
        {
            fflush(stdin);
            printf("\nOperacao invalida, tente novamente: ");
            scanf("%c", &opera[i]);
            getchar();
        }
        if(opera[i] == '/')
        {
            while(num2[i] == 0)
            {
                printf("\nNao eh possivel dividir por 0, escolha outro valor: ");
                scanf("%f", &num2[i]);
            }
        }
        
        switch(opera[i])
        {
            case '+': final[i] = num1[i] + num2[i];break;
            case '-': final[i] = num1[i] - num2[i];break;
            case '*': final[i] = num1[i] * num2[i];break;
            case '/': final[i] = num1[i] / num2[i];break;
        }
    }
    
    printf("\nEis o resultado das operacoes:");
    for(i=0;i<TAM;i++)
    {
        printf("\n%.2f %c %.2f = %.2f", num1[i], opera[i], num2[i], final[i]);
    }

    return 0;
}