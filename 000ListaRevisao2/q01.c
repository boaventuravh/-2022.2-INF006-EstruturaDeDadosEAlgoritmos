/*1) Que imprima o horóscopo de varias pessoas, a aprtir da sua data de nascimento (ddmm). O fim é determinado quando se digita 9999 para data.
considera que a data foi digitada corretamente.
01-20 Capricornio
02-19 Aquario
03-20 Peixes
04-20 Aries
05-20 Touro
06-20 Gemeos
07-21 Cancer
08-22 Leão
09-22 Virgem
10-22 Libra
11-21 Escorpião
12-21   Sargitario*/

#include <stdio.h>
#include <string.h>

int main()
{
    char dataStr[6];
    int dataInt[4], i;
    do{
        do{
    fflush(stdin);
    printf("\n\nInforme sua data de nascimento(formato ddmm, se desejar encerrar, digite 9999): ");
    fgets(dataStr, 5, stdin);
    getchar();
    dataStr[strlen(dataStr)] = '\0';
    
    
    for(i=0;dataStr[i]!='\0';i++)
      dataInt[i] = dataStr[i]-48;
    if (dataInt[0]+dataInt[1]+dataInt[2]+dataInt[3] == 4*9)
        break;
        
    }while(10*dataInt[0] + dataInt[1] <= 0 || 10*dataInt[0] + dataInt[1] > 31 || 10*dataInt[2] + dataInt[3] > 12 || 10*dataInt[2] + dataInt[3] <= 0);
    
        if (dataInt[0]+dataInt[1]+dataInt[2]+dataInt[3] != 4*9)
            printf("\nSeu signo: ");
        
        if(dataInt[2] == 0) //dataInt[2] é o primeiro dígito do mês
        {
        switch(dataInt[3])
        {
            case 1: //janeiro
            {
                if(10*dataInt[0] + dataInt[1] <= 20) //verificando o dia, o primeiro dígito é a casa das dezenas, o segundo é a casa das unidades
                    printf(" Capricornio");
                else
                    printf(" Aquario");
                break; 
            }
            case 2: //fevereiro
            {
                if(10*dataInt[0] + dataInt[1] <= 19) 
                    printf(" Aquario");
                else
                    printf(" Peixes");
                break;
            }
            case 3: // março
            {
                if(10*dataInt[0] + dataInt[1] <= 20) 
                    printf(" Peixes");
                else
                    printf(" Aries");
                break;
            }
            case 4: // abril
            {
                if(10*dataInt[0] + dataInt[1] <= 20) 
                    printf(" Aries");
                else
                    printf(" Touro");
                break;
            }
            case 5: // maio
            {
                if(10*dataInt[0] + dataInt[1] <= 20) 
                    printf(" Touro");
                else
                    printf(" Gemeos");
                break;
            }
            case 6: // junho
            {
                if(10*dataInt[0] + dataInt[1] <= 20) 
                    printf(" Gemeos");
                else
                    printf(" Cancer");
                break;
            }
            case 7: // julho
            {
                if(10*dataInt[0] + dataInt[1] <= 21) 
                    printf(" Cancer");
                else
                    printf(" Leao");
                break;
            }
            case 8: // agosto
            {
                if(10*dataInt[0] + dataInt[1] <= 22) 
                    printf(" Leao");
                else
                    printf(" Virgem");
                break;
            }
            case 9: // setembro
            {
                if(10*dataInt[0] + dataInt[1] <= 22) 
                    printf(" Virgem");
                else
                    printf(" Libra");
                break;
            }
        }
    }
        else
        {
        switch(dataInt[3]){
            case 0: // outubro
            {
                if(10*dataInt[0] + dataInt[1] <= 22) 
                    printf(" Libra");
                else
                    printf(" Escorpiao");
                break;
            }
         case 1: // novembro
            {
                if(10*dataInt[0] + dataInt[1] <= 21) 
                    printf(" Escorpiao");
                else
                    printf(" Sagitario");
                break;
            }
        case 2: // dezembro
            {
                if(10*dataInt[0] + dataInt[1] <= 21) 
                    printf(" Sagitario");
                else
                    printf(" Capricornio");
                break;
            }
        }
        
    }
        
    }while(dataInt[0]+dataInt[1]+dataInt[2]+dataInt[3] != 4*9);
    printf("\n\nPrograma encerrado!");
    return 0;
}