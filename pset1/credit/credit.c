#include <cs50.h>
#include <stdio.h>

long get_card(void);
int check_sum(long card);
int get_length(long n);
int get_first_digits(long card);

int main(void)
{
    //sets variables
    long card = get_card();
    int card_length = get_length(card);
    int first_digits = get_first_digits(card);


    //number length and first digits logic
    if (check_sum(card) == 1)
    {
        printf("card passes checksum");
        if (card_length == 15 && (first_digits == 34 || first_digits == 37))
        {
            printf("AMEX\n");
        }
        else if (card_length == 16 && (first_digits >= 51 && first_digits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((card_length == 13 || card_length == 16) && (first_digits / 10 == 4))
        {
            printf("VISA\n");
        }
        
        {
            printf("INVALID\n");
        }
    }
    else if (check_sum(card) == 0)
    {
        printf("INVALID\n");
    }
}

//get input card
long get_card(void)
{
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);

    return n;
}

//calculate length of digits in number
int get_length(long card)
{
    int sum = 0;
    while (card > 0)
    {
        card = card / 10;
        sum++;
    }

    return sum;
}

//returns first two digits of number
int get_first_digits(long card)
{
    while (card >= 100)
    {
        card /= 10;
    }

    return card;
}

//calculates checksum
int check_sum(long card)
{

    int counter = 1;
    int sum1 = 0;
    int sum2 = 0;
    int digit;

    while (card > 0)
    {
        digit = card % 10;

        if (counter % 2 == 0)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit / 10) + (digit % 10);
                sum2 += digit;
            }
            else
            {
                sum2 += digit;
            }
        }
        else
        {
            sum1 += card % 10;
        }


        card /= 10;
        counter++;
    }

    if ((sum1 + sum2) % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}