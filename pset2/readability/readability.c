#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

float calc_index(string text);
void calc_grade(float index);

// Calculate aprox graded level needed to comprehend some text
int main(void)
{
    string text = get_string("Text: ");
    calc_grade(calc_index(text));
}

// Calculates index
float calc_index(string text)
{
    int count_l = 0;
    int count_w = 1;
    int count_s = 0;

    // Iterates through string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Checks if char is a letter and adds to letter counter
        if (isalpha(text[i]))
        {
            count_l++;
        }
        // Checks if char is a space and adds to word counter
        else if (isspace(text[i]))
        {
            count_w++;
        }
        // Chekcs if char is a ., ! or ? and adds to sentence counter
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_s++;
        }
    }

    return (0.0588 * ((float) count_l / (float) count_w) * 100) - (0.296 * ((float) count_s / (float) count_w) * 100) - 15.8;
}

// Takes index and prints avg grade
void calc_grade(float index)
{
    int rounded = round(index);

    if (rounded < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounded);
    }
}