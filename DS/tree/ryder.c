#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

};


struct Node* constructTreeUtil(int previous[], int* PreviousIndex, int low, int high, int size)
{
    if (*PreviousIndex >= size || low > high)
        return NULL;

    struct Node* t = (struct Node *)malloc(sizeof(struct Node));
    t->left = NULL;
    t->right = NULL;
    t->data = previous[*PreviousIndex];
    *PreviousIndex = *PreviousIndex + 1;

    if (low == high)
        return t;

    int i;
    for (i = low; i <= high; ++i)
        if (previous[i] > t->data)
            break;

    t->left = constructTreeUtil(previous, PreviousIndex, *PreviousIndex, i - 1, size);
    t->right = constructTreeUtil(previous, PreviousIndex, i, high, size);
    return t;
}

struct Node* constructTree(int previous[], int size)
{
    int previousIndex = 0;
    return constructTreeUtil(previous, &previousIndex, 0, size - 1, size);
}

void inorder(struct Node *t)
{
    if (t!=NULL)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
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
    
}


int FindMin(struct Node *tree)
{
    int min;
    min = tree->data;
    if (tree->left == NULL) 
    {
        return min;
    }
    FindMin(tree->left);

}

int FindMax(struct Node *tree)
{
    int max;
    max = tree->data;
    if (tree->right == NULL) 
    {
        return max;
    }
    FindMax(tree->right);

}
int search(struct Node *tree, int n)
{
    if (n == tree->data)
    {
        printf("Found it ");
        return 0;
    }
    else if (n < tree->data)
    {
        search(tree->left, n);
    }
    else if (n > tree->data)
    {
        search(tree->right, n);
    }
    
}
void main()
{
    int opt;
    printf("1 for default values\n2 for custom values\n");
    printf(" Enter the option\n");
    scanf("%d", &opt);
    if (opt == 1)
    {
        int previous[] = { 27 ,19 ,14, 10, 35, 31, 42 };
        int size = sizeof(previous) / sizeof(previous[0]);
        struct Node *root;
        root = constructTree(previous, size);
        printf("Display in Inorder ");
        inorder(root);
        printf("\nThe min value %d \n", FindMin(root));
        printf("The max value %d ", FindMax(root));
        int n;
        printf("Enter the num to be searched ");
        scanf("%d", &n);
        search(root, n);
        
    }
    else if(opt == 2)
    {
        int previous[100], i = 0, data, size;
        struct Node *root;
        printf("\nEnte the previous order values, enter 0 to exit ");
        do
        {
            printf("\nEnter the data :");
            scanf("%d", &data);
            previous[i] = data;
            i++;
        }while(data);
        size = i - 1;
        root = constructTree(previous, size);
        printf("\nDisplay in Inorder ");
        inorder(root);
        printf("\nThe min value %d", FindMin(root));
        printf("\nThe max value %d ", FindMax(root));

        int n;
        printf("Enter the num to be searched ");
        scanf("%d", &n);
        search(root, n);

    }
    else
    {
        printf("Thank you ");
    }
    
}
