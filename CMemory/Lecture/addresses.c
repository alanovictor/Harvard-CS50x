#include <stdio.h>

int main()
{
  int n = 50;
  int *p = &n; // declarando um pointer (ponteiro) - a estrela esta relacionada com endereço 
  // pode ser escrita int* p , int * p
  printf("%p\n", &n); //  & é o endereço que esta armazenado na memoria - P a variavel que recebeu o endereço

  printf("%p\n", p); //imprimir o endereço através da variavel

  printf("%i\n", *p); // ir para o local da memoria e imprimir o que tem la

}

//gcc -o addresses .\addresses.c .\cs50.c