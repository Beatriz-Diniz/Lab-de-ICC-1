#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ataques{
  int indice_ataque;
  float valor_ataque;
}ataque[200];

/*funcao qsort*/
int comparar_inteiro (const void *a, const void *b) { 
  
  int posicao1 = ((struct ataques *)a)->valor_ataque;
  int posicao2 = ((struct ataques *)b)->valor_ataque;
  return (posicao1 - posicao2);
}

int main(){

  int tamanho_da_matriz,i=0, j=0;
  int linha, coluna, aux, tipo;
  float **matriz;
  int *ataque;
  int *tipos;

    ataque=(int*)malloc(100*sizeof(int));
    tipos=(int*)malloc(100*sizeof(int));

  struct ataques *atq;
  /*alocar memoria para a struct*/
  atq=(struct ataques*)malloc(1000*sizeof(struct ataques));

  /*determinar o tamanho da matriz*/
  scanf("%d", &tamanho_da_matriz);
  
  /*alocar memoria para a matriz de acordo com o tamanho definido*/
  matriz=(float**)malloc((tamanho_da_matriz+10)*sizeof(float));  //para criar um array de ponteiros
  for(i=0;i<tamanho_da_matriz;i++){
      matriz[i]=(float*)malloc((tamanho_da_matriz+10)*sizeof(float)); //para criar um array de int
  }
  /*para inserir os valores da matriz*/
  for(linha=0; linha<tamanho_da_matriz; linha++){
    for(coluna=0; coluna<tamanho_da_matriz; coluna++){
      scanf("%f", &matriz[linha][coluna]);
    }
  }

  /*para inserir os valores dos ataques e tipos ate encontar o -1*/
  i=0, j=0;
  while(aux!=-1){
    aux=0;
    /*para inserir os valores dos atques*/
    scanf("%d", &ataque[i]);
    aux = ataque[i];
      
    /*para criar o indice do ataque*/
    atq[j].indice_ataque=j;
      
    /*para forcar a parada quando encontrar o -1 e elimina-lo do vetor*/
    if(aux == -1){
      ataque[i]='\0';
      i--;
      break;
    }
    
    /*para inserir os tipos de ataques*/
    scanf("%d", &tipos[j]); 
      
    i++;
    j++;
  }

  /*para determinar qual vai ser o tipo de inimigo*/
  scanf("%d", &tipo);

  j=0;
  /*para calcular os danos ocasionado para cada tipo de ataque*/
  for(linha=0; linha<tamanho_da_matriz; linha++){
    coluna=tipo;

    atq[j].valor_ataque=matriz[linha][coluna]*(ataque[linha]);
    j++;
  }
  
  /*para ordenar os danos em ordem crescente*/
  qsort(atq, tamanho_da_matriz, sizeof(struct ataques), comparar_inteiro);

  /*para imprimir o maior dano e seu respctivo indice e se dois danos forem iguais imprimir aquele de menor indice*/
  if(atq[tamanho_da_matriz-1].valor_ataque>atq[tamanho_da_matriz-2].valor_ataque){
    printf("O melhor ataque possui indice %d e dano %.2f\n",atq[tamanho_da_matriz-1].indice_ataque,atq[tamanho_da_matriz-1].valor_ataque);
  }
  if(atq[tamanho_da_matriz-1].valor_ataque==atq[tamanho_da_matriz-2].valor_ataque){
    printf("O melhor ataque possui indice %d e dano %.2f\n",atq[tamanho_da_matriz-2].indice_ataque,atq[tamanho_da_matriz-2].valor_ataque);
  }
  

  /*para liberar a memoria alocada*/
  free(atq);
  free(matriz);
  free(ataque);
  free(tipos);
  return 0;
}