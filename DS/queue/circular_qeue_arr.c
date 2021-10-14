#include<stdio.h>
#define max 5

int main()
{
    int Cq[max], front = -1, rear = -1;
    int choice, ele, i;
    do
    {
        printf("\nEnter the choice");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(front == 0 && rear == max - 1)
                {
                    printf("\nQeuw is full");
                }
                else
                {
                    printf("\n Enter the num :");
                    scanf("%d", &ele);
                    if(front == -1)
                    {
                        front = rear = 0;
                    }
                    else
                    {
                        rear = (rear + 1)%max;
                    }
                    Cq[rear] = ele;
                }
                break;


            case 2:
                for(i = front; i != rear; (++i)%max )
                {
                    printf("%d", Cq[i]);
                }
                printf("%d", Cq[i]);
                break;


            case 3:
                front = (front + 1)%max;
                break;


        }
    } while (choice);


    printf("----*----*----*----*----*----");
    printf("\nThanks for using this code :)\n");
    printf("----*----*----*----*----*----");
    //Done by sugan0tech
    
}