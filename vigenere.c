#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Prototypes
int shift(char c);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // Declare new array as key from argv
        int n = strlen(argv[1]);
        int k[n];

        for (int i = 0; i < n; i++)
        {
            if (argv[1][i] >= 'A' && argv[1][i] <= 'z')
            {
                k[i] = shift(argv[1][i]);
            }
            else
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
        // Logic for encryption
        string s = get_string("plaintext:  ");
        int o = strlen(s);
        int r = 0;

        for (int j = 0; j < o; j++)
        {
            if (r >= n)
            {
                r = 0;
            }
            if (s[j] >= 'A' && s[j] <= 'Z' && s[j] + k[r] > 'Z')
            {
                int wrapUP = (s[j] + k[r]) - 90;
                s[j] = 'A' + wrapUP - 1;
                r++;
            }
            else if (s[j] >= 'a' && s[j] <= 'z' && s[j] + k[r] > 'z')
            {
                int wrapLO = (s[j] + k[r]) - 122;
                s[j] = 'a' + wrapLO - 1;
                r++;
            }
            else if (s[j] == ' ')
            {
                s[j] = ' ';
            }
            else if (s[j] < 'A')
            {
                s[j] = s[j];
            }
            else if (s[j] > 'z')
            {
                s[j] = s[j];
            }
            else
            {
                s[j] = s[j] + k[r];
                r++;
            }
        }
        // Return 0 all is well
        printf("ciphertext: %s\n", s);
        return 0;
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}

// Functions
int shift(char c)
{
    if (isupper(c))
    {
        c = c - 65;
    }
    else if (islower(c))
    {
        c = c - 97;
    }
    return c;
}














