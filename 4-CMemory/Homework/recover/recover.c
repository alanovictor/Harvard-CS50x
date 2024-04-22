#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

// To verify if there is two arguments
 if (argc != 2){
        printf("Invalid number of arguments.\n");
    return 1;
 }


string memorycard = argv[1];
FILE *mc = fopen(memorycard, "r");

// verificar se é possivel abrir o arquivo
  if (mc == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

uint8_t buffer[512]; // 512 numero magico, entender como fazer para captar o tamanho do arquivo




int c_image = 0;


FILE *output = NULL;

char *filename = malloc(8);


while(fread(buffer, 1, 512, mc)){
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            if (c_image > 0){
                fclose(output);
            }

            sprintf(filename, "%03i.jpg", c_image);
            output = fopen(filename, "w");
            c_image++;
        }

        if (output != NULL){
            fwrite(buffer, 1, 512, output);
        }


}


free(filename);
fclose(output);
fclose(mc);
return 0;


//gcc -o recover .\recover.c .\cs50.c
}
