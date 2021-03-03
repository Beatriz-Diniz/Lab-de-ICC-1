#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c;

    scanf("%f", &a);
    c = a;


    printf("%d\n",(int) a);
    b=a-((int)a);
    printf("%.4f\n", b);

    if(b>=0.5){
        /*arredondar para cima*/
        printf("%.0f\n", ceil(a));
    }
    else if(b<5){
        /*arredondar para baixo*/
        printf("%.0f\n", floor(a));
    }

    if(b>0){
        printf("%.3f\n", c);
    }
    if(b==0){
        printf("%d\n", (int)c);
    }

    return 0;
}
