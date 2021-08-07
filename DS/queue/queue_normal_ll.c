#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node
{
    int data ;
    struct Node *next;
    
};


void main()
{
    struct Node *Rear = NULL, *Front = NULL, *temp, *new;
    int n, option;
    // 1 for creation
    // 2 for enqueue
    // 3 for display
    // 4 for dequeue
    printf("1 for creation\n2 for enqueue\n3 for print\n4 for dequeue");
    printf("\nEnter your option :");
    scanf("%d", &option);
    do
    {
        switch (option)
        {
            case 1:
                printf("\n Enter the num :");
                scanf("%d", &n);
                do
                {
                    new = (struct Node *)malloc(sizeof(struct Node));
                    new->data = n;
                    new->next = NULL;
                    // case for if Front empty
                    if(Front == NULL)
                    {
                        Front = new;
                        Rear = new;
                        temp = Front;
                    }
                    // After test case
                    else
                    {
                        temp->next = new;
                        temp = new;
                        Rear = new;
                    }
                    printf("\n Enter the num :");
                    scanf("%d", &n);
                }while(n  != 0);
                break;


            case 2:
                new = (struct Node *)malloc(sizeof(struct Node));
                printf("\n Enter the num :");
                scanf("%d", &n);
                // enqueueing the data i.e pushing
                new->data = n;
                new->next = NULL;
                Rear->next = new;
                Rear = new;
                break;


            case 3:
                temp = Front;
                // printing using same linked list principle
                while (temp)
                {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("\nFront : %d Rear : %d", Front->data, Rear->data);
                break;


            case 4:
                // dequeueiug just removing the Front one value
                temp = Front;
                Front = temp->next;
                break;


        }
        printf("\nEnter your option :");
        scanf("%d", &option);
    } while (option);


    printf("----*----*----*----*----*----");
    printf("\nThanks for using this code :)\n");
    printf("----*----*----*----*----*----");
    //Done by sugan0tech
    
}