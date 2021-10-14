#include<stdio.h>
#define size 10
int rear = -1, front = -1, qeue[size];

void enqeue();
void deqeue();

void main()
{
    int i, boo;
    scanf("%d", &boo);
    do
    {
        enqeue();
        printf("\nEnter opt");
        scanf("%d", &boo);
    } while (boo);
    
    for (i = 0; i <= rear; i++)
    {
        printf("%d", qeue[i]);
    }
}

void enqeue()
{
    int n;
    printf("\nEnter the num");
    scanf("%d", &n);
    if (rear = -1)
    {
        qeue[0] = n;
        rear++;
        front++;
    }
    else
    {
        qeue[++rear] = n;
    }
    printf("\n%d %d", rear, front);

}

void deqeue()
{
    int temp;
    rear--;
}