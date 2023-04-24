#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    char text[1000];
    printf("Text: ");
    fgets(text, 1000, stdin);
    
    int chars = 0;
    int words = 1; // start at 1 to account for the last word
    int sentences = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalnum(text[i]))
        {
            chars++;
        }
        if (isspace(text[i]) && !isspace(text[i-1]))
        {
            words++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    
    float avgletter = (float) chars / (float) words * 100;
    float avgsentence = (float) sentences / (float) words * 100;
    int index = round(0.0588 * avgletter - 0.296 * avgsentence - 15.8);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
