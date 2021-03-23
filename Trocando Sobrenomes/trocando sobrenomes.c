#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct nomes{
  char *nome, *aux, *aux2;
  char *sobrenome;
}nome[1000];

#define READLINE_BUFFER 4096

char *readline(FILE *stream) {
  
  char *string = 0;
  int pos = 0;

	do {
		string = (char *) realloc(string, pos+1000);
		string[pos] = (char) fgetc(stream);
	} while (string[pos++] != '\n' && string[pos] != '\r' && string[pos-1] != '$' && !feof(stdin));
  if(string[pos-1]=='\n' || string[pos-1]=='\r'){
    string[pos-1] = '\0';
  }
	return string;
}

int main(){
  
  struct nomes *nom;
  char aux[100][100];
  int i=0,parada=0,j=0,k=0,a=0, l=1,c=1;

  /*alocar memoria para a struct*/
  nom=(struct nomes*)malloc(10000*sizeof(struct nomes));

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
        /*como o $ vai ser retirado do nome, o tamanho do nome deve diminuir uma posicao*/
        a=strlen(nom->nome);
        parada=1;
      }
    }

    for(j=0; j<1; j++){
      for(k=a;k>0;k--){
        /*para encontra apenas o ultimo espaço e separa o sobrenome*/
        if(nom->nome[k]==' ' && strlen(nom->nome)==a){ 
          *aux[j]='\0';
          
          /*para copiar o sobrenome para uma variavel auxiliar*/
          for(i=k+1; i<=k+1; i++){
            strcpy(aux[c], &nom->nome[i]);
          } 
          
          /*para armazenar o sobrenome na variavel sobrenome da struct*/
          nom[c].sobrenome=aux[c];
          /*para apagar o sobrenome do nome*/
          nom->nome[k]='\0';
          
          /*para armazenar o nome modificado na variavel nome*/
          nom[l].nome=nom->nome;
          /*para poder medir o tamanho do nome e impedir que o loop continue caso o nome seja um nome composto*/
          nom->nome=nom[l].nome;
          l++;
          c++;
        }
      }
    }
  }
  /*para imprmir os nomes com os sobrenomes invertidos*/
  for(i=1; i<l; i++){
    printf("%s %s\n", nom[i].nome, nom[c-1].sobrenome);
    c--;
  }
 
 /*para liberar a memoria alocada*/
  free(nom);
  return 0;
}