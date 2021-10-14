#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};

void main()
{
    struct Node *Head1=NULL, *Head2=NULL,*Head3 = NULL, *new, *temp1, *temp2, *temp3;
    int choice, co, pwr;
    printf("\nEnter the coice");
    scanf("%d",&choice);
    do
    {
        switch(choice)
        {
            case 1:
                new = (struct Node *)malloc(sizeof(struct Node));
                printf("\nEnter the coeff of the number");
                scanf("%d", &co);
                printf("\nEnter the power ");
                scanf("%d", &pwr);
                new->coeff = co;
                new->pow = pwr;
                new->next = NULL;
                if (Head1 == NULL)
                {
                    Head1 = new;
                    temp1 = Head1;
                }
                else
                {
                    temp1->next = new;
                    new = temp1;
                }
                break;
            case 2:
                temp1 = Head1;
                printf("\n printing the values");
                while (temp1 != NULL)
                {
                    printf("%d %d->", temp1->coeff, temp1->pow);
                    temp1 = temp1->next;
                }
                printf("NULL");
                break;
        }
        printf("\nEnter the coice");
        scanf("%d",&choice);
    } while (choice);

    printf("\nEnter the coice");
    scanf("%d",&choice);
    do
    {
        switch(choice)
        {
            case 1:
                new = (struct Node *)malloc(sizeof(struct Node));
                printf("\nEnter the coeff of the number");
                scanf("%d", &co);
                printf("\nEnter the power ");
                scanf("%d", &pwr);
                new->coeff = co;
                new->pow = pwr;
                new->next = NULL;
                if (Head2 == NULL)
                {
                    Head2 = new;
                    temp1 = Head1;
                }
                else
                {
                    temp1->next = new;
                    new = temp1;
                }
                break;
            case 2:
                temp1 = Head2;
                printf("\n printing the values");
                while (temp1 != NULL)
                {
                    printf("%d %d->", temp1->coeff, temp1->pow);
                    temp1 = temp1->next;
                }
                printf("NULL");
                break;
        }
        printf("\nEnter the coice");
        scanf("%d",&choice);
    } while (choice);
    
    temp1 = Head1;
    temp2 = Head2;
    while (temp1 != NULL || temp2 != NULL)
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        new->next = NULL;
        if (temp1->pow == temp2->pow)
        {
            new->coeff = temp1->coeff + temp2->coeff;
            new->pow = temp1->pow;
            printf("\n %d, %d", new->coeff, new->pow);
            temp1 = temp1->next;
            temp2 = temp2->next;

        }
        else if (temp1->pow < temp2->pow)
        {
            new->pow = temp1->pow;
            new->coeff = temp1->coeff;
            temp1 = temp1->next;

        }
        else if (temp2->pow < temp1->pow)
        {
            new->pow = temp2->pow;
            new->coeff = temp2->coeff;
            temp2 = temp2->next;

        }
        if (Head3 == NULL)
        {
            Head3 = new;
            temp3 = Head3;
            printf("\nbla%d, %d", Head3->coeff, Head3->pow);
        }
        else
        {
            temp3->next = new;
            temp3 = new;
        }

    }



    temp1 = Head1;
    printf("\n printing the values");
    while (temp1 != NULL)
    {
        printf("%d %d->", temp1->coeff, temp1->pow);
        temp1 = temp1->next;
    }
    printf("NULL");

    temp1 = Head2;
    printf("\n printing the values");
    while (temp1 != NULL)
    {
        printf("%d %d->", temp1->coeff, temp1->pow);
        temp1 = temp1->next;
    }
    printf("NULL");

    temp1 = Head3;
    printf("\n printing the values");
    while (temp1 != NULL)
    {
        printf("%d %d->", temp1->coeff, temp1->pow);
        temp1 = temp1->next;
    }
    printf("NULL");
    
}