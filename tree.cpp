#include<iostream>
#include<stdio.h>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(int data)
    {
        this->value = data;
        this->left = this->right = NULL;
    }
};


void preorder(TreeNode* root)
{
    if(root!=NULL)
    {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

void postorder(TreeNode* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

int main()
{
    /// Tree Creation

    TreeNode* root = NULL;
    root = new TreeNode(0);

    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    root->left->left->left = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->right->right->left = new TreeNode(9);


    /// Tree Traversal

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\n";

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}