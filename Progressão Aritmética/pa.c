#include <stdio.h>
#include <math.h>

int main(){
    int a1, r, n, an;
    double sn1, sn2, sn3;

    scanf("%d", &a1);
    scanf("%d", &r);
    scanf("%d", &n);

    an=a1+(n-1)*r;
    sn1= a1+an;
    sn2= sn1*n;
    sn3= sn2/2;

    printf("%d\n", an);
    printf("%.0f\n", sn3);

    return 0;
}
