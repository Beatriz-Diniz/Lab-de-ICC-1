#include <stdio.h>
#include<stdlib.h>

int main() {
  
  int **matriz=NULL, **matriz_com_borda, largura=0, altura=0, tamanho_da_borda=0, i=0,j=0, l=0, k=0;

  scanf("%d", &largura);  //para determinar a largura da imagem
  scanf("%d", &altura);   //para determinar a altura da imagem

  /*alocar uma matriz com as medidas da imagem*/
  matriz=(int**)malloc((largura+1)*sizeof(int*));
  for(i=0; i<altura; i++){
    matriz[i]=(int*)malloc(10*sizeof(int));
  }

  /*para preencher a matriz da imagem com valores*/
  for(i=0; i<altura; i++){
    for(j=0; j<largura; j++){
      matriz[i][j]='\0';
      scanf("%d", &matriz[i][j]);
    }
  }
  
  /*para determinar o tamanho da borda da imagem*/
  scanf("%d", &tamanho_da_borda);

  /*alocar uma nova matriz com o tamanho da imagem+borda*/
  matriz_com_borda=(int**)malloc((2*largura+(tamanho_da_borda*2)+1)*sizeof(int*));
  for(i=0; i<altura+(tamanho_da_borda*2); i++){
    matriz_com_borda[i]=(int*)malloc(15*sizeof(int));
  }

  /*para preencer essa nova matriz com 0*/
  for(i=0; i<(tamanho_da_borda*2)+altura; i++){
    for(j=0; j<(tamanho_da_borda*2)+largura; j++){
      matriz_com_borda[i][j]=0;
    }
  }
  /*para colocar os valores da matriz imagem no centro da matriz borda*/
  k=0;
  j=tamanho_da_borda;
    while(j<tamanho_da_borda+largura){
      l=0, i=tamanho_da_borda;
      while(i<tamanho_da_borda+altura){
        matriz_com_borda[i][j]=matriz[l][k];
        l++;
        i++;
      }
    k++;
    j++;
  }

  /*para imprmir a imagem+borda*/
  for(i=0; i<(tamanho_da_borda*2)+altura; i++){ //loop para imprimir a matriz inicial
  j=0;
    while(j<(tamanho_da_borda*2)+largura){
      printf("%d ",matriz_com_borda[i][j]);
      j++;
    } 
    printf("\n");   
  }

  /*para imprmir a imagem sem borda*/
  printf("\n");
  for(i=0; i<altura; i++){ 
    j=0;
    while(j<largura){
      printf("%d ",matriz[i][j]);
      j++;
    }
    printf("\n");
  }
  
  /*para liberar memoria*/
  free(matriz_com_borda);
  free(matriz);
  return 0;
}