#include <stdio.h>
#include <math.h>

int main(){
    float a,b,c;

    scanf("%f", &a);
    scanf("%f", &b);

    /*a = base
      b = expoente*/
    c=pow(a, b);
    printf("%.4f\n", c);

    return 0;
}
