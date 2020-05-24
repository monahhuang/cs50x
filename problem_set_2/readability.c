#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // prompt user for text
    string txt = get_string("Text: ");
    
    // set variable - will be used multiple times
    int len = strlen(txt);
    
    // calculate # of characters
    int l = 0;
    for (int i = 0; i < len; i += 1) 
    {
        if (isalnum(txt[i]) != 0)
        {
            l += 1;
        }
    }
    
    // calculate # words by using # spaces
    // cast w as float - converts values to float when calculating Coleman-Liau index
    float w = 1;
    for (int j = 0; j < len; j += 1)
    {
        if (isspace(txt[j]) != 0)
        {
            w += 1;
        }
    }
    
    // calculate # sentences by checking for '.', '?', '!'
    int s = 0;
    for (int k = 0; k < len; k += 1)
    {
        if (txt[k] == '.' || txt[k] == '?' || txt[k] == '!')
        {
            s += 1;
        }
    }
    
    // calculating Coleman-Liau index
    float index = 0.0588 * (l * 100 / w) - 0.296 * (s * 100 / w) - 15.8;
    
    // conditionals for grade
    int n = round(index);
    
    if (n < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (n >= 1 && n <= 16)
    {
        printf("Grade %i\n", n);
    }
    else
    {
        printf("Grade 16+\n");
    }
}