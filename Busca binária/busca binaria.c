#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct valor{ 
  int n;      //n = quantia de valores que serão inseridos
  int chave;  //chave = elemento que deve ser buscado no vetor
  int vetor[100]; //vetor = valores que irão compor o vetor
};

void leitura(struct valor *val){  //função que vai receber os valores
 
  int i;
  
  scanf("%d", &val->n);
  scanf("%d", &val->chave);
 
  for(i=0; i<val->n; i++){  //loop para preencer o vetor
    scanf("%d", &val->vetor[i]);
  }
}

void bubble_sort (struct valor *val) {  //função que vai ordenar os elemetos dos vetores
  int k, i, aux;
  for (k = 1; k < val->n; k++) {        //loop para comprar os vetores e organizar os valores em ordem crescente
    for (i = 0; i < val->n - 1; i++) {
      if (val->vetor[i] > val->vetor[i + 1]) {
        aux = val->vetor[i];
        val->vetor[i] = val->vetor[i + 1];
        val->vetor[i + 1] = aux;
      }
    }
  }
}

void busca_binaria(struct valor *val){  //função que vai realizar a busca binaria
  int inicio = 0;
  int fim = val->n - 1;
  int meio;
  int controle_pesquisa = 1;

  
  while (inicio <= fim){                    // Loop que ira realizar a pesquisa binaria 
    meio = (inicio + fim) / 2;              // Obtem o valor do meio do vetor 
      if (val->chave == val->vetor[meio]){  // Verifica se o valor foi encontrado 
        controle_pesquisa = 0;
        break;
      }              
      else if (val->chave < val->vetor[meio]){ //Se a pesquisa for menor que o meio do vetor, entao o fim do vetor sera o meio atual -1
        fim = meio - 1;
        continue;
      }        
      else if(val->chave > val->vetor[meio]){ //Se a pesquisa for maior que o meio do vetor, entao a pesquisa comecara 
        inicio = meio + 1;                    //a partir do meio atual atual do vetor
        continue;
      }
      else{ //Se o valor não for encontrado define o controle_pesquisa = 1
        controle_pesquisa = 1;
        break;
      }  
    }
        
    if (controle_pesquisa == 0){   //Se a variavel controle_pesquisa for igual a 0, entao o elemento foi encontrado
      printf("%d\n",meio);    
    } else {
      printf("Chave inexistente\n");
    }
}

int main(){
  
  struct valor *val;
  val=(struct valor*)malloc(sizeof(struct valor));
  
  leitura(val); //chamar a função para receber as entradas 
  bubble_sort(val);//chamar a função para ordenar os valores
  busca_binaria(val); //chamar a função para realizar a busca binaria
  
  free(val);
  return 0;
}