#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Top, *temp;

void push();
void pop();
void display();

void main()
{
    int opt;
    printf("\n1 for push, 2 for pop, 3 for display ");
    scanf("%d", &opt);
    do
    {
        switch(opt)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid");
                break;
        }
        printf("\n1 for push, 2 for pop, 3 for display ");
        scanf("%d", &opt);
    } while (opt > 0);
    
}

void push()
{
    int n;
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the num :");
    scanf("%d", &n);
    new->data = n;
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
    printf("pushed \n");
}

void pop()
{
    temp = Top;
    Top = temp->next;
    printf("\n popped \n");
}

void display()
{
    temp = Top;
    printf("\n");
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    printf("Done with printing \n");
}