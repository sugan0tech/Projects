#include<stdio.h>
#define size 10
int rear = -1, front = -1, qeue[size];

//function declaration definition will be at the bottom
void enqeue();
void deqeue();
void print();

void main()
{
    int i, boo;
    printf("1 for enqueue\n2 for printing\n3 for dequeue\n");
    printf("\n Enter the option:");
    scanf("%d", &boo);
    do
    {
        switch (boo)
        {
            case 1:
                enqeue();
                break;


            case 2:
                print();
                break;


            case 3:
                deqeue();
                break;


        }


        printf("\nEnter opt :");
        scanf("%d", &boo);
    } while (boo);


    printf("----*----*----*----*----*----");
    printf("\nThanks for using this code :)\n");
    printf("----*----*----*----*----*----");
    //Done by sugan0tech
    
}

void enqeue()
{
    int n;
    printf("\nEnter the num");
    scanf("%d", &n);
    if (front == -1)
    {
        qeue[0] = n;
        rear++;
        front++;
    }
    else
    {
        qeue[++rear] = n;
    }

}

void deqeue()
{
    int temp;
    rear--;
}

void print()
{
    int i;
    for ( i = front; i <= rear; i++)
    {
        printf(" %d", qeue[i]);
    }
    
    printf("\nFront : %d Rear : %d", qeue[front], qeue[rear]);
}