#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data ;
    struct Node *next;
    
};

void main()
{
    // declarations
    struct Node *Rear = NULL, *Front = NULL, *temp, *new;
    int n, option;

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

                    if(Front == NULL)
                    {
                        Front = new;
                        Rear = new;
                        temp = Front;
                    }
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
                //getting
                printf("\n Enter the num :");
                scanf("%d", &n);
                // assignment and allocation
                new = (struct Node *)malloc(sizeof(struct Node));
                new->data = n;
                new->next = NULL;
                Rear->next = new;
                Rear = new;
                break;


            case 3:
                temp = Front;
                while (temp)
                {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("\nFront : %d Rear : %d", Front->data, Rear->data);
                
                break;


            case 4:
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