#include <stdio.h>

int main(){
  int numero;// numero inserido
  int fator;// possiveis fatores do numero inserido
  int multiplicidade; // multiplicidade dos fatores

  scanf("%d", &numero);
  fator = 2;
  while (numero > 1) {
      multiplicidade = 0;
      while (numero % fator == 0){
          multiplicidade ++;
          numero = numero / fator; 
      }
      if (multiplicidade != 0) {
          printf("%d %d\n", fator, multiplicidade); 
      }
      fator++; 
  }
  return 0;
}