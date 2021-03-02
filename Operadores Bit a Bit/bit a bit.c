#include <stdio.h>

int main(void) {

  int a;
  int b;


  scanf("%d", &a);
  scanf("%d", &b);

  if (a < 0 || b < 0){
    printf("Erro \n");
    return 0;
  }
  
  // and
  printf("%d\n", a & b);
  // or
  printf("%d\n", a | b);
  // exclusive (xor)
  printf("%d\n", a ^ b);
  // complement a
  printf("%d\n", ~a);
  // complement b
  printf("%d\n", ~b);
  //dloc direita
  printf("%d\n", a >> 2);
  //dloc esquerda
  printf("%d\n", b << 2);

  return 0;
}
