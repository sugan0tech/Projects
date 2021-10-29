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
    void search(TreeNode *node, int num);
    TreeNode *miin(TreeNode *node);
    TreeNode *maax(TreeNode *node);
    void del(TreeNode *node, int num);
    TreeNode *_del(TreeNode *node, int num);
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

void BST::search(TreeNode *node, int num)
{
    TreeNode *temp = node;
    if (node != NULL)
    {
        if (num > temp->data)
        {
            search(temp->right, num);
        }
        else if (num < temp->data)
        {
            search(temp->left, num);
        }
        else
        {
            cout << "\nFound it !! " << temp->data << endl;
        }
    }
    else
    {
        cout << "\nnotfound\n";
    }
}

TreeNode *BST::miin(TreeNode *node)
{
    TreeNode *temp = node;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

TreeNode *BST::maax(TreeNode *node)
{
    TreeNode *temp = node;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
void BST::del(TreeNode *node, int num)
{
    node = _del(node, num);
}
TreeNode *BST::_del(TreeNode *node, int num)
{
    if (node == NULL)
        return root;
    else if (num < node->data)
        root->left = _del(node->left, num);
    else if (num > node->data)
        root->right = _del(node->right, num);
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            delete node;
            node = NULL;
        }
        else if (root->left == NULL)
        {
            TreeNode *temp = node;
            node = node->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            TreeNode *temp = miin(node->right);
            node->data = temp->data;
            node->right = _del(node->right, temp->data);
        }
    }
    return node;
}

int main()
{
    BST tree;
    int n = 1, opt, val;

    cout << "\n0 for exit\n1 for creation\n2 for geting min and max\n3 for searching\n4 for inserting\n5 for deletion\n";
    cout << "\nEnter the option :";
    cin >> opt;

    do
    {
        switch (opt)
        {
        case 1:
            while (n)
            {
                cout << "enter the num : ";
                cin >> n;
                if (n)
                    tree.create(n);
            }
            break;

        case 2:

            cout << "the min value : " << tree.miin(tree.root)->data << endl;
            cout << "the max value : " << tree.maax(tree.root)->data << endl;
            break;

        case 3:

            cout << "\nEnter the val :";
            cin >> val;
            tree.search(tree.root, val);
            break;

        case 4:

            cout << "\nEnter the val :";
            cin >> val;
            tree.create(val);
            tree.inorder(tree.root);
            tree.preorder(tree.root);
            break;

        case 5:

            cout << "\nEnter the val :";
            cin >> val;
            tree.del(tree.root, val);
            tree.inorder(tree.root);
            tree.preorder(tree.root);
            break;

        default:
            break;
        }

        cout << "\n0 for exit\n1 for creation\n2 for geting min and max\n3 for searching\n4 for inserting\n5 for deletion\n";
        cout << "\nEnter the option :";
        cin >> opt;

    } while (opt);
}