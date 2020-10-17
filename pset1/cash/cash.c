#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_positive_float(void);
float owed;

// Returns the number of coins needed for a certain amount of change
int main(void)
{
    int cents = round(get_positive_float() * 100);
    int counter = 0;
    
    // Loops until nothing is owed
    while (cents > 0)
    {
        if (cents >= 25)
        {
            counter++;
            cents -= 25;
        }
        else if (cents >= 10)
        {
            counter++;
            cents -= 10;
        }
        else if (cents <= 5)
        {
            counter++;
            cents -= 5;
        }
        else
        {
            counter++;
            cents -= 1;
        }
    }

    printf("%i\n", counter);
}

// Gets positive float
float get_positive_float(void)
{
    do
    {
        owed = get_float("Change owed: ");
    }
    while (owed < 0);

    return owed;
}