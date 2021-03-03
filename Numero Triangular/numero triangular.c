#include <stdio.h>
#include <math.h>

int main(){
    int n_input = 0;
    float n = 0;

    scanf("%d", &n_input);

    //Isolado n na eq. para determinar o numero triangulo
    n = (sqrt(8 * n_input + 1) - 1) / 2;

    //Caso o valor de n arredondado seja igual a n, entao o numero eh inteiro
    if (floorf(n) == n){
        printf("SIM\n");

        //Para conseguir o proximo, precisamos incrementar n
        n = floorf(n) + 1;
        int prox_triangular = (n * (n + 1)) / 2;

        printf("%d\n", prox_triangular);

        //Verifica se a soma da entrada com o prox_triangular eh quadrado
        float quadrado = (n_input + prox_triangular);
        if (sqrt(quadrado) == floorf(sqrt(quadrado))){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
    }
    else{
        printf("NAO\n");
    }

    return 0;
}
