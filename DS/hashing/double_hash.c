#include<stdio.h>
#define size 11

int hash1(int a)
{
    return a%10;
}

int hash2(int b)
{
    return b%8;
}
void insert(int arr[], int val)
{
    int tmp = 0, key = hash1(val) + tmp*hash2(val);
    if (arr[key] == -1) 
    {
        arr[key] = val;
    }
    else if (arr[key] != -1)
    {
        int temp = 0;
        while (arr[key] != -1)
        {
            key = hash1(val) + tmp*hash2(val);
            if(temp == size)
            {
                break;
            }
            temp++;
            if (arr[key] == -1)
            {
                arr[key] = val;
                break;
            }
            tmp++;
            
        }
        
    }
    
    
}
void main()
{
    int val, key, hash_table[size];
    for (int i = 0; i < size; i++)
    {
        hash_table[i] = -1;
    }
    
    printf("Enter the val :");
    scanf("%d", &val);
    insert(hash_table, val);
    while(val != -1)
    {
        printf("\nEnter the val :");
        scanf("%d", &val);
        insert(hash_table, val);
    }

    for (int i = 0; i < size; i++)
    {
        if (hash_table[i] == -1)
        {
            printf("\nkey :%d -> val :Empty", i);
            continue;
        }
        
        printf("\nkey :%d -> val :%d",i , hash_table[i]);
    }
    
}