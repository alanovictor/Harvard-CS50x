#include <stdio.h>
#include <cs50.h>
#include <string.h>

int string_length(string s);

int main(void){
string name = get_string("Name: ");
string lastname = get_string("Last Name: ");
 int length = string_length(name);
 int length2 = strlen(name); // addedd by string.h
 printf("%i\n", length);
 printf("%i\n", length2);
 
}

int string_length(string s){
   int n = 0;
  while (s[n] != '\0'){

    n++;
  }
return n;
}