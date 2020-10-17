#include <stdio.h>
#include <cs50.h>

// Prints hello world
int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}