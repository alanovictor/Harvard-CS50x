#include <stdio.h>

int main()
{
  int n = 50;
  int *p = &n; // declarando um pointer (ponteiro) - a estrela esta relacionada com endereço, significa que estou declarando uma variavel inteira que armazenará um endereço.
  // pode ser escrita int* p , int * p

  printf("%p\n", &n); //  o type p e & é o endereço que esta armazenado na memoria -o %p indica um pointer

  printf("%p\n", p); //imprimir o endereço através da variavel, não precisa do & antes, pois esta variavel ja aponta a localização em sua criação quando foi colocada *p

  printf("%i\n", *p); // diferente o *p acima, este significa que esta dizendo para ir para o local da memoria e imprimir o que tem la, ou seja, o numero que esta no endereço registrado em p.. se fosse só o endereço, ficaria desta vez sem o asterisco *, e o tipo alterado para %p

}

//gcc -o addresses .\addresses.c .\cs50.c