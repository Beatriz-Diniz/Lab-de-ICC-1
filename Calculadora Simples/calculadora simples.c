#include "stdio.h"

int main(){
    float n1, n2;
    char oper;

    scanf("%f %c %f", &n1, &oper, &n2);

    switch(oper){
        case'+':
            printf("%f\n", n1+n2);
            break;
        case'-':
            printf("%f\n", n1-n2);
            break;
        case'*':
            printf("%f\n", n1*n2);
            break;
        case'/':
            printf("%f\n", n1/n2);
            break;
        case'%':
            printf("%f\n", ((n1/n2)*100));
    }
    return 0;
}
