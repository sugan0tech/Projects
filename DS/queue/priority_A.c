#include<stdio.h>
#include<stdlib.h>

// node formation here it have additional data of priority value
struct Node
{
    int data;
    int priority;
    struct Node *next;
};


void main()
{
    struct Node *Front=NULL,*Rear=NULL,*temp,*new;
    int choice,element,priority;
    do
    {
        printf("\n1 Insertion\n2 Deletion\n3 DIsplay");
        printf("\nEnter the choice :");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                // getting
                printf("Enter the data:");
                scanf("%d",&element);
                printf("Enter the priority:");
                scanf("%d",&priority);
                // assignments and allocations
                new=(struct Node*)malloc(sizeof(struct Node));
                new->data=element;
                new->priority=priority;
                new->next=NULL;

                if(Front==NULL)
                {
                    Front  = new;
                    Rear = Front;
                }
                else
                {
                    if(new->priority > Front->priority)
                    {
                        Front->next = new;
                        Rear = new;
                    }
                    else if(new->priority < Rear->priority)
                    {
                        new->next = Front;
                        Front = new;
                    }
                    else{
                        temp=Front;
                        while(temp->next!=NULL)
                        {
                            if(new->priority>temp->priority && new->priority<temp->next->priority)
                            {
                                new->next  = temp->next;
                                temp->next = new;
                                break;
                            }
                        temp =temp->next;
                        }
                    }
                }
            break;


            case 2:
                    if(Front==NULL)
                        printf("\nQueue is empty");
                    else
                    {
                        temp=Front;
                        Front = Front->next;
                        free(temp);
                    }
                break;


            case 3:
                if(Front==NULL)
                    printf("\nQueue is empty");
                else{
                    temp=Front;
                    printf("\n --- Ascending order ---");
                    printf("\nDequeue region Front");
                    printf("\nFront |-");
                    while(temp->next!=NULL)
                    {
                        printf(" data :%d priority :%d <-",temp->data,temp->priority);
                        temp=temp->next;
                    }
                    printf(" data :%d priority :%d ",temp->data,temp->priority);
                    printf("-| Rear");
                    printf("\nEnqueue region Rear");
                }
                break;


        }

    }while(choice);


    printf("----*----*----*----*----*----");
    printf("\nThanks for using this code :)\n");
    printf("----*----*----*----*----*----");
    //Done by sugan0tech


}