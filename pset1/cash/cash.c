#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int calculate_coins(int cents, int coin_value);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{

    // TODO

    int cents;
    do
    {
        cents = get_int("How many cents are owed? ");
    }
    while (cents < 0);

    return cents;
}

int calculate_quarters(int cents)
{
    // TODO
    return calculate_coins(cents, 25);
}

int calculate_dimes(int cents)
{
    // TODO
    return calculate_coins(cents, 10);
}

int calculate_nickels(int cents)
{
    // TODO
    return calculate_coins(cents, 5);
}

int calculate_pennies(int cents)
{
    // TODO
    return calculate_coins(cents, 1);
}

// function that calculates coins, takes value in cents and coin value
int calculate_coins(int cents, int coin_value)
{
    int coin_number = 0;

    while (cents >= coin_value)
    {
        cents = cents - coin_value;
        coin_number++;
    }

    return coin_number;
}