#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

struct Node* makeNode(int value){
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct Node* insert(struct Node* node, int value){
    if(node==NULL) return makeNode(value);
    else if(value < node->data) node->left = insert(node->left,value);
    else if(value > node->data) node->right = insert(node->right,value);
    return node;
}

void inorder(struct Node* node){
    if(node==NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(struct Node* node){
    if(node==NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node* node){
    if(node==NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

void search(struct Node* node, int value){
    if(node==NULL) printf("\n%d not found\n", value);
    else if(value == node->data) printf("\n%d is found\n", value);
    else if(value < node->data) search(node->left, value);
    else if(value > node->data) search(node->right, value);
}

int main(){
    int choice, value;
    do
    {
        printf("\n1.Insert\n2.Traverse\n3.Search\n4.Exit\n");
        printf("Enter your Choice :");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter Value:");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("\nInorder: ");
            inorder(root);
            printf("\nPreorder: ");
            preorder(root);
            printf("\nPostorder: ");
            postorder(root);
            printf("\n");
            break;
        case 3:
            printf("Enter Value:");
            scanf("%d", &value);
            search(root, value);
            break;
        case 4:
            printf("\nExit\n");
            break;
        default:
            break;
        }
    } while (choice != 4);
    
}