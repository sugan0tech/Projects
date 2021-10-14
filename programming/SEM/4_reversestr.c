#include <stdio.h>

// reversing a string
int main()
{
    int size;
    printf("\nEnter the size :");
    scanf("%d", &size);
    char str[size];
    printf("\nEnter the string : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%c", &str[i]);
    }
    printf("\n");

    for (int i = size - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
