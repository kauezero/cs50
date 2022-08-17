#include <cs50.h>
#include <stdio.h>

void print_hashes(int i);

int main(void)
{
    // gets height from user input
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

        print_hashes(i);

        // print spaces
        printf("  ");

        print_hashes(i);

        printf("\n");
    }
}

// prints the number of hashes acording to the line number
void print_hashes(int i)
{
    for (int k = 0; k <= i; k++)
    {
        printf("#");
    }
}