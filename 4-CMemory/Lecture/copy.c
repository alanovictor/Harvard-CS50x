#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
  char *s = get_string("s: ");
  if (s == NULL){
    return 1;
  }

  // char *t = s;    apenas copiaria o ponteiro da string
  char *t = malloc(strlen(s + 1));  //função malloc, encontrar um numero de bytes aí na memoria para salvar um item.


// no caso de algum numero extra grande, em computador com pouca memoria -- significa que não há memoria suficiente disponível.
  if (t == NULL){ 
    return 1;
  }
  // ______________________________________

  for(int i = 0, n = strlen(s); i <= n; i++){
    t[i] = s[i];
  }

  if(strlen(t) > 0) 
  {
     t[0] = toupper(t[0]);
  }
 

   printf("%s\n", s);
    printf("%s\n", t);

}
 //gcc -o copy .\copy.c .\cs50.c