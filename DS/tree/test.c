#include <stdio.h>
#include <string.h>

int len(int arr[], int n)
{
    int i = 0;
    while (1)
    {
        if(arr[i] == -1) 
        {
            break;
        }
        i++; 
    }
    printf("%d, %d", i, strlen(arr));
    
}

void main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, -1};
    len(arr, 7);
}