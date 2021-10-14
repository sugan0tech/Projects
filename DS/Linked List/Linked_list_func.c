#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data ;
    struct Node *next;
    
};

// Function returns Struct Node <can be updated with the Head node>
struct Node *create(struct Node *head)
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
        // fron initial value of head
        if(head == NULL)
        {
            head = new;
            temp = head;
        }
        // for non empty head case
        else
        {
            temp->next = new;
            temp = new;
        }
        printf(" Enter the node data :");
        scanf("%d", &n);
    }

    temp = head;
    return temp;
}


struct Node *begining(struct Node *head, int n)
{

    // adding a node as Head
    struct Node *temp, *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = n;
    temp = head;
    head = new;// simple swaping Head.next <-> Head
    head->next = temp;
    return head;
}


void print(struct Node *node)
{
    printf("%d", node->data);
    node = node->next;
    // usual linked list print loop
    while (node != NULL)
    {
        printf(" -> %d", node->data);
        node = node->next;
    }
    printf(" - > NULL");
}


void insert(struct Node *head)
{
    // adding element at a postion
    // value declaration
    struct Node *new, *temp, *pre;
    int n, pos_val;
    // getting values
    printf("\n Enter the num to be inserted :");
    scanf("%d", &n);
    printf("\n Enter the node to be inserted  before :");
    scanf("%d", &pos_val);
    // assigning values
    temp = head;
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
}


void append(struct Node *head)
{
    // declaring
    int n;
    struct Node *new, *temp;
    // getting
    printf("\nEnter the num to be appended :");
    scanf("%d", &n);
    // assigning and memory allotment
    new  = (struct Node *)malloc(sizeof(struct Node));
    new->data = n;
    new->next = NULL;
    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    
}


void delete(struct Node *head, int n)
{
    struct Node *pre, *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            pre->next = temp->next;
            break;
        }
        pre = temp;
        temp = temp->next;
    }
    
}


void main(){

    int choice, n;
    struct Node *Head = NULL;
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
            Head = create(Head);
            break;


        case 2:
            // Printing the LinkedList
            print(Head);
            break;


        case 3:
            // adding element at the begining
            printf("\n Enter the num to be inserted :");
            scanf("%d", &n);
            Head = begining(Head, n);
            break;


        case 4:
            // appending a element
            append(Head);
            break;


        case 5:
            insert(Head);
            break;
            
            
        case 6:
            // removing element 
            printf("\n Enter the num to be deleted :");
            scanf("%d", &n);
            delete(Head, n);
            break;
        }


    } while (choice);


    printf("----*----*----*----*----*----");
    printf("\nThanks for using this code :)\n");
    printf("----*----*----*----*----*----");
    //Done by sugan0tech
    
}