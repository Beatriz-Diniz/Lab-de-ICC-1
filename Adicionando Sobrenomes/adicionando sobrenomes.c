#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct nomes{
  char *nome, *aux, *aux2;
  char *sobrenome;
}nome[200];

#define READLINE_BUFFER 4096

char *readline(FILE *stream) {
  
  char *string = 0;
  int pos = 0;

	do {
		string = (char *) realloc(string, pos+1000);
		string[pos] = (char) fgetc(stream);
	} while (string[pos++] != '\n' && string[pos-1] != '$' && !feof(stdin));
  if(string[pos-1]=='\n'){
    string[pos-1] = '\0';
  }
	return string;
}

int main(){
  
  struct nomes *nom;
  char aux[100][100];
  int i=0,parada=0,j=0,k=0,a=0, l=1,c=1;

  /*alocar memoria para a struct*/
  nom=(struct nomes*)malloc(1000*sizeof(struct nomes));

  /*loop para inserir os nomes e separar os sobrenomes*/
  while(parada!=1){       
    /*para inserir o nome*/
    nom[i].nome=readline(stdin);
    /*para ser possivel verificar cada caracter do nome*/
    nom->nome=nom[i].nome;
    
    a=0;
    /*para medir o tamanho do nome*/
    a=strlen(nom[i].nome);
    /*loop para verificar se o $ esta no nome e se estiver
    ele ira parar de inserir os nomes*/
    for(i=0; i<a; i++){
      if(nom->nome[i]=='$'){
        nom->nome[i]='\0';
        i--;
        /*como o $ vai ser retirado do nome, o tamanho do nome deve diminuir uma posicao*/
        a=a-1;
        parada=1;
      }
    }
    
    for(j=0; j<1; j++){
      for(k=a;k>0;k--){
        /*para encontra apenas o ultimo espaço e separa o sobrenome*/
        if(nom->nome[k]==' '){ 
          *aux[j]='\0';
          
          /*para copiar o sobrenome para uma variavel auxiliar*/
          for(i=k+1; i<=k+1; i++){
            strcpy(aux[c], &nom->nome[i]);
          } 
          
          /*para armazenar o sobrenome na variavel sobrenome da struct*/
          nom[c].sobrenome=aux[c];
          
          /*para armazenar o nome inteiro na variavel nome*/
          nom[l].nome=nom->nome;

          l++;
          c++;
          break;
        }
      }
    }
  }

  c=1;
  for(i=1; i<l; i++){
    /*para imprmir os nomes impares*/
    if(i==1 || i==3 || i==5 || i==7 || i==9){
      printf("%s\n", nom[i].nome);
    }
    /*para imprmir os nomes pares com o sobrenome do nome anterior*/
    if(i==2 || i==4 || i==6 || i==8 || i==10){
      printf("%s %s\n", nom[i].nome, nom[c].sobrenome);
      c=c+2;
    }  
  }
 
 /*para liberar a memoria alocada*/
  free(nom);
  return 0;
}