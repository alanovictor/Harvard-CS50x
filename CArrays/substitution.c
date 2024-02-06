#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h> 
int norepeat(string s);
int isitalpha(string s);


int main(int argc, string argv[]){
if (argc != 2) { 
  printf("Error");
  return 1;
}

string cipher = argv[1];
int step1 = norepeat(argv[1]);
int step2 = isitalpha(argv[1]);
int l = strlen(argv[1]);
string plaintext;
string ciphertext;
int ascii;

if ((step1 == 1) || (strlen(argv[1]) != 26) || (step2 == 1)) { 
  printf("Error");
  return 1;
}

plaintext = get_string("plain text: ");
ciphertext = plaintext;


for (int c = 0; c < strlen(plaintext); c++){
  ascii = 0;
  if(isalpha(ciphertext[c])){
    for(int c2 = tolower(ciphertext[c]); c2 >= 97; c2--){
      ascii++;
    }
    if (isupper(plaintext[c])){
      ciphertext[c] = tolower(cipher[ascii - 1]) - 32;
    }else{
     ciphertext[c] = tolower(cipher[ascii - 1]);
    }
  
  }

}
 printf("ciphertext: %s\n", ciphertext);
return 0;
}


// Functions

//norepeat
int norepeat(string s){
  int l = strlen(s);
  for (int c1 = 0; c1 < l; c1++){
    for(int c2 = c1+1; c2 < l; c2++){
        if (tolower(s[c1]) == tolower(s[c2])){
          return 1;
        }
    }
  }
  return 0;
}

//isalpha
int isitalpha(string s){
  int l = strlen(s);
  int alpha = 0;
  for (int c = 0; c < l; c++){
    if (isalpha(s[c])){
      alpha++;
    }
  }
    printf("%i\n", alpha);
  if (alpha != 26){
    return 1;
  } else{
    return 0;
  }

}
