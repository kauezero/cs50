#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char shift(char c, int k);

int main(int argc, string argv[])
{
    // Return error messages and closes program if argument is not correct
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("The key must contain only digits\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string plain = get_string("plaintext: ");
    string cipher = plain;

    // Iterates through array shifting characters
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        cipher[i] = shift(plain[i], key);
    }

    printf("ciphertext: %s\n", cipher);

}

// Shifts a char c by a key k
char shift(char c, int k)
{
    if (isupper(c))
    {
        int c_int = (int) c - 65;
        int shifted = (c_int + k) % 26;
        return (char) shifted + 65;
    }
    else if (islower(c))
    {
        int c_int = c - 97;
        int shifted = (c_int + k) % 26;
        return (char) shifted + 97;
    }
    else
    {
        return c;
    }
}