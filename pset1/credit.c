#include <cs50.h>
#include <stdio.h>

int number_length(long n);

int main(void)
{
    // get card number and length
    long number = get_long("Number: ");
    long cc = number;
    int length = number_length(number);

    // return if length is invalid
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // setup the two sums
    int sum1 = 0;
    int sum2 = 0;

    while (number > 0)
    {
        sum1 += number % 10;
        number = number / 10;
    }
}

// gets number of digits in a number
int number_length(long n)
{
    int sum = 0;
    while (n > 0) {
        n = n / 10;
    }

    return sum;
}