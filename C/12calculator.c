#include <cs50.h>
#include <stdio.h>

int main(void)
{
  long long x = get_long("x: ");
  long long y = get_long("y: ");

  printf("%lld\n", x + y);
  // long long para valores muito altos, somente o long não funcionou... li para long, e lld para long long


  x = get_long("x: ");
  y = get_long("y: ");
  float z = (float) x / (float) y;
    printf("%f\n", z);
    // divisão - float


  x = get_long("x: ");
  y = get_long("y: ");
  double h = (double) x / (double) y;
    printf("%.20f\n", h);
    //show a limited amount of numbers

}





