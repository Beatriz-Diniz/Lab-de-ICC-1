#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct nomes{
  char nomes[5][50],aux[50];  //matriz de 5 nomes com no maximo 50 caracters cada um e uma variavel auxiliar
  int letra;                  
};

void alocacao_de_memoria(struct nomes *nom){  //alocar memoria para s utilizada 
  nom = (struct nomes*) malloc(sizeof(struct nomes));
}

void receber_nomes(struct nomes *nom){  //função para receber os nomes 
  int i=0, j=0;
  for(i = 0; i < 5; i++){
      j=0;                       
	    do{
        nom->letra = getchar();         //Lê letra da entrada
        nom->nomes[i][j] = nom->letra;  //Coloca a letra lida na string
        j++;                            //Aumenta o indice para ler a proxima letra
	    }while((nom->letra != 10) && (nom->letra != EOF)); //Ler letras até achar o \n (número 10 na tabela ASC II), ou EOF, 
	    nom->nomes[i][j-1] = '\0';        //indicador de fim de arquivo (testes de entrada) que indicam que acabou o nome atual
  }                                     ////Como o ultimo caractere lido não é o '\0', deve ser substituido por '\0', para indicar o fim da string
}

void comparar_strings(struct nomes *nom){            //funçaõ para comparar e colocar os nomes em ordem alfabetica
  int i=0,j=0;
  for(i = 0; i < 5; i++){                            //loop para comparar 5 nomes
		for(j = i; j < 5; j++){
			if(strcmp(nom->nomes[j], nom->nomes[i]) < 0){  //para comparar qual das strings começa com o menor numero de acordo com a tabela ascii
				strcpy(nom->aux, nom->nomes[j]);
				strcpy(nom->nomes[j], nom->nomes[i]);
				strcpy(nom->nomes[i], nom->aux);
			}
		}
	}
}

void imprimir_nomes(struct nomes *nom){  //função para imprimir os nomes em ordem alfabetica 
  int i=0;
  for(i = 0; i < 5; i++){                //loop para imprimir 5 nomes
		printf("%s\n", nom->nomes[i]);
	}
}

int main(){

  struct nomes *nom;
  nom = (struct nomes*) malloc(sizeof(struct nomes));

  receber_nomes(nom);       //para chamar a função receber_nomes
  comparar_strings(nom);    //para chamar a função comparar_strings
  imprimir_nomes(nom);      //para chamar a função imprimir_nomes

  free(nom);                //para liberar a memoria utilizada
  return 0;
}