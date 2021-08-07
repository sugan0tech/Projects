#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};
struct Node *Top, *temp;

int opre(char);
void push();
void pop();
void display();

void main()
{
        printf("Linked List based implementation is selected :)");
        int choice3,n;
        struct Node *Top=NULL,*new,*temp;
        n = opre('^');
        printf("%d", n);
        push();
        printf("next\n");
        push();
        printf("next\n");
        push();
        printf("next\n");
        push();
        printf("next\n");
        push();
        printf("printing");
        display();
}

int opre(char ch)
{
    switch(ch)
    {
        case '-':
            return 1;
        case '+':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void push()
{
    printf("push");
    char ni;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the num :");
    scanf("%c", &ni);
    new->data = ni;
    new->next = NULL;
    if (Top == NULL)
    {
        Top = new;
        Top->next = NULL;
    }
    else 
    {
        new->next = Top;
        Top = new;
    }
}

void pop()
{
    temp = Top;
    Top = temp->next;
}

void display()
{
    temp = Top;
    while(temp != NULL)
    {
        printf("\n%c\n", temp->data);
        temp = temp->next;
    }
    printf("Done with printing \n");
}