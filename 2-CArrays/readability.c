#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h> // lembrar de arrendodar pontuação para o numero inteiro mais proximo

int main(void){
string length = get_string("Text: ");
string grade;
float words = 1;
float phrases = 0;
float characteres = 0;
float L = 0;
float S = 0;
int index;

for(int c = 0; c < strlen(length); c++) {
  if(isblank(length[c])){
    words += 1;
 
  }
  if((length[c] == '.') || (length[c] == '!') || (length[c] == '?')){
    phrases += 1;

  }
  if(isalpha(length[c])){
    characteres += 1;
  }
}

L = (characteres / words) * 100;
S = (phrases / words) * 100;


index = round((0.0588 * L) - (0.296 * S) - 15.8);


if (index < 1){
grade = "Before Grade 1";
} else if (index <= 2){
  grade = "Grade 2";
}   else if (index <= 3){
  grade = "Grade 3";
}   else if (index <= 4){
  grade = "Grade 4";
}   else if (index <= 5){
  grade = "Grade 5";
}   else if (index <= 6){
  grade = "Grade 6";
}   else if (index <= 7){
  grade = "Grade 7";
}   else if (index <= 8){
  grade = "Grade 8";
}  else if (index <= 9){
  grade = "Grade 9";
}  else if (index <= 10){
  grade = "Grade 10";
}  else {
  grade = "Grade 16+";
}


printf("%s\n", grade);
}
