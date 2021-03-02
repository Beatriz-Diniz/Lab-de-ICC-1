#include <stdio.h>
#include <math.h>

float distancia(float xa, float ya, float xb, float yb){
    float x = pow(xa - xb, 2);
    float y = pow(ya - yb, 2);
    return sqrtf(x + y);
}

int main(){
    
    float xa, ya, xb, yb, distance = 0;
    int n;

    scanf("%d", &n);

    //Recebe o primeiro ponto
    scanf("%f %f", &xa, &ya);

    for (int i = 1; i < n; i++){
        scanf("%f %f", &xb, &yb);

        //Soma a distancia
        distance += distancia(xa, ya, xb, yb);

        //Troca os pontos para receber o proximo
        xa = xb;
        ya = yb;
    }

    printf("%.4f\n", distance);

    return 0;
}
