#include<stdio.h>
#include<stdlib.h>
#define limit  5


void main()
{
    int choice, i = 0, j;
    int arr[limit];
    printf("\nEnter the choice 1 for adding , 2 for printing, 3 for pop :");
    scanf("%d", &choice);
    do
    {
    
    switch(choice)
    {
        case 1:
            if (i >= limit)
            {
                printf("\nStack  over flow\n");
                break;
            }
            
            printf("\nEnter the new Top :");
            scanf("%d", &arr[i]);
            i++;
            break;

        case 2:
        printf("\nPrinting the stack \n");
            printf("Top\n");
            for (j = i; j > 0; j--)
            {
                printf("%d \n", arr[j - 1]);
            }
            printf("Base\n");
            break;

        case 3:
            if(i <= 0)
            {
                printf("\nStack in underflow \n");
                break;
            }
            printf("\nTop element is popped \n");
            i--;
            break;
        default:
            break;
    }
    printf("\nEnter the choice 1 for adding , 2 for printing, 3 for pop :");
    scanf("%d", &choice);
    } while (choice > 0);
}