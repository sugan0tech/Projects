#include <iostream>
#include <stdlib.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int num)
    {
        data = num;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    TreeNode *root = NULL;

public:
    void create(int num);
    void _create(TreeNode *node, int num);
    void inorder(TreeNode *node);
    void preorder(TreeNode *node);
    int maxHeight_Depth(TreeNode *node);
    TreeNode *left_rotate(TreeNode *node);
    TreeNode *right_rotate(TreeNode *node);
    TreeNode left_right_rotate(TreeNode *node);
    TreeNode right_left_rotate(TreeNode *node);
};

void BST::create(int num)
{
    if (root == NULL)
    {
        root = new TreeNode(num);
    }
    else
    {
        _create(root, num);
    }
}

void BST::_create(TreeNode *node, int num)
{
    if (num > node->data)
    {
        if (node->right == NULL)
        {
            node->right = new TreeNode(num);
        }
        else
        {
            _create(node->right, num);
        }
    }
    else if (num < node->data)
    {
        if (node->left == NULL)
        {
            node->left = new TreeNode(num);
        }
        else
        {
            _create(node->left, num);
        }
    }
}

void BST::inorder(TreeNode *node)
{
    if (node)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void BST::preorder(TreeNode *node)
{
    if (node)
    {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

int BST::maxHeight_Depth(TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int l = maxHeight_Depth(node->left);
        int r = maxHeight_Depth(node->right);
        cout << node->data << l << r << endl;
        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
}

TreeNode *BST::left_rotate(TreeNode *node)
{
    TreeNode *P1;
    P1 = node->right;
    node->right = P1->left;
    P1->left = node;
    return P1;
}

TreeNode *BST::right_rotate(TreeNode *node)
{
    TreeNode *P1;
    P1 = node->left;
    node->left = P1->left;
    P1->right = node;
    return P1;
}

int main()
{
    BST tree;
    int opt, n = 1;
    cout << "\n\nEnter your choice :\n 0 for exit, \n 1 for creation, \n 2 inorer and preorder, \n 3 for insertion, \n 4 for deletion, \n 5 For max depth\n";
    cout << " >";
    cin >> opt;
    while (opt)
    {
        switch (opt)
        {
        case 1:
            while (n != 0)
            {
                cout << "\nenter the num : ";
                cin >> n;
                if (n != 0)
                    tree.create(n);
            }
            cout << "\n root node " << tree.root->data;
            break;
        case 2:
            cout << "\n\nInorder : ";
            tree.inorder(tree.root);
            cout << "\n\nPreorder : ";
            tree.preorder(tree.root);
            cout << endl;
            break;
        case 3:
            cout << "\nenter the num : ";
            cin >> n;
            tree.create(n);
            break;
        case 4:
            cout << "\nleft rotate";
            tree.root = tree.left_rotate(tree.root);
            cout << "\n\tInorder : ";
            tree.inorder(tree.root);
            cout << "\n\tPreorder :";
            tree.preorder(tree.root);
            cout << "\nright rotate";
            tree.root = tree.right_rotate(tree.root);
            cout << "\n\tInorder : ";
            tree.inorder(tree.root);
            cout << "\n\tPreorder :";
            tree.preorder(tree.root);
            cout << "\n";
            break;
        case 5:
            break;
        default:
            break;
        }
        cout << "\n\nEnter your choice :\n 0 for exit, \n 1 for creation, \n 2 inorer and preorder, \n 3 for insertion, \n 4 for deletion, \n 5 For max depth\n";
        cout << " >";
        cin >> opt;
    }
}