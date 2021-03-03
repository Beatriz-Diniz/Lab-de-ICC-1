#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main ()
{
  int i;
  char comando[200], direcao,posicaoFinal;
  direcao = 0;

  scanf("%s",comando);  //para inserir os comandos
  for (i=0; i<=comando[i]; i++){  
    if (comando[i] == 'D'){
      direcao ++; //para determinar que deve somar +1 cada vez que o comando D for digitado
      if (direcao >= 4 || direcao <0){  
        direcao = direcao%4;  /*para determinar que que as direções formam um ciclo de 4 posições
         e que quando a soma de suas posições forem maior que 4 ou menor que 0 sinifica que foi 
         dada n voltas completas e mais x posições*/
      }
    }
    if (comando[i] == 'E'){
      direcao --; //para determinar que deve subtrair -1 cada vez que o comando E for digitado
      if (direcao >=0 && direcao<4){
        direcao = direcao;  /*para determinar em qual direção o comando parou quando as somas 
        de seus valores forem maior que 0 e menor que 4*/
      } 
    }  
  }
  posicaoFinal=direcao;
  if (posicaoFinal == 0 || posicaoFinal==-4){ /*para imprimir a posição norte quando a 
  posicaoFinal parar em 0 ou 4*/
    printf ("Norte\n");
  }
  else if (posicaoFinal == 1 || posicaoFinal==-3){  /*para imprimir a posição leste quando a 
  posicaoFinal parar em 1 ou -3*/
    printf ("Leste\n");
  }
  else if (posicaoFinal == 2 || posicaoFinal==-2){  /*para imprimir a posição sul quando a 
  posicaoFinal parar em 2 ou -2*/
    printf ("Sul\n");
  }
  else if (posicaoFinal == 3 || posicaoFinal ==-1){ /*para imprimir a posição oeste quando a 
  posicaoFinal parar em 3 ou -1*/
    printf ("Oeste\n");
  }
  return 0;
}