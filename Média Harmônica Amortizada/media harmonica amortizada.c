#include<stdio.h>
#include<stdlib.h>


int main() 
{
    int numNotas, i;
    float mediaHarmonica, denominador;
    float notas[100];
    fflush(stdin);

    scanf("%d", &numNotas); //para determinar o n�mero de notas que ser�o inseridas
    for (i = 0; i < numNotas; i++) {
        scanf("%f", &notas[i]); //para inserir as notas
        denominador += 1 / (notas[i] + 1); //para calcular o denominador da equa��o
        mediaHarmonica = ((numNotas / denominador) - 1);//para calcular a m�dia 
    }
    printf("%.2f", mediaHarmonica); //para imprimir o valor da m�dia
    return 0;
}
