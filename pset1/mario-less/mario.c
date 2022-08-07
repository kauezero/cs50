#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // o
    int height;
    do
    {
        height = get_int("Choose the pyramid's height: ");
    }
    while (height <= 0 || height > 8);

    //loop through the lines
    for (int i = 0; i < height; i++)
    {
        // loops through the spaces
        for (int j = height; j > i + 1; j--)
        {
            printf(" ");
        }

        // loops through the hashes
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}