#include<stdio.h>

typedef struct  node Node;

struct  node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int item){
    Node *n_node =(Node*)malloc(sizeof(Node));
    n_node->data = item;
    n_node->left = NULL;
    n_node->right = NULL;

    return n_node;
}

void Alchild(Node*node ,Node*child){
    node->left = child;
}

void ARchild(Node*node ,Node*child){
    node->right = child;
}


