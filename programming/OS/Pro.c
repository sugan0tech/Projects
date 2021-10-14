#include <stdio.h>
#include <stdlib.h>

// node formation here it have additional data of priority value
struct Node
{
    int AT, BT, WT, TT;
    int priority;
    struct Node *next;
};

struct Node *create(struct Node *head, int pcount)
{
    int n, n2, count = 1, AT;
    struct Node *new, *temp;
    while (pcount != 0)
    {
        printf("\nEnter the Brust Time of process %d:", count);
        scanf("%d", &n);
        printf("\nEnter the priority of process %d:", count);
        scanf("%d", &n2);
        new = (struct Node *)malloc(sizeof(struct Node));
        new->BT = n;
        new->priority = n2;
        new->WT = -1;
        new->AT = 0;
        new->next = NULL;
        if (head == NULL)
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

struct Node *prio(struct Node *head, int count)
{
    struct Node *temp = head;
    int pr = temp->priority, time = 0, mx = 0;
    while (temp != NULL)
    {
        if (temp->priority >= mx)
            mx = temp->priority;
        temp = temp->next;
    };
    // for waiting time
    while (count)
    {
        pr = mx;
        temp = head;
        while (temp != NULL)
        {
            if ((temp->WT == -1) && (temp->priority <= pr))
            {
                pr = temp->priority;
            }
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            if ((temp->priority <= pr) && (temp->WT == -1))
            {
                temp->WT = time;
                time = time + temp->BT;
            }
            temp = temp->next;
        }
        count--;
    };

    // for turn around time
    temp = head;
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
    printf("\n\nProcess         BT      AT      WT      TT");
    while (temp != NULL)
    {
        count++;
        printf("\nP[%d]\t\t%d\t%d\t%d\t%d\t", count, temp->BT, temp->AT, temp->WT, temp->TT);
        avgWT = avgWT + temp->WT;
        avgTT = avgTT + temp->TT;
        temp = temp->next;
    }
    printf("\n\nAverage waiting time is : %.2f ms", avgWT / count);
    printf("\nAverage turnaround time is : %.2f ms\n\n", avgTT / count);
}

void main()
{
    int count;
    printf("\nEnter the count of process:");
    scanf("%d", &count);
    struct Node *head = NULL;
    head = create(head, count);
    head = prio(head, count);
    printQ(head);
}