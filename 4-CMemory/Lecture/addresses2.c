#include <cs50.h>
#include <stdio.h>

int main(void)
{
  string s ="HI!"; //s ja é um pointer, é o endereço da string, pois uma string é uma array de characteres
  printf("%p\n", s); // o s ja é um ponteiro então não é necessario a inclusão do & antes
  printf("%p\n", &s); // como o s ja é um ponteiro vai vir um endereço infudado caso coloque o &
  printf("%p\n", &s[0]); // porém s[0] é um charactere, localizando extametne um espaço na memoria, não é um ponteirom, então é necessario utilizar o & comercial
  printf("%p\n", &s[1]);
  printf("%p\n", &s[2]);
  printf("%p\n", &s[3]);

  printf("%p\n", s[0]); // caminho infudado, pois há a necessidade da utilização do & comercial

  //uma string é uma char star = char *s = "HI!"; 

}

//gcc -o ad2 .\addresses2.c .\cs50.c