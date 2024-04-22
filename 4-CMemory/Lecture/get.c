#include <stdio.h>

int main(void){

  //integer
  int n;
  printf("n: ");
  scanf("%i", &n);
  printf("n: %i\n", n);

  // string
  char *s;
  printf("s: ");
  scanf("%s", s);
  printf("%s\n", s);
}

 //gcc -o get .\get.c .\cs50.c