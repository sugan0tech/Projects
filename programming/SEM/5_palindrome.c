#include <stdio.h>
#include <string.h>

// comparing two string
int main()
{
    char str1[40];
    char str2[40];
    printf("Enter the first string : ");
    scanf("%s", str1);
    printf("Enter the second string : ");
    scanf("%s", str2);
    if (strcmp(str1, str2) == 0)
        printf("strings are same\n");
    else
        printf("strings are not same\n");
    return 0;
}