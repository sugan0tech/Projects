#include <stdio.h>

// odd or even finder
void main()
{
    int num;
    printf("\nEnter the num :");
    scanf("%d", &num);
    if (num % 2 == 0)
        printf("\nEven number\n");
    else
        printf("\nOdd number\n");
}