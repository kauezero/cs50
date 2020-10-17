#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char shift(char c, char k);

int main(int argc, string argv[])
{
    // Return error messages and closes program if argument is not correct
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("All characters of the key must be alphabetic\n");
            return 1;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    string key = argv[1];
    string plain = get_string("plaintext: ");
    string cipher = plain;

    // Iterates through plain string shifting characters
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isupper(plain[i]))
        {
            cipher[i] = toupper(key[(int) plain[i] - 65]);
        }
        else if (islower(plain[i]))
        {
            cipher[i] = tolower(key[(int) plain[i] - 97]);
        }
        else
        {
            cipher[i] = plain[i];
        }
    }

    printf("ciphertext: %s\n", cipher);

}