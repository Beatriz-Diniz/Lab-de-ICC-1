#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char *readline(FILE *stream) {  //função para receber os valores
  
  char *string = 0;
  int pos = 0;    

  do {
    int q = pos / 5000 + 1;
    string = (char *) realloc(string, q * 5000);
    string[pos] = (char) fgetc(stream);
  }while (string[pos++] != '\n' && !feof(stdin));
  string[pos-1] = '\0';
  
  return string;
}

int quantidade_de_espacos(char *texto){ //função para calcular a quantidade de substrings que vai ter e ser utilizada na opção 2
    
    int espacos = 0;
    while(*texto){
        if (*texto == ' '){
           espacos++;
        }
        texto++;
    }
    return espacos;
}

void opcao1(char *texto){                 //função para imprimir as strings em substrings
  
  const char quebra[2] = " ";             //variavel para determinar onde deve ocorrer a quebra da string
  char *texto_quebrado;                   //variavel que vai receber a string repartida em varias e subtring
   
  texto_quebrado = strtok(texto, quebra); //para ocorer a quebra da string
  
  while( texto_quebrado != NULL ) {
      
    printf("%s\n", texto_quebrado );      //para imprimir as subtrings
    texto_quebrado = strtok(NULL, quebra);
  }
}

void opcao2(char *texto){             //função para imprimir a string em substrings em ordem alfabetica
  
  for(int i=0; i<strlen(texto); i++){ //para deixar todas as letras minusculas
    texto[i]=tolower(texto[i]);
  }
  
  const char quebra[2] = " ";                                   //variavel para determinar onde deve ocorrer a quebra da string
  char *texto_quebrado, aux[100];                               //variavel que vai receber a string repartida em varias e subtring e variavel auxiliat
  int quantidade_de_strings = quantidade_de_espacos(texto) + 1; //variavel auxilar que vai determinar o numero de subtrings
  char strings[quantidade_de_strings][strlen(texto)];           //variavel que vai receber as subtrings
  int i=0, j=0, k=0;
  
  texto_quebrado = strtok(texto, quebra);    //para ocorer a quebra da string
  while( texto_quebrado != NULL ) {
    strcpy(strings[i++], texto_quebrado);    //para amarzenar em uma posição do vetor o texto que aparece antes da quebra
    texto_quebrado = strtok(NULL, quebra);
  }
  for (i = 0; i < quantidade_de_strings; i++) {  //para colocar as subtrings em ordem alfabetica
    for (j = i+1; j < quantidade_de_strings; j++) {
      k=strcmp(strings[i], strings[j]);
      if (k>0) {
        strcpy(aux, strings[i]);
        strcpy(strings[i], strings[j]);
        strcpy(strings[j], aux);
      }
    }
  }
  for(i=0; i<quantidade_de_strings; i++){
    printf("%s\n", strings[i]);
  }

}

int main(){
  
  char *texto=readline(stdin);    //para inserir a frase
  char *operacao=readline(stdin); //para escolher a opcao
  
  switch (*operacao){
    
    case '1':
      opcao1(texto);  //para realizar a opcao de imprimir a string em substring
      break;
    
    case '2':
      opcao2(texto);  //para realizar a opcao de imprimir a string em substring em ordem alfabetica
  }

  return 0;
}