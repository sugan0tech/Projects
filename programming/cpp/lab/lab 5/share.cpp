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
    void inorder(TreeNode *node);
    void preorder(TreeNode *node);
    void postorder(TreeNode *node);
    void search(TreeNode *node, int num);
    int maxHeight_Depth(TreeNode *node);
    // TreeNode *miin(TreeNode *node);
    // TreeNode *del(TreeNode *node, int num);
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

void BST::postorder(TreeNode *node)
{
    if (node)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
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

int main()
{
    BST tree;
    int n = 1;
    while (n)
    {
        cout << "enter the num : ";
        cin >> n;
        if (n)
            tree.create(n);
    }
    cout << tree.root->data << "\n";
    tree.inorder(tree.root);
    cout << "\n";
    tree.preorder(tree.root);
    cout << "\n";
    tree.postorder(tree.root);
    cout << "\n";
    tree.search(tree.root, 5);
    cout << "\n";
    cout << "\n Max height or Depth " << tree.maxHeight_Depth(tree.root) << endl;
}