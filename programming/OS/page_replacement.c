#include <stdio.h>
int n, nf;
int in[100];
int p[50];
int hit = 0;
int i, j, k;
int pgfaultcnt = 0;

void getData()
{
    printf("\nLength of page reference string: ");
    scanf("%d", &n);
    printf("Reference String: ");
    for (i = 0; i < n; i++)
        scanf("%d", &in[i]);
    printf("Frame size: ");
    scanf("%d", &nf);
}

void initialize()
{
    pgfaultcnt = 0;
    for (i = 0; i < nf; i++)
        p[i] = 9999;
}

int isHit(int data)
{
    hit = 0;
    for (j = 0; j < nf; j++)
    {
        if (p[j] == data)
        {
            hit = 1;
            break;
        }
    }

    return hit;
}

int getHitIndex(int data)
{
    int hitind;
    for (k = 0; k < nf; k++)
    {
        if (p[k] == data)
        {
            hitind = k;
            break;
        }
    }
    return hitind;
}

void dispPgFaultCnt()
{
    printf(" - no of page faults: %d", pgfaultcnt);
    printf("\n");
}

void fifo()
{
    initialize();
    for (i = 0; i < n; i++)
    {
        if (isHit(in[i]) == 0)
        {

            for (k = 0; k < nf - 1; k++)
                p[k] = p[k + 1];

            p[k] = in[i];
            pgfaultcnt++;
        }
    }
    dispPgFaultCnt();
}

void optimal()
{
    initialize();
    int near[50];
    for (i = 0; i < n; i++)
    {

        if (isHit(in[i]) == 0)
        {

            for (j = 0; j < nf; j++)
            {
                int pg = p[j];
                int found = 0;
                for (k = i; k < n; k++)
                {
                    if (pg == in[k])
                    {
                        near[j] = k;
                        found = 1;
                        break;
                    }
                    else
                        found = 0;
                }
                if (!found)
                    near[j] = 9999;
            }
            int max = -9999;
            int repindex;
            for (j = 0; j < nf; j++)
            {
                if (near[j] > max)
                {
                    max = near[j];
                    repindex = j;
                }
            }
            p[repindex] = in[i];
            pgfaultcnt++;
        }
    }
    dispPgFaultCnt();
}

void lru()
{
    initialize();

    int least[50];
    for (i = 0; i < n; i++)
    {

        if (isHit(in[i]) == 0)
        {

            for (j = 0; j < nf; j++)
            {
                int pg = p[j];
                int found = 0;
                for (k = i - 1; k >= 0; k--)
                {
                    if (pg == in[k])
                    {
                        least[j] = k;
                        found = 1;
                        break;
                    }
                    else
                        found = 0;
                }
                if (!found)
                    least[j] = -9999;
            }
            int min = 9999;
            int repindex;
            for (j = 0; j < nf; j++)
            {
                if (least[j] < min)
                {
                    min = least[j];
                    repindex = j;
                }
            }
            p[repindex] = in[i];
            pgfaultcnt++;
        }
    }
    dispPgFaultCnt();
}

int main()
{
    int choice;
    printf("\nPage Replacement Algorithms");
    getData();
    printf("\nFIFO");
    fifo();
    printf("OPTIMAL");
    optimal();
    printf("LRU");
    lru();
    return 0;
}