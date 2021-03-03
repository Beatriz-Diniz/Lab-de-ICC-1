#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int readInt(){
    int numNotas;
    scanf("%d\n",&numNotas);  //para determinar a qunatidade de notas que serao inseridas
    return numNotas;
}
double readDouble(){
  double denominador,mediaHarmonica;
  double notas[100];
  int i;
  int n= readInt();
  for (i = 0; i < n; i++) {
        scanf("%lf", &notas[i]); //para inserir as notas
        denominador += 1 / (notas[i] + 1); //para calcular o denominador da equacao
        mediaHarmonica = ((n / denominador) - 1);//para calcular a media 
    }
    return mediaHarmonica;
}
double printDouble(){
  double mediaHarmonica=readDouble(); //funcao para imprimir a media
  printf("%.2lf",mediaHarmonica);
  return mediaHarmonica;
}

int main()
{ 
  printDouble();  //para imprimir a media
}
