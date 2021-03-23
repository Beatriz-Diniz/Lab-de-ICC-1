#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct movimentos{

	int posicaoX, posicaoY, linha, coluna, base_coordenadaX, base_coordenadaY;
	double movimento, distancia;
};

void alocacao_de_memoria(struct movimentos *mov){	//alocar mememoria

	mov = (struct movimentos*) malloc(sizeof(struct movimentos));
}

void instrucoes(struct movimentos *mov){	//função para receber as intruções

	scanf("%d %d", &mov->linha, &mov->coluna);								//receber a quantia de linhas e colunas
	scanf("%d %d %lf", &mov->posicaoX, &mov->posicaoY, &mov->movimento);	//receber as coordenadas da posição do jogador e
}																			//a quantia de movimentos possiveis

void ler_matriz(struct movimentos *mov){	//função para ler e preencher a matriz, buscar e salvar as coordenadas da base

	int tabuleiro[mov->linha][mov->coluna];	//variavel para ser o tabuleiro do jogo
	int i=0, j=0;							//variavies auxiliares

	for (i = 0; i < mov->linha; i++) {		//loop para preencher o tabuleiro
		for (j = 0; j < mov->coluna; j++) {
			scanf("%d", &tabuleiro[i][j]);
		}
	}
	for (i = 0; i < mov->linha; i++) {		//loop para salvar as coordenadas da base
		for (j = 0; j < mov->coluna; j++) {
			if(tabuleiro[i][j] == 1) {
				mov->base_coordenadaX = i;
				mov->base_coordenadaY = j;
			}
		}
	}
}

void distancia_euclidiana(struct movimentos *mov){	//funcao para calcular a distancia euclidiana(distancia entre dois pontos)

  	mov->distancia = (mov->posicaoX - mov->base_coordenadaX) * (mov->posicaoX - mov->base_coordenadaX);
	mov->distancia += (mov->posicaoY - mov->base_coordenadaY) * (mov->posicaoY - mov->base_coordenadaY);
	mov->distancia = sqrt(mov->distancia);	//para calcular a raiz quadrada
}

void resultado(struct movimentos *mov){	 //função para calcular e imprimir o resultado

  if (mov->distancia > mov->movimento) { //se a distancia entre o jogador e a base for maior que a quantia de movimentos 
		printf("Game Over!");			 //o jogador terá perdido
	} else {							 //se a distancia entre o jogador e a base for menor ou igual a quantia de movimentos
		printf("Voce escapou!");		 //o jogador irá ganhar
	}
}

int main(){

  struct movimentos *mov;
  mov = (struct movimentos*) malloc(sizeof(struct movimentos));
  instrucoes(mov);
  ler_matriz(mov);
  distancia_euclidiana(mov);
  resultado(mov);
  free(mov);
  return 0;
}