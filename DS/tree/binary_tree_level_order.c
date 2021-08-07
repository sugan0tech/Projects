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
void print_order(struct Node *t)
{
    int h, i;
    h = height(t);

    for(i = 1; i <= h; i++)
    {
        print_level(t, i);
    }

}

int print_level(struct Node *t, int level)
{
    if(t == NULL)
    {
        return NULL;
    }
    if(level == 1)
    {
        printf("%d ", t->data);
    }
    else if (level > 1)
    {
        print_level(t->left, level - 1);
        print_level(t->right, level - 1);
    }
    
}

int height(struct Node *t)
{
    int lheight, rheight;
    if(t==NULL)
    {
        return 0;
    }
    else
    {
        lheight = height(t->left);
        rheight = height(t->right);
    }
    if (lheight > rheight)
    {
        return lheight + 1;
    }
    else
    {
        return rheight + 1;
    }
}

void main()
{
    struct Node *Tree = NULL;
    Tree = create();
    preorder(Tree);
}