// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer;
    while(fread(&buffer, sizeof(int16_t), 1, input)){
// Esta função tenta ler um bloco de dados do arquivo de entrada input. Ela recebe quatro argumentos: o endereço de memória onde os dados lidos serão armazenados (&buffer), o tamanho de cada item a ser lido (o tamanho de int16_t, ou seja, 2 bytes), o número de itens a serem lidos (1) e o ponteiro para o arquivo de entrada (input). Se fread conseguir ler com sucesso uma amostra de áudio, ela retornará um valor diferente de zero, caso contrário, retornará zero. while(...): Esta é uma estrutura de loop while que continua executando enquanto a condição dentro dos parênteses for verdadeira. Nesse caso, a condição é o resultado da chamada fread, então o loop continuará enquanto houver amostras de áudio para ler no arquivo de entrada.

        //Uptade volume
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    
    // Update volume: Dentro do loop, a cada iteração, a amostra de áudio lida do arquivo de entrada está armazenada na variável buffer. A linha buffer *= factor; multiplica o valor da amostra de áudio (representada pela variável buffer) pelo fator de escala armazenado na variável factor. Isso aumenta ou diminui o volume da amostra, dependendo do valor do fator de escala. fwrite(&buffer, sizeof(int16_t), 1, output);: Após a atualização do volume da amostra no buffer, essa linha escreve a amostra de áudio atualizada no arquivo de saída output. Ele usa a função fwrite para escrever os dados armazenados no endereço de memória &buffer no arquivo de saída output. O tamanho de cada item a ser escrito é sizeof(int16_t) (2 bytes), o número de itens é 1 e o ponteiro para o arquivo de saída é output.
    }

    // Close files
    fclose(input);
    fclose(output);
}

// o output acaba não gerando o arquivo corretamente com o IDE vs code
//gcc -o volume .\volume.c .\cs50.c