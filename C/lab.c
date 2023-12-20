#include <cs50.h>
#include <stdio.h>

int main(void)
{
int startllamas;
int endllamas;
int addedllamas;
int lostllamas;
int years = 0;
startllamas = get_int("Write the initial number of llamas: ");
if(startllamas < 9)
{
    do{
    startllamas = get_int("The initial number wrote will need be equal or lesser than nine, write again: ");
    }
    while (startllamas < 9);
}

endllamas = get_int("Write the llama goal: ");
if(endllamas < startllamas)
{
    do{
    endllamas = get_int("The number of llama goal need to be greater than the initial number of llamas: ");
    }
    while (endllamas < startllamas);
}

for(int c = startllamas; c < endllamas; years++){
addedllamas = c / 3;
lostllamas = c / 4;
c = c + addedllamas - lostllamas;
}

printf("Years: %i\n", years);

    // TODO: Prompt for start size

    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}
