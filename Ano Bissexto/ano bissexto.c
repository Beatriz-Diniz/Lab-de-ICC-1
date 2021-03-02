#include "stdio.h"
#include "stdbool.h"
int main(){
    int ano;
    bool bissexto;

    scanf("%d",&ano);

    /*um ano sera bissexto se for divisivel por 400 ou divisivel por 4 e nao ser divisivel por 100*/
    if(ano%400==0){
        bissexto = true;
    }
    else if((ano%4==0) && (ano%100!=0)){
        bissexto=true;
    }
    else{
        bissexto=false;
    }


    if(bissexto==true){
        printf("SIM");
    }
    else{
        printf("NAO");
    }

    return 0;
}
