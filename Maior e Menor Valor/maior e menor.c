#include<stdio.h>
#include<stdlib.h>

int main(){
	int i, c, numero, maior, menor;
	maior = 0;
	menor = 100000;

	scanf("%d", &c); //determinar a quantidade de numeros inseridos
	for (i = 1; i <= c; i++) {
		scanf("%d", &numero);
		if (maior < numero) { //encontrar o maior valor
			maior = numero;
		}
		if (menor > numero) { //encontrar o menor valor
			menor = numero;
		}
	}
	printf("max: %d\nmin: %d\n", maior, menor);
	return 0;
}
