#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
   
void terra_tempo(long int *segundo,
 long int *minuto, long int *hora, long int *dia, long int segundos){ //função para calucular o tempo na terra

  *segundo = segundos;      //para transferir o total de segundos inseridos para o ponteiro segundo

  if(*segundo>59){          //se a quantia inseridas de segundos for maior que 59 significa que vai ter minutos
    *minuto=(*segundo/60);  //para saber a quantia de minutos os segundos é dividido por 60 e o quociente é a quantia de minutos
    *segundo=(*segundo%60); //a quantia de segundos vai ser o resto da divisao para achar a quantia de minutos
  }
  if(*minuto>59){           //se a quantia de minutos for maior que 59 significa que vai ter horas
    *hora=(*minuto/60);     //para saber a quantia de horas os minutos é dividido por 60 e o quociente é a quantia de horas
    *minuto=(*minuto%60);   //a quantia de minutos vai ser o resto da divisao para achar a quantia de horas
  }
  if(*hora>23){             //se a quantia inseridas de horas for maior que 23 significa que vai ter dias
    *dia=(*hora/24);        //para saber a quantia de dias as horas é dividido por 24 e o quociente é a quantia de horas 
    *hora=(*hora%24);       //a quantia de horas vai ser o resto da divisao para achar a quantia de dias
  }
}

void mercurio_tempo(long int *segundo,
 long int *minuto, long int *hora, long int *dia, long int segundos){ //função para calucular o tempo em mercurio

  *segundo = segundos;      //para transferir o total de segundos inseridos para o ponteiro segundo

  if(*segundo>59){          //se a quantia inseridas de segundos for maior que 59 significa que vai ter minutos
    *minuto=(*segundo/60);  //para saber a quantia de minutos os segundos é dividido por 60 e o quociente é a quantia de minutos
    *segundo=(*segundo%60); //a quantia de segundos vai ser o resto da divisao para achar a quantia de minutos
  }
  if(*minuto>59){           //se a quantia de minutos for maior que 59 significa que vai ter horas
    *hora=(*minuto/60);     //para saber a quantia de horas os minutos é dividido por 60 e o quociente é a quantia de horas
    *minuto=(*minuto%60);   //a quantia de minutos vai ser o resto da divisao para achar a quantia de horas
  }
  if(*hora>1407){           //se a quantia inseridas de horas for maior que 1407 significa que vai ter dias
    *dia=(*hora/1408);      //para saber a quantia de dias as horas é dividido por 1408 e o quociente é a quantia de horas 
    *hora=(*hora%1408);     //a quantia de horas vai ser o resto da divisao para achar a quantia de dias
  }
}

void venus_tempo(long int *segundo,
 long int *minuto, long int *hora, long int *dia, long int segundos){ //função para calucular o tempo em venus

  *segundo = segundos;      //para transferir o total de segundos inseridos para o ponteiro segundo

  if(*segundo>59){          //se a quantia inseridas de segundos for maior que 59 significa que vai ter minutos
    *minuto=(*segundo/60);  //para saber a quantia de minutos os segundos é dividido por 60 e o quociente é a quantia de minutos
    *segundo=(*segundo%60); //a quantia de segundos vai ser o resto da divisao para achar a quantia de minutos
  }
  if(*minuto>59){           //se a quantia de minutos for maior que 59 significa que vai ter horas
    *hora=(*minuto/60);     //para saber a quantia de horas os minutos é dividido por 60 e o quociente é a quantia de horas
    *minuto=(*minuto%60);   //a quantia de minutos vai ser o resto da divisao para achar a quantia de horas
  }
  if(*hora>5831){           //se a quantia inseridas de horas for maior que 5831 significa que vai ter dias
    *dia=(*hora/5832);      //para saber a quantia de dias as horas é dividido por 5832 e o quociente é a quantia de horas 
    *hora=(*hora%5832);     //a quantia de horas vai ser o resto da divisao para achar a quantia de dias
  }
}

void jupiter_tempo(long int *segundo,
 long int *minuto, long int *hora, long int *dia, long int segundos){ //função para calucular o tempo em jupiter

  int i=0;
  *segundo = segundos;       //para transferir o total de segundos inseridos para o ponteiro segundo

  if(*segundo>35759){       //se a quantidade de segundos for maior que 35759 = um dia
    *dia=(*segundo/35760);  //a quantia de dias vai ser o quociente da divisao dos segundos por 35760
    i=(*segundo%35760);     //i vai armazenar o resto da divisao de segundos por 35760
    *segundo=(i%60);        //a quantia de segundos restantes vai ser o resto de i por 60
    i=(i/60);               //o novo valor de i vai ser o valor armazenado dividido por 60
    *minuto=(i%60);         //a quantia de minutos vai ser igual ao resto do valor novo de i dividido por 60
    *hora=(i/60);           //a quantia de horas vai ser igual ao quociente da divisao do valor novo de i por 60
  }else{                    //se a quantidade de segundos for menor que 35759 = um dia
    *minuto=(*segundo/60);  //para saber a quantia de minutos os segundos é dividido por 60 e o quociente é a quantia de minutos
    *segundo=(*segundo%60); //a quantia de segundos vai ser o resto da divisao para achar a quantia de minutos
    *hora=(*minuto/60);     //para saber a quantia de horas os minutos é dividido por 60 e o quociente é a quantia de horas
    *minuto=(*minuto%60);   //a quantia de minutos vai ser o resto da divisao para achar a quantia de horas
    *dia=0;                 //como a quantia de segundos é inferior a um dia o valor de dia vai ser igual a 0
  }
}
int main(){

  char planetas[5];                                         //variavel para inserir o planeta escolhido
  char terra[6]={'T','e','r','r','a','\0'};                 //variavel que contem o planeta terra para usar como comparação
  char mercurio[9]={'M','e','r','c','u','r','i','0','\0'};  //variavel que contem o planeta mercurio para usar como comparação
  char venus[6]={'V','e','n','u','s','\0'};                 //variavel que contem o planeta venus para usar como comparação
  char jupiter[8]={'J','u','p','i','t','e','r','\0'};       //variavel que contem o jupiter terra para usar como comparação
  long int segundo=0, minuto=0, hora=0, dia=0, segundos=0;  //variaveis que irão armazenar os tempos
  int i=0, j=0;                                             //variaveis auxiliares
  
  scanf("%ld %s",&segundos, &planetas[j]);  //para inserir a quantia de segundos e escolher o planeta
  
  if(planetas[j]==terra[i]){                                         //se o planeta escolhido for a Terra
    terra_tempo(&segundo,&minuto, &hora, &dia, segundos);            //para chamar a função para transferir os valores calculados pela função
    printf("%ld segundos no planeta Terra equivalem a:\n",segundos); //para imprimir o total de segundos inseridos
    printf("%ld dias,", dia);                                        //para imprimir o total de dias
    printf(" %ld horas,", hora);                                     //para imprimir o total de horas
    printf(" %ld minutos e", minuto);                                //para imprimir o total de minutos
    printf(" %ld segundos\n", segundo);                              //para imprmir o total de segundos restantes
  }
  
  if(planetas[j]==mercurio[i]){                                         //se o planeta escolhido for Mercurio
    mercurio_tempo(&segundo,&minuto, &hora, &dia, segundos);            //para chamar a função para transferir os valores calculados pela função
    printf("%ld segundos no planeta Mercurio equivalem a:\n",segundos); //para imprimir o total de segundos inseridos
    printf("%ld dias,", dia);                                           //para imprimir o total de dias                                        //para imprimir o total de dias
    printf(" %ld horas,", hora);                                        //para imprimir o total de horas
    printf(" %ld minutos e", minuto);                                   //para imprimir o total de minutos
    printf(" %ld segundos\n", segundo);                                 //para imprmir o total de segundos restantes
  }
  
  if(planetas[j]==venus[i]){                                          //se o planeta escolhido for Venus
    venus_tempo(&segundo,&minuto, &hora, &dia, segundos);             //para chamar a função para transferir os valores calculados pela função
    printf("%ld segundos no planeta Venus equivalem a:\n",segundos);  //para imprimir o total de segundos inseridos
    printf("%ld dias,", dia);                                         //para imprimir o total de dias  
    printf(" %ld horas,", hora);                                      //para imprimir o total de horas
    printf(" %ld minutos e", minuto);                                 //para imprimir o total de minutos
    printf(" %ld segundos\n", segundo);                               //para imprmir o total de segundos restantes
  }
  
  if(planetas[j]==jupiter[i]){                                         //se o planeta escolhido for Jupiter
    jupiter_tempo(&segundo,&minuto, &hora, &dia, segundos);            //para chamar a função para transferir os valores calculados pela função
    printf("%ld segundos no planeta Jupiter equivalem a:\n",segundos); //para imprimir o total de segundos inseridos
    printf("%ld dias,", dia);                                          //para imprimir o total de dias 
    printf(" %ld horas,", hora);                                       //para imprimir o total de horas
    printf(" %ld minutos e", minuto);                                  //para imprimir o total de minutos
    printf(" %ld segundos\n", segundo);                                //para imprmir o total de segundos restantes
  }
  return 0;
}