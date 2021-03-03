#include<stdio.h>
#include <math.h>

int main(){
    long double a, b, c, d;
    long double media;

    scanf("%Lf", &a);
    scanf("%Lf", &b);
    scanf("%Lf", &c);
    scanf("%Lf", &d);

    /*se a menor nota for o a*/
    if(a<=b && a<=c && a<=d){
        media=((b+c+d)/3);
        printf("%.4Lf\n", media);

    /*se a menor nota for o b*/
    }else if(b<=a && b<=c && b<=d){
        media=((a+c+d)/3);
        printf("%.4Lf\n", media);

    /*se a menor nota for o c*/
    }else if(c<=a && c<=b && c<=d){
        media=((a+b+d)/3);
        printf("%.4Lf\n", media);

    /*se a menor nota for o d*/
    }else if(d<=a && d<=b && d<=c){
        media=((a+b+c)/3);
        printf("%.4Lf\n", media);

    }
    return 0;
}
