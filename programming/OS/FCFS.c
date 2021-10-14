#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int BT, WT, TT;
    struct Node *next;
};

struct Node *create(struct Node *head)
{
    int n, count = 1, pcount, AT;
    printf("\nEnter the count of process :");
    scanf("%d", &pcount);
    struct Node *new, *temp;
    while (pcount!=0)
    {
        printf("\nEnter the Brust Time of process %d:", count);
        scanf("%d", &n);
        new = (struct Node *)malloc(sizeof(struct Node));
        new->BT = n;
        new->next = NULL;
        if(head == NULL)
        {
            head = new;
            temp = head;
        }
        else
        {
            temp->next = new;
            temp = new;
        }
        count++;
        pcount--;
    }
    temp = head;
    return temp;
}

struct Node *FirstComeFirstServerWT(struct Node *head) {
    struct Node *temp = head;
    int time = 0;
    while (temp != NULL)
    {
        temp->WT = time;
        time = time + temp->BT;
        temp = temp->next;
    }
    temp = head;
    return temp;
}


struct Node *FirstComeFirstServerTT(struct Node *head) {
    struct Node *temp = head;
    int tmp = 0;
    while (temp != NULL)
    {
        tmp = temp->BT + temp->WT;
        temp->TT = tmp;
        temp = temp->next;
    }
    temp = head;
    return temp;
}

void printQ(struct Node *head)
{
    struct Node *temp = head;
    int count = 0;
    float avgWT = 0, avgTT = 0;
    printf("\n\nProcess         BT      WT      TT");
    while (temp != NULL)
    {
        count++;
        printf("\nP[%d]\t\t%d\t%d\t%d\t", count, temp->BT, temp->WT, temp->TT);
        avgWT = avgWT + temp->WT;
        avgTT = avgTT + temp->TT;
        temp = temp->next;
    }
    printf("\n\nAverage waiting time is : %.2f ms", avgWT/count);
    printf("\nAverage turnaround time is : %.2f ms\n\n", avgTT/count);
}
void main()
{
    struct Node *head = NULL;
    head = create(head);
    head = FirstComeFirstServerWT(head);
    head = FirstComeFirstServerTT(head);
    printQ(head);
}