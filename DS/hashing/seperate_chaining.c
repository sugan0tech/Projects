#include<stdio.h>
#include<stdlib.h>
#define size 10

struct Node 
{
    int data;
    struct Node *next;

};


void print(struct Node *node)
{
    if (node == NULL)
    {
        printf(" NULL");
        exit;
    }
    
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


int hash(int a)
{
    return a%10;
}


void insert(struct Node *arr[], int val)
{
    int key = hash(val);
    struct Node *node, *temp;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    if (arr[key] == NULL) 
    {
        arr[key] = node;
    }
    else if (arr[key] != NULL)
    {
        temp = arr[key];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    
    
}


void main()
{
    int val, key;
    struct Node *hash_table[size], *temp = NULL;
    for (int i = 0; i < size; i++)
    {
        hash_table[i] = NULL;
    }
    
    printf("Enter the val :");
    scanf("%d", &val);
    insert(hash_table, val);
    while(val != -1)
    {
        printf("\nEnter the val :");
        scanf("%d", &val);
        if (val == -1)
        {
            break;
        }
        
        insert(hash_table, val);
    }


    for (int i = 0; i < size; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\nkey :%d | val :NULL", i);
            continue;
        }
        
        printf("\nkey :%d | val :",i);
        print(hash_table[i]);
    }
    
}