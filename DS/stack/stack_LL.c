#include<stdio.h>
#include<stdlib.h>
#define size 5

struct Node
{
    int data;
    struct Node *next;
};

void main()
{
    int choice, n, check = 0;
    struct Node *Top=NULL,*new,*temp;
    do
    {
        printf("\nEnter the choice 1 for adding , 2 for printing, 3 for pop :");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(check >= 5)
                {
                    printf("\nStack overflow :(\n");
                    break;
                }
                printf("\nEnter the new Top :");
                scanf("%d", &n);
                new = (struct Node *)malloc(sizeof(struct Node));
                new->data = n;
                new->next = NULL;

                if ( Top == NULL)
                {
                    Top = new;
                    temp = Top;
                }

                else
                {
                    new->next = Top;
                    Top = new;
                }
                check++;
                break;


            case 2:
                printf("\nPrinting The Stack \n");
                temp = Top;
                printf("Top\n");

                while (temp != NULL)
                {
                    printf("%d\n", temp->data);
                    temp = temp->next;
                }

                printf("Base\n");
                break;


            case 3:
                if(check <= 0)
                {
                    printf("\nStack in Underflow\n");
                    exit;
                }
                printf("\nTop element is poped");
                temp = Top->next;
                Top = temp;
                check--;
                break;


            default:
                break;
        }

    }while(choice > 0);


}