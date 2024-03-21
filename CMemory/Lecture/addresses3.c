#include <stdio.h>

// como uma string é apenas um char star, vamos imprimir uma string sem precisar do include cs50 utilizando o *c
int main(void)
{
  char *s = "HI!";   // e aqui não precisamos do & comercial, por que as aspas de certa maneira ja fazem este papel, o compilador é inteligênte o suficiente para quando ele ver double quotes (aspas) em torno de uma sequência de caracteres, ele deseja colocar o endereço do primeiro caractere na variável para você.
  printf("%s\n", s);
}

//gcc -o ad3 .\addresses3.c .\cs50.c