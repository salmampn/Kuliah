#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
    char data;
    struct Node *left, *right;
}Node;

Node *createNewNode(char data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insertNode(char *exp, int *pos){
    Node *root = createNewNode(exp[*pos]);
    (*pos)++;

    if(root->data == '+' || root->data == '-' || root->data == '*' || root->data == '/'){
        root->left = insertNode(exp, pos);
        root->right = insertNode(exp, pos);
    }

    return root;
}

void inorder(Node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

int main(){
    char expA[] = "-*+abcd";
    char expB[] = "*+ab+cd";
    char expC[] = "+/ab/cd";
    int pos = 0;

    printf("Expression a\t\t: %s\n", expA);
    Node *rootA = insertNode(expA, &pos);
    printf("Correct expression\t: ");
    inorder(rootA);
    printf("\n\n");

    pos = 0;
    printf("Expression b\t\t: %s\n", expB);
    Node *rootB = insertNode(expB, &pos);
    printf("Correct expression\t: ");
    inorder(rootB);
    printf("\n\n");

    pos = 0;
    printf("Expression c\t\t: %s\n", expC);
    Node *rootC = insertNode(expC, &pos);
    printf("Correct expression\t: ");
    inorder(rootC);
    return 0;
}