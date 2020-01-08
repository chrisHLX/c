#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define the JPEG header byte
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *infile = NULL;
    if (argv[1] != 0)
    {
        infile = fopen(argv[1], "r");
    }
    else
    {
        printf("Usage: ./recover image\n");
    }

    if (infile == NULL)
    {
        fprintf(stderr, "file does not exist\n");
        return 1;
    }

    // Find the input files size in bytes / sets the address to the end of file
    fseek(infile, 0, SEEK_END);
    int content = ftell(infile);

    // Set address to the start of file
    fseek(infile, 0, SEEK_SET);

    // Allocate memory on the heap for the input files contents, to be stored in buffer
    // Don't forget to free
    BYTE *buffer = malloc(content * sizeof(BYTE));
    if (buffer == NULL)
    {
        fprintf(stderr, "something went wrong");

        fclose(infile);
        return 7;
    }

    // Read the contents of the file
    fread(buffer, sizeof(BYTE), content, infile);

    int count = 0;
    int end = 0;


    for (int i = 0; i < content; i++)
    {
        if (buffer[i] == 0xff && buffer[i + 1] == 0xd8 && buffer[i + 2] == 0xff
            && (buffer[i + 3] & 0xf0) == 0xe0)
        {
            count++;
        }
        else if (buffer[i] == 0xff && buffer[i + 1] == 0xd9)
        {
            end++;
        }
    }

    // Array of addresses
    int start[count];
    int endpoint[end];

    int num = 0;

    for (int i = 0; i < content; i++)
    {
        if (buffer[i] == 0xff && buffer[i + 1] == 0xd8 && buffer[i + 2] == 0xff
            && (buffer[i + 3] & 0xf0) == 0xe0)
        {
            start[num] = i;
        }
        else if (buffer[i] == 0xff && buffer[i + 1] == 0xd9)
        {
            endpoint[num] = i;
            num++;
        }
    }

    // Create the filename and open it for writing
    for (int i = 0; i < num; i++)
    {
        // Size of the image
        int size;

        if (i == num - 1)
        {
            size = content - start[i];
        }
        else
        {
            size = start[i + 1] - start[i];
        }

        // Starting location of the jpeg
        int loc = start[i];

        printf("%i\n", size);

        char filename[7];
        sprintf(filename, "%03i.jpg", i);
        FILE *image = fopen(filename, "w");

        // Write the data to the file
        fwrite(&buffer[loc], sizeof(BYTE), size, image);
        fclose(image);
    }


    printf("\n%i\n", num);
    printf("\nSize of file: %d BYTES\n", content);
    printf("start: %i end: %i\n", start[0], endpoint[0]);

    fclose(infile);
    free(buffer);

}
