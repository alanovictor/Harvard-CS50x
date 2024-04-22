#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(){

string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

string s = get_string("String: ");
for(int i = 0; i < 6; i++){

// comparação de strings
  if(strcmp(strings[i], s) == 0){
    printf("Found\n");
    return 0;

  }
}

printf("Not found\n");
return 1;
    // gcc -o two .\two.c .\cs50.c
    // pesquisa LINEAR! PESQUISAR UMA COISA DE CADA VEZ..
}