#include <cs50.h>
#include <stdio.h>

int main(void)
{
  for (int i = 0; i<4; i++)
  {
    printf("?");
  }
  printf("\n");
  for (int i = 0; i<4; i++)
  {
    printf("#\n");
  }
    int n = get_int("Size: ");
    while (n < 1) 
    {
      printf("Invalid information, type again!");
      n = get_int("Size: ");
    }
    for (int i = 0; i < n; i++)
  {
      for(int j = 0; j < n; j++)
      {
        printf("#");
      }
      printf("\n");
  }
  
  n = 0;
  n = get_int("Size: ");
    do
    {
      n = get_int("Size: ");
    }
    while(n < 1);

// Print grid of bricks

    for (int i = 0; i < n; i++)
  {
      for(int j = 0; j < n; j++)
      {
        printf("#");
      }
      printf("\n");
  }
  
}