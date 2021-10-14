#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    int prior;
    struct Node *next;
};
int main()
{
    struct Node *front=NULL,*neww,*temp;
    int choice,ele,prio;
    do
    {
      printf("1.Insertion 2.Deletion3.Display");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1:
                 neww=(struct Node*)malloc(sizeof(struct Node));
                 printf("Enter the data:");
                 scanf("%d",&ele);
                 printf("Enter the prirority");
                 scanf("%d",&prio);
                 neww->data=ele;
                 neww->prior=prio;
                 neww->next=NULL;
                 if(front==NULL)
                 {
                     front = neww;
                     temp = neww;
                 }
                 else
                 {
                     neww->next=front;
                     front = neww;
                     temp=front;
                     while(temp->next!=NULL)
                     {
                         if(temp->prior < temp->next->prior)
                         {
                             int dat = temp->data;
                             int pri = temp->prior;
                             temp->data = temp->next->data;
                             temp->prior= temp->next->prior;
                             temp->next->data = dat;
                             temp->next->prior = pri;
                         }
                         temp=temp->next;
                     }
                }
         break;
         case 2:
             if(front==NULL){
                 printf("Queue is empty");
             }
             else{
                temp=front;
                front =temp->next;
                free(temp);
                printf("First element is deleted");
             }
         break;
         case 3:
             if(front==NULL)
                printf("Queue is empty");
             else{
                temp=front;
                while(temp!=NULL)
                {
                    printf("[%d,%d]->",temp->data,temp->prior);
                    temp=temp->next;
                }
             }
         break;
      }
    }while(choice<=3);
    return 0;
}
