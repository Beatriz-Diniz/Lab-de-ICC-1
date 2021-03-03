#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
	int i=0, j=0, soma1=0, soma2=0, contador1 = 0, contador2 = 0,a=0,b=0;
	char palavra1[1000] = { '\0' };
	char palavra2[1000] = { '\0' };
	char letra[26] = { '\0' };
	char c;
	c = getchar();

	scanf("%s  %s", palavra1, palavra2);

	switch (c)
	{
	case '1':   //maior palavra
		if (strlen(&palavra1[i]) > strlen(&palavra2[i])) {
			printf("1\n");
		}
		if(strlen(&palavra1[i]) < strlen(&palavra2[i])) {
			printf("2\n");
		}
		if(strlen(&palavra1[i]) == strlen(&palavra2[i])){
		    printf("0\n");  
		}
		break;

	case '2':   //ordem alfabetica
	    palavra1[i]=tolower(palavra1[i]);
	    palavra2[i]=tolower(palavra2[i]);
		if (strcmp(&palavra1[i], &palavra2[i]) < 0) {
			printf("1\n");
		}
		if (strcmp(&palavra1[i], &palavra2[i]) > 0) {
			printf("2\n");
		}
		if (strcmp(&palavra1[i], &palavra2[i]) == 0) {
			printf("0\n");
		}
		break;

	case '3':   //palavra que apresenta maior soma dos valores das letrasa
    i=0;
		while (palavra1[i]!=0) {
      palavra1[i]=tolower(palavra1[i]);
			soma1 += (palavra1[i]-97);
			i++;
		}
    i=0;
		while(palavra2[i] !='\0'){
      palavra2[i]=tolower(palavra2[i]);
			soma2 += (palavra2[i]-97);
			i++;
    }		
			if (soma1 > soma2) {
				printf("1\n");
				break;
			}
			if (soma1 < soma2) {
				printf("2\n");
				break;
			}
			if(soma1==soma2){
			    printf("0\n");
			    break;
			}
		break;

	case '4':   //palavra com mais repetições de uma detreminada letra
		scanf("%s", letra);
		for (i = 0; i < strlen(palavra1); i++) {
			for (j = 0; j < strlen(letra); j++) {
				if (tolower(palavra1[i]) == tolower(letra[j])) {
					contador1++;
				}
			}
		}
		for (i = 0; i < strlen(palavra2); i++) {
			for (j = 0; j < strlen(letra); j++) {
				if (tolower(palavra2[i]) == tolower(letra[j])) {
					contador2++;
				}
			}
		}
		if (contador1 > contador2) {
			printf("1\n");
		}
		if (contador1 < contador2) {
			printf("2\n");
		}
		if (contador1 == contador2) {
			printf("0\n");
		}
		break;

	case'5':   //palavra que aparece determinada letra primeiro
		scanf("%s", letra);
   		do{

        	if (tolower(palavra1[i]) == tolower(letra[j])){
            	printf("1\n");
            	break;
       		 }        
        	if (tolower(palavra2[i]) == tolower(letra[j])){
            	printf("2\n");
            	break;
        	}
        	i++; 
    	} while (palavra1[i] != palavra2[i]); // para palavras coma a letra em posiçoes diferentes
        while(palavra1[i]==palavra2[i]){	//para palavras com a letra na mesma posição
      		a=tolower(palavra1[i]) == tolower(letra[j]);
      		b=tolower(palavra2[i]) == tolower(letra[j]);
      		if(a==b){
        		printf("0\n");
        		break;
      		}
  		}
  		break;
    	while(palavra1[i] == 0 || palavra2[i] == 0){	//para quando a letra não está em nenhuma palavra
    		if(tolower(palavra1[i]) != tolower(letra[j]) && tolower(palavra2[i]) != tolower(letra[j])){
    	    	printf("0\n");
    	    	break;
        	}     
    	} 	
	}
}