#include<stdio.h>
#include<stdlib.h> // da acesso ao malloc

int main(void){
  // int list[3]; agora vamos usar o malloc
  int *list = malloc(3 * sizeof(int));
  if (list == NULL){
    return 1;
  }

  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  for(int i = 0; i < 3; i++){
    printf("%i\n", list[i]);
  }
}

//gcc -o list .\list.c .\cs50.c