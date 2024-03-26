#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void){
  //string s = get_string("s: ");
  char *s = get_string("s: ");
  //string t = get_string("t: ");
  char *t = get_string("t: ");

  printf("%p\n", s);
  printf("%p\n", t);

  if(strcmp(s, t) == 0){
    printf("Same\n");
  } else{
    printf("Different\n");
  }
}

//gcc -o compares .\compareString.c .\cs50.c