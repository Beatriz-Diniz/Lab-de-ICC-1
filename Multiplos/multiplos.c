#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	int i, j, n;     // dados de entrada                        
    int multi, multj; // multiplos de i e multiplos de j        
    int k;            // conta quantos multiplos foram impressos 
  
  	scanf("%d", &n);
  	scanf("%d %d", &i, &j);
  
   	//inicializacoes 
  	multi = 0;
  	multj = 0;
  
  	for (k = 0; k < n; k++){
     	if (multi < multj){
	 	    printf("%d\n", multi);
	  	   multi = multi + i;
		}
     	else{
	  		printf("%d\n",multj);
	  		if (multi == multj) {
	     		multi = multi + i;
	    	}
	  		multj = multj + j;      
		  }	
    }  
  return 0;
}
