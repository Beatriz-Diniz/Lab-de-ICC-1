#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main() {
	float base, expoente, potencia, contador;

	scanf("%f", &base);
	scanf("%f", &expoente);
	potencia = 1;
	contador = 0;

	while (contador != expoente) {
		potencia = potencia * base;
		contador = contador + 1;
	}
	printf("%.4f\n", potencia);
	return 0;

}
