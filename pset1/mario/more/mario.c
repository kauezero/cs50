#include <stdio.h>
#include <cs50.h>

int get_height(void);
void build_pyramid(int h);
int height;

// Builds a pyramid of hashes
int main(void)
{
    build_pyramid(get_height());
}

// Gets height of the pyramid
int get_height(void)
{
    do
    {
        height = get_int("Choose the height of the pyramid: ") ;
    }
    while (height < 1 || height > 8);

    return height;
}

// Builds pyramid
void build_pyramid(int h)
{
    // Iterate through the lines
    for (int i = 0; i < h; i++)
    {
        // Prints spaces height - row times
        for (int k = h; k > (i + 1); k--)
        {
            printf(" ");
        }

        // Iterate through the character
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        // Iterate through the characters of the other side
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}