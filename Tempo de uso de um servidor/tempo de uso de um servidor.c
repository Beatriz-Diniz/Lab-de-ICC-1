#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    float horas[13];
    float maior = 0.0;
    int meses;
    int i;
    
    for (i = 0; i < 12; i++){ //para inserir as horas jogadas no servidor
        scanf("%f", &horas[i]);  
        if(horas[i] > maior){ 
            maior = horas[i];
            meses = i;
        }
    }
    printf("%d %.2f", meses+1, maior);
    return 0;
}