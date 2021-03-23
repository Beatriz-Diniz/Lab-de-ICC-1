#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct nome_completo{
  char nome[500];      //variavel que vai receber o nome completo
  char sobrenome[30];  //variavel que vai receber o sobrenome
};

void alocacao_de_memoria(struct nome_completo *nome){
  nome = (struct nome_completo*) malloc(sizeof(struct nome_completo));  //função para alocar a quantidade de memoria necessaria 
}

void nome_bibliografico(struct nome_completo *nome){  //função para criar o nome bibliografico
  int i=0, j=0, a, c;
  nome->sobrenome[i]='\0';
  scanf(" %[^\r\n]s", &nome->nome[i]);    //para receber o nome completo
  a=strlen(nome->nome);                   //variavel auxiliar que vai receber o tamanho do nome
  for(i=a;i>=0;i--){                      //loop para separar o nome do sobrenome
    if(nome->nome[i]==' '){
      nome->sobrenome[0]=nome->nome[i+1]; //para armazenar cada caracter do nome
      for(j=i+1;j<a;j++){
        nome->sobrenome[c]=toupper(nome->nome[j]);  //para transformar todas as letras o sobrenome em maisculas
          c++;
      }
      if(nome->nome[i]==' '){ //para salvar o restante do nome sem o sobrenome
        nome->nome[i]='\0';
        i--;
      }
      printf("%s, %s",nome->sobrenome, nome->nome);
      break;
    }
  }
}
int main(){

  struct nome_completo *nome;
  nome = (struct nome_completo*) malloc(sizeof(struct nome_completo)*500);

  nome_bibliografico(nome); //para chamar a função nome_bibliografico
  free(nome);               //para liberar a memoria rservada 
  return 0;
}