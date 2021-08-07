#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data ;
    struct Node *next;
    
};


void main(){

    int choice, n, pos_val, i;
    struct Node *Head = NULL, *new, *temp, *pre;
    printf("1 for creating new Linked List \n2 for printing Linked List \n3 for adding element to first index \n4 for appending\n5 for adding element at desired place\n6 for deleting an element");
    do
    {
        printf("\nEnter the option : ");
        /* 1 for creating new LinkedList 
           2 for printing LinkedList
           3 for adding a element to the begining of the list
           4 for appending a element to the end of tha list
           5 for adding a node before another node
           6 for deleing an  */
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // creation of LinkedList
            printf("\n Enter the node data :");
            scanf("%d", &n);
            while (n!=0)
            {
                new = (struct Node *)malloc(sizeof(struct Node));
                new->data = n;
                new->next = NULL;
                if(Head == NULL)
                {
                    Head = new;
                    temp = Head;
                }
                else
                {
                    temp->next = new;
                    temp = new;
                }
                printf(" Enter the node data :");
                scanf("%d", &n);
            }
            break;


        case 2:
            // Printing the LinkedList
            temp = Head;
            printf("%d", temp->data);
            temp = temp->next;
            while (temp != NULL)
            {
                printf(" -> %d", temp->data);
                temp = temp->next;
            }
            printf(" - > NULL");
            break;


        case 3:
            // adding element at the begining
            // getting 
            printf("\n Enter the num to be inserted :");
            scanf("%d", &n);
            // assignment
            temp = Head;
            new = (struct Node *)malloc(sizeof(struct Node));
            new->data = n;
            new->next = temp;
            Head = new;
            break;


        case 4:
            // appending a element
            //getting
            printf("\n Enter the num to be append :");
            scanf("%d", &n);
            // assignment
            temp = Head;
            new = (struct Node *)malloc(sizeof(struct Node));
            new->data = n;
            new->next = NULL;
            // printing vallues untill Node becomes NULL
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new;
            break;


        case 5:
            // adding element at a postion
            // getting
            printf("\n Enter the num to be inserted :");
            scanf("%d", &n);
            printf("\n Enter the node to be inserted  before :");
            scanf("%d", &pos_val);
            // assignments and allocation
            temp = Head;
            new = (struct Node *)malloc(sizeof(struct Node));
            new->data = n;
            new->next = NULL;
            while (temp != NULL)
            {
                // comparing that pos_val to get access to it's previous
                if (temp->data == pos_val)
                {
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