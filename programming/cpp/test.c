#include <stdio.h>
#include <string.h>
int main()
{
    char s[100], s2[100];
    fgets(s, 100, stdin);
    fgets(s2, 100, stdin);
    printf("%d\n", strlen(s));
    printf("%d", strlen(s2));
}