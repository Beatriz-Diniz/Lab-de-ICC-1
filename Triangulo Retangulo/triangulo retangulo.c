#include <stdio.h>
#include <math.h>

int main(){

    int n1, n2, n3;
    int a, b,c;

    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);

    a=n1*n1;
    b=n2*n2;
    c=n3*n3;

    if(n1>n2 && n1>n3 && n1*n1==b+c){
       printf("SIM");
    }else if(n2>n1 && n2>n3 && n2*n2==a+c){
        printf("SIM");
    }else if(n3>n1 && n3>n2 && n3*n3==a+b){
        printf("SIM");
    }else
        printf("NAO");
   
   return 0;
}
