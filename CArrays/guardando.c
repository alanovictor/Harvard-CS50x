for (int c = 0;  c < length1; c++){  //inicio for
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
    for(int cthree = 0; cthree < 3; cthree++){
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
}// fim for 