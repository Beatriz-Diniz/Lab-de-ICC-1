#include<stdio.h>
int main()
{
    long int valor;
    scanf("%ld", &valor);
    unsigned char* p = (unsigned char*)&valor;
    printf("%x\n", p[0]); // mostrar o primeiro byte mais significativo
    printf("%x\n", p[1]); // mostrar o segundo byte mais significativo
    printf("%x\n", p[2]); // mostrar o terceiro byte mais significativo
    printf("%x\n", p[3]); // mostrar o quarto byte mais significativo
    printf("%x\n", p[4]); // mostrar o quinto byte mais significativo
    printf("%x\n", p[5]); // mostrar o sexto byte mais significativo
    printf("%x\n", p[6]); // mostrar o setimo byte mais significativo
    printf("%x\n", p[7]); // mostrar o oitavo byte mais significativo
}
