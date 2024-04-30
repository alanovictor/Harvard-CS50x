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

int *tmp = malloc(4 * sizeof(int));
if(tmp == NULL){
  free(list);  //lembrar de liberar o espaço na memoria, pois ele iria retornar sem liberar = vazamento de memoria
  return 1;
}

for (int i = 0 ; i < 3; i++){
  tmp[i] = list[i];
}
tmp[3] = 4;
free(list);

list = tmp;

  for(int i = 0; i < 4; i++){
    printf("%i\n", list[i]);
  }

  free(list);
  return 0;
}

//gcc -o list .\list.c .\cs50.c