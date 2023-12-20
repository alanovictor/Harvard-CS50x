#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long numberCard;
    numberCard = get_long_long("Write a correct number card here: ");
    int sum = 0;
    int mult = 0;
    int master = numberCard / 100000000000000;
    for(long long c0 = numberCard; c0 > 1;){
        c0 = c0 / 10;
        mult = (c0 % 10) * 2;
         if(mult > 9){
            sum = sum + (mult / 10);
            sum = sum + (mult % 10);
        } else{
            sum = sum + mult;
        }
        c0 = c0 / 10;
    }

    for(long long c1 = numberCard; c1 > 1; c1 = c1 / 100){
        sum = sum + (c1 % 10);
    }

    if(((sum % 10) == 0) || ((sum % 100) == 0)){
        if(((numberCard / 1000000000000) == 4) || ((numberCard / 1000000000000000) == 4)){
            printf("VISA\n");
        } else if(((numberCard / 10000000000000) == 34) || ((numberCard / 10000000000000) == 37)){
            printf("AMEX\n");
        } else if((master == 51) || (master == 52) || (master == 53) || (master == 54) || (master == 55)){
            printf("MASTERCARD\n");
        } else{
            printf("INVALID\n");
        }

    } else{
        printf("INVALID\n");
    }

    }


