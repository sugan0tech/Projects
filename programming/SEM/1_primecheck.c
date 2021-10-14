#include <stdio.h>

// to find the prime number
void main()
{
    int num, boo = 1;
    printf("\nEnter the num :");
    scanf("%d", &num);
    if (num == 1)
    {
        printf("\nIt's not a prime number\n");
    }
    else
    {
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                boo = 0;
                printf("\n It's not a prime number \n");
                break;
            }
        }
        if (boo == 1)
        {
            printf("\n It's a prime number \n");
        }
    }
}
