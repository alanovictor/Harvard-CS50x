#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>


string one = "AEIOULMRST";
string two = "DG";
string three = "BCMP";
string four = "FHVWY";
string five = "K";
string eight = "JX";
string ten = "QZ";
int points1 = 0;
int points2 = 0;

int main(void)
{
string player1 = get_string("Player 1: ");
string player2 = get_string("Player 2: ");
int length1 = strlen(player1);
int length2 = strlen(player2);

for (int c = 0;  c < length1; c++){  //start for 1
  for(int cone = 0; cone < 10; cone++){
    if(toupper(player1[c]) == one[cone]){
      points1 += 1;
    }
  }
for(int ctwo = 0; ctwo < 2; ctwo++){
      if(toupper(player1[c]) == two[ctwo]){
      points1 += 2;
      }
    }
    for(int cthree = 0; cthree < 4; cthree++){
      if(toupper(player1[c]) == three[cthree]){
      points1 += 3;
      }
    }
    for(int cfour = 0; cfour < 5; cfour++){
      if(toupper(player1[c]) == four[cfour]){
      points1 += 4;
      }
    }
    for(int cfive = 0; cfive < 1; cfive++){
      if(toupper(player1[c]) == five[cfive]){
      points1 += 5;
      }
    }
    for(int ceight = 0; ceight < 2; ceight++){
      if(toupper(player1[c]) == eight[ceight]){
      points1 += 8;
      }
    }
    for(int cten = 0; cten < 2; cten++){
    if(toupper(player1[c]) == ten[cten]){
      points1 += 10;
    }
  }
}// end for 1

for (int c = 0;  c < length2; c++){  //start for 2
  for(int cone = 0; cone < 10; cone++){
    if(toupper(player2[c]) == one[cone]){
      points2 += 1;
    }
  }
for(int ctwo = 0; ctwo < 2; ctwo++){
      if(toupper(player2[c]) == two[ctwo]){
      points2 += 2;
      }
    }
    for(int cthree = 0; cthree < 4; cthree++){
      if(toupper(player2[c]) == three[cthree]){
      points2 += 3;
      }
    }
    for(int cfour = 0; cfour < 5; cfour++){
      if(toupper(player2[c]) == four[cfour]){
      points2 += 4;
      }
    }
    for(int cfive = 0; cfive < 1; cfive++){
      if(toupper(player2[c]) == five[cfive]){
      points2 += 5;
      }
    }
    for(int ceight = 0; ceight < 2; ceight++){
      if(toupper(player2[c]) == eight[ceight]){
      points2 += 8;
      }
    }
    for(int cten = 0; cten < 2; cten++){
    if(toupper(player2[c]) == ten[cten]){
      points2 += 10;
    }
  }
}// end for 2

if (points1 > points2)
  {
  printf("Player 1 wins!\n");
  } else if(points1 < points2){
      printf("Player 2 wins!\n");
  } else{
      printf("Tie!\n");
  }

}
