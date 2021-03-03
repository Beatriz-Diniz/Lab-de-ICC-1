#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void change(int moeda[6],int sizeof_moeda){
 	moeda[100]=0;
	int resto=0;
 	int moeda100=0;
 	int moeda50=0;
 	int moeda25=0;
 	int moeda10=0;
 	int moeda5=0;
 	int moeda1=0;
	scanf("%d", &resto); //para inserir o valor do troco
  
	if(resto>=100){
		moeda100=resto/100;
		resto=resto%100;	//para saber a quantia de moedas de 1 real
    	moeda[0]=moeda100;
	}

	if(resto>=50){
		moeda50=resto/50;
		resto=resto%50;		//para saber a quantia de moedas de 50 centavos
    	moeda[1]=moeda50; 
	}
	if(resto>=25){
		moeda25=resto/25;
		resto=resto%25;		//para saber a quantia de moedas de 25 centavos
    	moeda[2]=moeda25;
	}
	if(resto>=10){
		moeda10=resto/10;
		resto=resto%10;		//para saber a quantia de moedas de 10 centavos
    	moeda[3]=moeda10;
	}
	if(resto>=5){
		moeda5=resto/5;
		resto=resto%5;		//para saber a quantia de moedas de 5 centavos
    	moeda[4]=moeda5;
	}
	if(resto>=1){
		moeda1=resto/1;		//para saber a quantia de moedas de 1 centavo
    	moeda[5]=moeda1;
	}
  
}

int main(){
  int a[100];
  a[0]=0;
  a[1]=0;
  a[2]=0;
  a[3]=0;	//para iniciar as variaveis com zero
  a[4]=0;
  a[5]=0;

  change(a,6); //para transferiri os valores da função para a variavel

  printf("O valor consiste em %d moedas de 1 real\nO valor consiste em %d moedas de 50 centavos\nO valor consiste em %d moedas de 25 centavos\nO valor consiste em %d moedas de 10 centavos\nO valor consiste em %d moedas de 5 centavos\nO valor consiste em %d moedas de 1 centavo\n", a[0],a[1],a[2],a[3],a[4],a[5]);
  return 0;
}
