#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void ler_matriz(int *posicao1, int *posicao2, int *posicao_da_mistura, int matriz[6][3]){ //funcao para ler a matriz

  int linha, coluna;

  scanf("%d %d %d", &*posicao1, &*posicao2, &*posicao_da_mistura);  /*para receber os valores que serao as coordenadas para das cores que 
                                                                    serao misturadas e a coordenada de onde a mistura vai ser armazenada*/
  for(linha=0; linha<6; linha++){ //loop para preencher a matriz
    for(coluna=0; coluna<3; coluna++){
      scanf("%d",&matriz[linha][coluna]);
    }
  }
}

//funcao para realizar a mistura das cores
void misturar_cores(int posicao1, int posicao2, int posicao_da_mistura, int matriz[6][3], int matriz_nova[6][3]){

  int linha, coluna;
   
  for(linha=0; linha<6; linha++){ //para loop criar a matriz que vai imprimir a matriz com resultados
    for(coluna=0; coluna<3; coluna++){
      matriz_nova[linha][coluna]=matriz[linha][coluna];
    }
  }

  if(posicao1>=0 && posicao1<=6){ //loop para fazer as misturas das cores e armazenar na coordenada inserida
    
    matriz_nova[posicao_da_mistura][0]=(matriz[posicao1][0])/2+(matriz[posicao2][0])/2;
    
    if(matriz[posicao1][1]%2!=0){ //para quano o valor de divisao nao e exato e poder arredondar para cima
      matriz_nova[posicao_da_mistura][1]=((matriz[posicao1][1]/2)+(matriz[posicao2][1])/2)+1;
    }
    
    if(matriz[posicao1][1]%2==0){ //para quando o valor da divisao é exato
      matriz_nova[posicao_da_mistura][1]=(matriz[posicao1][1])/2+(matriz[posicao2][1])/2;
    }
    
    if(matriz[posicao1][1]==0 || matriz[posicao2][1]==0){ //para quando uma das linhas tiverem valor igual a 0
      matriz_nova[posicao_da_mistura][1]=((matriz[posicao1][1])+(matriz[posicao2][1]))-1;
    }
    
    if(matriz[posicao1][1]>matriz[posicao2][1]){  //para quando o valor da linha 1 for maior que o da linha 2
      matriz_nova[posicao_da_mistura][1]=matriz[posicao1][1];
    }
    matriz_nova[posicao_da_mistura][2]=(matriz[posicao1][2])/2+(matriz[posicao2][2])/2;

    
    if(matriz_nova[posicao_da_mistura][0]>255){ //para o valor da cor nao passar de 255
      matriz_nova[posicao_da_mistura][0]=255;
    }
    if(matriz_nova[posicao_da_mistura][1]>255){ //para o valor da cor nao passar de 255
      matriz_nova[posicao_da_mistura][1]=255;
    }
    if(matriz_nova[posicao_da_mistura][2]>255){ //para o valor da cor nao passar de 255
      matriz_nova[posicao_da_mistura][2]=255;
    }
  }

}

//funcao para imprimir as matrizes
void imprimir_matriz(int posicao1, int posicao2, int posicao_da_mistura, int matriz[6][3], int matriz_nova[6][3]){ 
  int linha, coluna, cor=0;

  printf("Start:\n"); 
  for(linha=0; linha<6; linha++){ //loop para imprimir a matriz inicial
    coluna=0;
    printf("Color(%d): [\t%d\t%d\t%d\t]\n",cor, matriz[linha][coluna], matriz[linha][coluna+1], matriz[linha][coluna+2]);
    cor++;
  }

  cor=0;
  printf("\nResult:\n");
  for(linha=0; linha<6; linha++){ //loop para imprimir a matriz depois da mistura
    coluna=0;
    printf("Color(%d): [\t%d\t%d\t%d\t]\n",cor, matriz_nova[linha][coluna], matriz_nova[linha][coluna+1], matriz_nova[linha][coluna+2]);
    cor++;
  }
}

int main(void) {
  
  int posicao1=0, posicao2=0, posicao_da_mistura=0;
  int matriz[6][3], matriz_nova[6][3];

  ler_matriz(&posicao1, &posicao2, &posicao_da_mistura, matriz);                //para chamar a funcao que insere os valores
  
  misturar_cores(posicao1, posicao2, posicao_da_mistura, matriz, matriz_nova);  //para chamar a funcao que realiza a mistura
  
  imprimir_matriz(posicao1, posicao2, posicao_da_mistura, matriz, matriz_nova); //para chamar a funcao que imprime as matrizes
  return 0;
}