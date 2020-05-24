#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // garbage value
    int x;
    do
    {
        x = get_int("x: ");
        // use condition to check
        // if condition not satisfied --> prompts user again
        if (x >= 1 && x <= 8)
        {
            // need to use nested loops to change both rows + columns
            for (int i = 0; i < x; i += 1)
            {
                // to print left triangles:
                // to print spaces:
                for (int j = 1; j <= x - i - 1; j += 1)
                {
                    printf(" ");
                }
                // to print #:
                for (int k = 1; k <= i + 1; k += 1)
                {
                    printf("#");
                }
                // to print space in between triangles:
                printf("  ");
                // to print right triangles:
                for (int l = 1; l <= i + 1; l += 1)
                {
                    printf("#");
                }
                printf("\n");
            }
        }
    }
    while (x < 1 || x > 8);
}