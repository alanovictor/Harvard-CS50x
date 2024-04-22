#include <stdio.h>
#include <cs50.h>

int main(void)
{
  char c1= 'H';
  char c2= 'I';
  char c3 = '!';

  printf("%i %i %i\n", c1, c2, c3);  // output is how integer


  string s = "HI!";
  printf("%s\n", s);

  printf("%c%c%c\n",s[0], s[1], s[2]);

  s = "HI!";
  string t = "BYE!";

  printf("%s\n", s);
  printf("%s\n", t);

  // if a will want add a string with arrays, with two spaces? 

  string words[2];
  words[0] = "HI!";
  words[1] = "BYE!";

  printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
  printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3];

}