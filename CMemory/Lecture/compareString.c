#include <cs50.h>
#include <stdio.h>

int main(void){
  //string s = get_string("s: ");
  char *s = get_string("s: ");
  //string t = get_string("t: ");
  char *t = get_string("t: ");

  if(s == t){
    printf("Same\n");
  } else{
    printf("Different\n");
  }
}

//gcc -o compares .\compareString.c .\cs50.c