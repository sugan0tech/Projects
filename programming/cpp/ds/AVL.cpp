#include <iostream>
#include <stdlib.h>
using namespace std;

class TreeNode
{
public:
    int data, height;
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
    void postorder(TreeNode *node);
    void search(TreeNode *node, int num);
    int height(TreeNode *node, int num);
    int _height(TreeNode *node, int num, int &height);
    int depth(TreeNode *node, int num);
    TreeNode *del(TreeNode *node, int num);
    TreeNode *miin(TreeNode *node);
    TreeNode *maax(TreeNode *node);
    int get_bal(TreeNode *node);
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
int BST::_height(TreeNode *node, int num, int &height)
{
    if (node == NULL)
    {
        return -1;
    }
    int lh = _height(node->left, num, height);
    int rh = _height(node->right, num, height);
    int res = max(lh, rh) + 1;
    if (node->data == num)
    {
        height = res;
    }
    return res;
}

int BST::height(TreeNode *node, int num)
{
    int height = -1;
    int max_height = _height(node, num, height);
    return height;
}

int BST::depth(TreeNode *node, int num)
{
    if (node == NULL)
        return -1;
    int dist = -1;
    if ((node->data == num) || (dist = depth(node->left, num)) >= 0 || (dist = depth(node->right, num)) >= 0)
        return dist + 1;
    return dist;
}

TreeNode *BST::del(TreeNode *node, int num)
{
    if (node == NULL)
        return root;
    else if (num < node->data)
        root->left = del(node->left, num);
    else if (num > node->data)
        root->right = del(node->right, num);
    else if (num == node->data)
    {
        if (node->left == NULL && node->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            TreeNode *temp = node->right;
            delete node;
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = node->left;
            delete node;
            return temp;
        }
        else
        {
            TreeNode *temp = miin(node->right);
            node->data = temp->data;
            node->right = del(node->right, temp->data);
        }
    }
    return node;
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

int BST ::get_bal(TreeNode *node)
{

    if (node == NULL)
        return 0;
    return height(node, node->left->data) - height(node, node->right->data);
}

int main()
{
    BST tree;
    int opt, n = 1;
    cout << "\n\nEnter your choice :\n 0 for exit, \n 1 for creation, \n 2 inorer ,preorder and postorder, \n 3 for insertion, \n 4 for deletion, \n 5 for searching, \n 6 For finding min and max,\n 7 for depth and height.\n";
    cout << " >";
    cin >> opt;
    while (opt)
    {
        switch (opt)
        {
        case 1:
            //creation section
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
            //display section
            cout << "\n\nInorder : ";
            tree.inorder(tree.root);
            cout << "\n\nPreorder : ";
            tree.preorder(tree.root);
            cout << "\n\nPostorder : ";
            tree.postorder(tree.root);
            cout << endl;
            break;
        case 3:
            //insertion section
            cout << "\nenter the num : ";
            cin >> n;
            tree.create(n);
            break;
        case 4:
            //delete section
            cout << "\nenter the num to deleted: ";
            cin >> n;
            tree.del(tree.root, n);
            break;
        case 5:
            // search section
            cout << "\nenter the num to search: ";
            cin >> n;
            tree.search(tree.root, n);
            break;
        case 6:
            // min and max
            cout << "\n min : " << tree.miin(tree.root)->data << "\n max : " << tree.maax(tree.root)->data << endl;
        case 7:
            //depth
            cout << "\nenter the num to see depth and height :";
            cin >> n;
            cout << "\n depth : " << tree.depth(tree.root, n) << endl;
            cout << "\n height : " << tree.height(tree.root, n);
        case 8:
            //get bal
            cout << "\nEnter the num to find balance :";
            cin >> n;
        default:
            break;
        }
        cout << "\n\nEnter your choice :\n 0 for exit, \n 1 for creation, \n 2 inorer ,preorder and postorder, \n 3 for insertion, \n 4 for deletion, \n 5 for searching, \n 6 For finding min and max,\n 7 for depth and height.\n";
        cout << " >";
        cin >> opt;
    }
}