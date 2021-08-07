#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data ;
    struct Node *next;
    struct Node *prev;
    
};


void main(){

    int choice, n, val, i;
    struct Node *Head = NULL, *new, *temp, *pre;
    printf("1 for creating new Double Linked List \n2 for printing Double Linked List \n3 for adding element to first index \n4 for appending\n5 for adding element at desired place\n6 for deletion");
    do
    {
        printf("\nEnter the option : ");
        /* 1 for creating new Double LinkedList 
           2 for printing Double LinkedList
           3 for adding a element to the begining of the list
           4 for appending an element to the end of tha list
           5 for adding a node before another node
           6 for removing an element
           7 for removing an element at a particular index
        */
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // creation of Double LinkedList
            printf("\n Enter the node data :");
            scanf("%d", &n);
            while (n!=0)
            {
                new = (struct Node *)malloc(sizeof(struct Node));
                new->data = n;
                new->next = NULL;
                new->prev = NULL;
                if(Head == NULL)
                {
                    Head = new;
                    Head->prev = NULL;
                    temp = Head;
                }
                else
                {
                    new->prev = temp;
                    temp->next = new;
                    temp = new;
                }
                printf(" Enter the node data :");
                scanf("%d", &n);
            }
            break;


        case 2:
            // Printing the Double LinkedList
            printf("\n by ascending ");
            temp = Head;
            printf("%d", temp->data);
            temp = temp->next;
            while (temp != NULL)
            {
                printf(" -> %d", temp->data);
                if (temp->next == NULL)
                {
                    pre = temp;
                }
                temp = temp->next;
            }
            printf(" - > NULL");

            printf("\n by desending ");
            temp = pre;
            printf("%d", temp->data);
            temp = temp->prev;
            while (temp != NULL)
            {
                printf(" -> %d", temp->data);
                temp = temp->prev;
            }
            printf(" - > NULL");
            break;


        case 3:
            // adding element at the begining
            temp = Head;
            printf("\n Enter the num to be inserted :");
            scanf("%d", &n);
            new = (struct Node *)malloc(sizeof(struct Node));
            new->data = n;
            temp->prev = new;
            new->next = temp;
            Head = new;
            Head->prev = NULL;
            break;


        case 4:
            // appending a element
            temp = Head;
            printf("\n Enter the num to be append :");
            scanf("%d", &n);
            new = (struct Node *)malloc(sizeof(struct Node));
            new->data = n;
            new->next = NULL;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            new->prev = temp;
            temp->next = new;
            break;


        case 5:
            // adding element at a postion
            temp = Head;
            printf("\n Enter the num to be inserted :");
            scanf("%d", &n);
            printf("\n Enter the node to be inserted  before :");
            scanf("%d", &val);
            new = (struct Node *)malloc(sizeof(struct Node));
            new->data = n;
            new->next = NULL;
            while (temp != NULL)
            {
                // comparing that pos_val to get access to it's previous
                if (temp->data == val)
                {
                    new->prev = pre;
                    temp->prev = new;
                    new->next = temp;
                    pre->next = new;
                    break;
                }
                pre = temp;
                temp = temp->next;
            }
            break;
            

        case 6:
            // removing element 
            temp = Head;
            printf("\n Enter the num to be deleted :");
            scanf("%d", &n);
            while (temp != NULL)
            {
                // comparing that pos_val to get access to it's previous
                if (temp->data == n)
                {
                    pre->next = temp->next;
                    temp->next->prev = pre;
                    break;
                }
                pre = temp;
                temp = temp->next;
            }
            break;

        case 7:
            // removing element at a postion
            temp = Head;
            printf("\n Enter the node to be deleted  ");
            scanf("%d", &val);
            new = (struct Node *)malloc(sizeof(struct Node));
            new->data = val;
            new->next = NULL;
            while (temp != NULL)
            {
                // comparing that val to get deleted
                if (temp->data == val)
                {
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                    break;
                }
                pre = temp;
                temp = temp->next;
            }

            break;


        default:
            break;
        }

    } while (choice > 0);
    printf("----*----*----*----*----*----");
    printf("\nThanks for using this code :)\n");
    printf("----*----*----*----*----*----");
    //Done by sugan0tech
}