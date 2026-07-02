#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float count_letters(string text, int str_length);
float count_words(string text, int str_length);
float count_sentences(string text, int str_length);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    int length = strlen(text);

    // Count the number of letters, words, and sentences in the text
    float letters = count_letters(text, length);
    float words = count_words(text, length);
    float sentences = count_sentences(text, length);

    // Compute the Coleman-Liau index
    float L = round((100 / words) * letters);
    float S = round((100 / words) * sentences);

    float index = (0.0588 * L - 0.296 * S - 15.8);
    index = round(index);

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", (int) index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
float count_letters(string text, int str_length)
{
    // Return the number of letters in text
    int letters = 0;
    for (int i = 0; i < str_length; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
    }
    return letters;
}
float count_words(string text, int str_length)
{
    // Return the number of words in text
    int words = 0;
    for (int i = 0; i < str_length; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }
    words++;
    return words;
}

float count_sentences(string text, int str_length)
{
    // Return the number of sentences in text
    int sentences = 0;

    for (int i = 0; i < str_length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
