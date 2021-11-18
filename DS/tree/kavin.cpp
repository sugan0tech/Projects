#include <iostream>
#include <stdlib.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    Node *root = NULL;

public:
    Node *create();
    void insert();
    void print(Node *tmp);
};

Node *Tree::create()
{
    Node *tmp;
    int n;

    cout << "\nEnter num -1 for null :";
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }
    tmp = new Node(n);
    printf("\nEnter left child %d ", n);
    tmp->left = create();
    printf("\nEnter rigth child %d", n);
    tmp->right = create();
    return tmp;
};

void Tree::insert(){

};

void Tree ::print(Node *tmp)
{
    if (tmp == NULL)
    {
        printf("null");
    }
    else
    {
        print(tmp->left);
        printf("%d", tmp->data);
        print(tmp->right);
    }
};
int main()
{
    Tree t;
    t.root = t.create();
    t.print(t.root);

    return 0;
}