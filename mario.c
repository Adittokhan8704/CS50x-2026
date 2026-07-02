#include <cs50.h>
#include <stdio.h>

int main(void)

{

    int n;
    do
    {
        n = get_int("length ");
    }
    while (n < 1 || n > 8);
    for (int i = 0; i < n; i++)
    {
        for (int s = 1; s < n - i; s++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        {
            printf("  ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
