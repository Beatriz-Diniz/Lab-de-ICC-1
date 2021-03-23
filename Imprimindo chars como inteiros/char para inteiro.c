#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char *readline(FILE *stream) {
  char *string = NULL;
  int pos = 0;    

  do {
    string = (char *) realloc(string, pos+400);
    string[pos] = (char) fgetc(stdin);
    if(string[pos]=='\n' || string[pos]=='\r' ){  //para ignorara as quebras de linha
      string[pos]='\0';
      pos--;
    }
    pos++;
  }while (string[pos-1] != 'x' && !feof(stdin));  //crtiterio de parada  
  return string;
}

/*fucao para qsort*/
int ordenar_char(const void *string1, const void *string2) {  //funacao para ordenar em ordem alfabetica
   if (*(char*)string1 > *(char*)string2) {
      return 1;
   } else if (*(char*)string1 < *(char*)string2) {
      return -1;
   } else {
      return 0;
   }
}


int main(){

  char *string=0;
  int *inteiro=0, i=0, *tamanho_string=0;

  /*chamar a funcao para inserir os valores*/
  string=readline(stdin);                 
 
  /*alocar memoria para ser usada para armazenar a quantia de strings*/
  tamanho_string=(int*)malloc(10001*sizeof(int));

  /*para calcular o tamanho da string*/
  *tamanho_string=strlen(string);          

  /*funcao qsort para ordenar em ordem alfabetica*/
  qsort(string, *tamanho_string, sizeof(char), ordenar_char);

  /*para coverter char para inteiro*/
  inteiro=(int*) string;              
  for(i=0; i<(*tamanho_string/4); i++){  //loop para imprimir os valores como inteiros
    printf("%d\n",inteiro[i]);
  }

  free(inteiro);
  free(tamanho_string);
  return 0;
}