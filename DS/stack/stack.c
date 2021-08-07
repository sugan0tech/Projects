#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void main()
{
    int choice1;
    printf("Enter 1 for array based implementation, 2 for linked list based implementation ");
    scanf("%d", &choice1);
    // Array based implementation goes here
    if (choice1 == 1)
    {
        printf("Array based implementaion is selected :)");
        int limit, choice2, i;
        i = 0;
        printf("Enter the limit for the stack");
        scanf("%d", &limit);
        int arr[limit];
        do
        {
        printf("Enter the choice :");
        scanf("%d", &choice2);
        switch(choice2)
        {
            case 1:
                printf("Enter the new Top :");
                scanf("%d", &arr[i]);
                i++;
                break;

            case 2:
                printf("Printing the stack ");
                printf("Top\n");
                for (limit = i; limit > 0; limit--)
                {
                    printf("%d \n", arr[limit - 1]);
                }
                break;

            case 3:
                printf("poped the top element ");
                i--;
                break;

        }
        }while(choice2 > 0);

    }


    // Linked List based implementation 
    else if (choice1 == 2)
    {
        printf("Linked List based implementation is selected :)");
        int choice3,n;
        struct Node *Top=NULL,*new,*temp;

        do
        {
            printf("Enter the choice 1 for adding , 2 for printing, 3 for pop");
            scanf("%d", &choice3);

            switch(choice3)
            {
                case 1:
                    printf("\nEnter the num");
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
                    break;

                case 2:
                    printf("Printing The Stack \n");
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
                    printf("Top element is poped ");
                    temp = Top->next;
                    Top = temp;
                    break;

                default:

                    break;
            }
        }while(choice1 > 0);
    }
    

    else
    {
        printf("Invalid choice");
    }
}