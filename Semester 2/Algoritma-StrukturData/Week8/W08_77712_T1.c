#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *newNode(int val){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int data){
    if (node == NULL) return newNode(data);
    
    if (data < node->data)
    node->left = insert(node->left, data);

    else if(data > node->data)
    node->right = insert(node->right, data);

    return node;
}

void preorder(struct node *root){
    if (root!= NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root){
    if (root!= NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root){
    if (root!= NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    struct node *root = NULL;

    root = insert(root, 50);

    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);

    printf("Binary Tree in PreOrder\t\t: ");
    preorder(root);
    printf("\n");
    printf("Binary Tree in InOrder\t\t: ");
    inorder(root);
    printf("\n");
    printf("Binary Tree in PostOrder\t: ");
    postorder(root);
    printf("\n");
    return 0;
}