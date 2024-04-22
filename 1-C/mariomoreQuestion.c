#include <cs50.h>
#include <stdio.h>

int main(void)
{

int height = get_int("How is the pyramid's height?(1-8) ");

if ((height > 8) || (height < 1)){
while ((height > 8) || (height <1)){
height = get_int("Invalid Number! Write a number between one and eight: ");
}
}




for(int c0 = 1; c0 <= height; c0++)
{
for(int c1 = height - c0; c1 > 0; c1--){
printf(" ");
}
for(int c2=1; c2 <= c0; c2++){
printf("#");
}
printf("  ");
for(int c3=1; c3 <= c0; c3++){
printf("#");
}
printf("\n");
}


}
