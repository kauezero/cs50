#include <stdio.h>
#include <cs50.h>

bool checksum(long num);
void validation(bool val, long num);

int main(void)
{
    long card = get_long("Card number: ");
    validation(checksum(card), card);
}

// Checks if number is valid credit card
bool checksum(long num)
{
    long sum0 = 0;
    long sum1 = 0;
    long aux = 0;

    // Iterates through the number two at a time
    while (num > 0)
    {
        if (num > 9)
        {
            sum1 += num % 10;

            aux = ((num % 100) / 10) * 2;

            if (aux < 10)
            {
                sum0 += aux;
            }
            else
            {
                sum0 += (aux % 10) + ((aux % 100) / 10);
            }

            num = num / 100;
        }
        else
        {
            sum1 += num % 10;
            num = num / 10;
        }
    }

    long sum = sum0 + sum1;

    return sum % 10 == 0;
}

// Checks brand of credit card;
void validation(bool val, long num)
{
    int count = 2;

    if (val)
    {
        while (num > 99)
        {
            num /= 10;
            count++;
        }
        if (count == 15 && (num == 34 || num == 37))
        {
            printf("AMEX\n");
        }
        else if (count == 16 && (num == 51 || num == 52 || num == 53 || num == 54 || num == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((count >= 13 && count <= 16) && (num >= 40 && num <= 49))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}