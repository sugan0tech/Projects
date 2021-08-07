#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

};

struct Node *create()
{
    struct Node *child;
    int x;
    printf("Enter data and -1 for NULL data ");
    scanf("%d", &x);
    if(x==-1)
        return NULL;
    child=(struct Node *)malloc(sizeof(struct Node));
    child->data = x;
    printf("Enter left child of %d ", x);
    child->left = create();
    printf("Enter right child of %d ", x);
    child->right = create();
    return child;

}

void inorder(struct Node *t)
{
    if (t!=NULL)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
    else
    {
        printf("NULL ");
    }
    
    
}

void preorder(struct Node *t)
{
    if (t!=NULL)
    {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
    else
    {
        printf("NULL ");
    }
    
    
}

void postorder(struct Node *t)
{
    if (t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
    else
    {
        printf("NULL ");
    }
    
    
}


struct Node *impose(int pre_start, int in_start,int in_end, int pre_order[], int in_order[])
{
    struct Node *root;
    int in_index = 0, len_pre = 0, len_in = 0;
    

    for (int i = 0; i <= in_end - in_start; i++)
    {
        len_in++;
    }
    for (int i = 0; i <= in_end - pre_start; i++)
    {
        len_pre++;
    }


    root = (struct Node *)malloc(sizeof(struct Node *));
    root->data = pre_order[0];

    if (pre_start > len_pre - 1 || in_start > len_in )
    {
        return NULL;
    }

    for(int i = in_start; i< in_end; i++)
    {
        if(root->data == in_order[i])
        {
            in_index = i;
        }
    }

    root->left = impose(pre_start + 1, in_start, in_index - 1, pre_order, in_order);
    root->right = impose(pre_start + in_index - in_start + 1, in_index + 1, in_end, pre_order, in_order);
    return root;
}

void main()
{
    int in_order[5] = {3, 9, 20, 15, 7}, pre_order[5] = {9, 3, 15, 20, 7}, i;
    struct Node *Root;
    Root = impose(0, 0, 4, pre_order, in_order);
    inorder(Root);

    // printf("\nEnter the In order :");
    // for(i=0; i<10; i++)
    // {
    //     scanf("%d", &in_order[i]);
    // }

    // printf("\nEnter the Pre order :");
    // for(i=0; i<10; i++)
    // {
    //     scanf("%d", &pre_order[i]);
    // }

    // printf("\nIn order :");
    // for(i=0; i<10; i++)
    // {
    //     printf("%d ", in_order[i]);
    // }
    // printf("\nPre order :");
    // for(i=0; i<10; i++)
    // {
    //     printf("%d ", pre_order[i]);
    // }

    struct Node *root = NULL, *temp;
    root = create();
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
}