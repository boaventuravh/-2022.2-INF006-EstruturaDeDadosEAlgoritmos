#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoData{
int dia;
int mes;
int ano;
int validade;
}Data;

int validarData(int dia, int mes, int ano);
int validarStringData(char data[]);
long int somaDias(Data data, int valor);


int main(){
    
    Data dataInt;
    char dataString[12];

    printf("\nDigite uma data no formato dd/mm/aaaa: ");
    scanf("%d/%d/%d", &dataInt.dia, &dataInt.mes, &dataInt.ano);
    getchar();
    dataInt.validade = validarData(dataInt.dia, dataInt.mes, dataInt.ano);
    
    if(dataInt.validade == 0)
        printf("\nData invalida!\n");

    else
        printf("\nData validada com sucesso!\n");

    printf("\nDigite uma data no formato dd/mm/aaaa: ");
    fgets(dataString, 12, stdin);
    int valiDataString = validarStringData(dataString);
	if(valiDataString == 0)
        printf("\nData invalida!\n");

    else
        printf("\nData validada com sucesso!\n");
}

int validarData(int dia, int mes, int ano){
    
    Data data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    data.validade = 1;

    if(data.dia<1 || data.dia > 31 || data.mes < 1 || data.mes > 12 || data.ano<10)
    {
        data.validade = 0;
        return data.validade;
    }

    else if(data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11)
    {
        if(data.dia>30){
            data.validade = 0;
            return data.validade;
        }
    }

    else if(data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12)
    {
        if(data.dia>31){
            data.validade = 0;
            return data.validade;
        }
    }

    else if(data.mes == 2)
    {
        if(data.ano % 4 == 0 && (data.ano % 100 != 0 || data.ano % 400 == 0))
        {
            if(data.dia>29)
            {
            data.validade = 0;
            return data.validade;
            }
        }

        else
        {
            if(data.dia>28)
            {
            data.validade = 0;
            return data.validade;
            }
        }
    }

    data.validade = 1;
    return data.validade;
	
}

int validarStringData(char dataString[]){
    
    char aux[12];
    int data;
    Data dataInt;
    int i, j = 0;
    
    if(dataString[2] != '/' || dataString[5] != '/')
        return 0;
    
    for(i=0;dataString[i]!='\0';i++)
        aux[i] = dataString[i];
    
    // Copiando apenas numeros para o vetor dataString
        for(i = 0; aux[i] != '\0'; i++){
            if(aux[i] >= 48 && aux[i] <= 57){
                dataString[j] = aux[i];
                j++;
            }
        }
        dataString[j] = '\0';
        
    if(j<8)
        return 0;
        
    // Transformando a data (string) em data (int)
    data = atoi(dataString);
    
    dataInt.ano = data % 10000;
    dataInt.mes = (data / 10000) % 100;
    dataInt.dia = (data / 10000) / 100;
    
    if(dataInt.dia > 31)
        dataInt.validade = 0;
        // printf("\nDia invalido");
    if(dataInt.mes > 12)
        dataInt.validade = 0;
        // printf("\nMes invalido");
        
    int maxDias;
    if(dataInt.mes == 2){
        if((dataInt.ano % 400 == 0) || ((dataInt.ano % 4 == 0) && (dataInt.ano % 100 != 0))) {
            // Ano Bissexto
            if(dataInt.mes == 2)
                maxDias = 29;
        }
        else {
            // Ano não bissexto
            if(dataInt.mes == 2)
                maxDias = 28;
        }
        if(dataInt.mes == 2 && dataInt.dia > maxDias)
            dataInt.validade = 0;
            // printf("Erro. O mes %d teve %d dias neste ano.", mes, maxDias);
    }
    else{
        if(dataInt.mes == 4 || dataInt.mes == 6 || dataInt.mes == 9 || dataInt.mes == 11)
            maxDias = 30;
        else
            maxDias = 31;
            
        if(dataInt.dia > maxDias)
            dataInt.validade = 0;
            // printf("\nErro. O mes %d possui apenas %d dias", mes, maxDias);
    }

    return dataInt.validade;
}

long int somaDias(Data data, int valor) {
    // primeiro passo: calcular a quantidade de dias com base na quantidade de anos
        //qtdeDias = (ano - 1)*365
        //qtdeBissextos = (ano)/4
        //qtdeDias += qtdeBissextos

    int qtdeDias = (data.ano - 1)*365;
    // acima, subtraimos por um porque o ano informado na data é uma fração, não um inteiro

    qtdeDias += data.ano/4;
    // a operação acima acrescenta os dias extras de cada ano bissexto (366 dias)

    // segundo passo: acrescentar a quantidade de dias refetente à quantidade de meses

    for (int i = 1; i<data.mes; i++)
        {
            if (i == 4 || i == 6 || i == 9 || i == 11)
                qtdeDias += 30;
        }
        
}