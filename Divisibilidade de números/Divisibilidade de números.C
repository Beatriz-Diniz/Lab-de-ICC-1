#include<stdlib.h>
#include<stdio.h>

int main()
{
    int numero[31],i;

    for(i = 0; i < 31; i++){	//para ler os vetores inseridos na entrada
        scanf("%d", &numero[i]);
    }
    for(i = 0; i < 30; i++){	//imprime se o resto da divisão for zero
      if(!(numero[i]%numero[30]))
          printf("%d\n",numero[i]);
    }
    return 0;
}