#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // gets name from user
    string name = get_string("What's your name? ");

    // prints hello, "name"
    printf("hello, %s\n", name);
}