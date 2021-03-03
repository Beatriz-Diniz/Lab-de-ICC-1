#include <stdio.h>
#include <math.h>

int main(){
    float a1, q, n, an1, an2, an3;
    double sn1, sn2, sn3, sn4;

    scanf("%f", &a1);
    scanf("%f", &q);
    scanf("%f", &n);

    an1=n-1;
    an2=pow(q, an1);
    an3=a1*an2;

    sn1=pow(q,n);
    sn2=sn1-1;
    sn3=a1*sn2;
    sn4=sn3/(q-1);


    printf("%.2f\n", an3);
    printf("%.2f\n", sn4);

    return 0;
}

