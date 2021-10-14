#include <stdio.h>
#include <stdlib.h>

struct node
{
    int ID, AT, BT, FT, TT, rem;
    float nTT;
} Q[5], temp;

void roundRobin()
{
    int rr[20], q, x, k;
    int f, r, n, i, j, tt = 0, qt, t, flag, wt = 0;
    float awt = 0, antat = 0, atat = 0;

    printf("Enter the no. of jobs:");
    scanf("%d", &n);
    for (r = 0; r < n; r++)
    {
        printf("\nEnter burst time : ");
        scanf("%d", &Q[r].BT);
        Q[r].ID = r;

        Q[r].AT = 0;
    }
    printf("Enter quantum:\n");
    scanf("%d", &qt);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (Q[i].AT > Q[j].AT)
            {
                temp = Q[i];
                Q[i] = Q[j];
                Q[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        Q[i].rem = Q[i].BT;
        Q[i].FT = 0;
    }
    tt = 0;
    q = 0;
    rr[q] = 0;
    do
    {
        for (j = 0; j < n; j++)
            if (tt >= Q[j].AT)
            {
                x = 0;
                for (k = 0; k <= q; k++)
                    if (rr[k] == j)
                        x++;
                if (x == 0)
                {
                    q++;
                    rr[q] = j;
                }
            }
        if (q == 0)
            i = 0;
        if (Q[i].rem == 0)
            i++;
        if (i > q)
            i = (i - 1) % q;
        if (i <= q)
        {
            if (Q[i].rem > 0)
            {
                if (Q[i].rem < qt)
                {
                    tt += Q[i].rem;
                    Q[i].rem = 0;
                }
                else
                {
                    tt += qt;
                    Q[i].rem -= qt;
                }
                Q[i].FT = tt;
            }
            i++;
        }
        flag = 0;
        for (j = 0; j < n; j++)
            if (Q[j].rem > 0)
                flag++;
    } while (flag != 0);

    printf("\nprocesses       AT      BT      TT      WT");
    for (f = 0; f < n; f++)
    {
        wt = Q[f].FT - Q[f].BT - Q[f].AT;
        Q[f].TT = Q[f].FT - Q[f].AT;
        Q[f].nTT = (float)Q[f].TT / Q[f].BT;
        antat += Q[f].nTT;
        atat += Q[f].TT;
        awt += wt;
        printf("\np[%d]\t\t%d\t%d\t%d\t%d", Q[f].ID, Q[f].AT, Q[f].BT, Q[f].TT, wt);
    }
    antat /= n;
    atat /= n;
    awt /= n;
    printf("\n\nAverage Turn around Time is %.2f", atat);
    printf("\nAverage Waiting Time is %.2f", awt);
}

void main()
{
    roundRobin();
}