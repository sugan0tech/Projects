#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int AT, BT, WT, TT;
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
        new = (struct Node *)malloc(sizeof(struct Node));
        new->BT = n;
        new->WT = -1;
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

struct Node *ShortestJobFirst(struct Node *head, int count)
{
    struct Node *temp = head;
    int bt = temp->BT, time = 0, mx = 0;
    while (temp != NULL)
    {
        if (temp->BT > mx)
            mx = temp->BT;
        temp = temp->next;
    };
    // for waiting time
    while (count)
    {
        bt = mx;
        temp = head;
        while (temp != NULL)
        {
            if ((temp->WT == -1) && (temp->BT <= bt))
            {
                bt = temp->BT;
            }
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            if ((temp->BT <= bt) && (temp->WT == -1))
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
    printf("\n\nProcess         BT      WT      TT");
    while (temp != NULL)
    {
        count++;
        printf("\nP[%d]\t\t%d\t%d\t%d\t", count, temp->BT, temp->WT, temp->TT);
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
    struct Node *head = NULL;
    printf("\nEnter the count of process:");
    scanf("%d", &count);
    head = create(head, count);
    head = ShortestJobFirst(head, count);
    printQ(head);
}