#include <stdio.h>
int main()
{
    char a;
    scanf("%c", &a);
    char b[50];
    scanf("%s", b);
    char t;
    scanf("%c", &t); //🤔
    char str[100];
    scanf("%[^\n]", str);
    printf("%c \n", a);
    printf("%s \n", b);
    printf("%s", str);
    return 0;
}