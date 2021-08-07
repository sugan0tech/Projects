#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data ;
    struct Node *next;
    
};


void push(struct Node* Head)
{
    int n;
    printf("\n Enter the node data :");
    scanf("%d", &n);
    struct Node *new, *temp;
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

}
void print(struct Node* Head)
{
    printf("%d", Head->data);
    Head = Head->next;
    while (Head != NULL)
    {
        printf(" -> %d", Head->data);
        Head = Head->next;
    }
    printf(" - > NULL");

}

void insert(int n, int pos, struct Node* Head)
{

    struct Node *temp, *new, *pre;
    temp = Head;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = n;
    new->next = NULL;
    while (temp != NULL)
    {
        // comparing that pos to get access to it's previous
        if (temp->data == pos)
        {
            new->next = temp;
            pre->next = new;
            break;
        }
    pre = temp;
    temp = temp->next;
    }
}

void main(){

    struct Node *Head1 = NULL, *Head2 = NULL ,*new, *temp, *pre;
    int choice, n, pos, i;
    printf("1 for creating new Linked List \n2 for printing Linked List \n3 for adding element to first index \n4 for appending\n5 for adding element at desired place\n6 for deleting an element");
    do
    {
        printf("\nEnter the option : ");
        /* 2 for creating new LinkedList 
           2 for printing LinkedList
           3 for adding a element to the begining of the list
           4 for appending a element to the end of tha list
           5 for adding a node before another node
           6 for deleing an element
        */
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // creation of LinkedList
            printf("\n Give the data for list 1:");
            push(Head1);
            printf("%d", Head1->data);
            print(Head1);
            break;


        case 2:
            // P1rinting the LinkedList
            printf("\n Give the data for list 2:");
            printf("\n Enter the node data :");
            scanf("%d", &n);
            push(Head2);
            print(Head2);
            break;


        case 3:
            // adding element at the begining
            temp = Head1;
            printf("\n Enter the num to be inserted :");
            scanf("%d", &n);
            new = (struct Node *)malloc(sizeof(struct Node));
            new->data = n;
            new->next = temp;
            Head1 = new;
            break;


        case 4:
            // appending a element
            temp = Head1;
            printf("\n Enter the num to be append :");
            scanf("%d", &n);
            new = (struct Node *)malloc(sizeof(struct Node));
            new->data = n;
            new->next = NULL;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new;
            break;


        case 5:
            // adding element at a postion
            printf("\n Enter the num to be inserted :");
            scanf("%d", &n);
            printf("\n Enter the node to be inserted  before :");
            scanf("%d", &pos);
            insert(n, pos, Head1);
            break;
            
            
        case 6:
            // removing element 
            temp = Head1;
            printf("\n Enter the num to be deleted :");
            scanf("%d", &n);
            while (temp != NULL)
            {
                // comparing that pos to get access to it's previous
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
    //Done by 20EUCS147
    
}