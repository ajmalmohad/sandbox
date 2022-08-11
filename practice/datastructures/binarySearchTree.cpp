#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* getNewNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        root = getNewNode(data);
    }else if(data < root->data){
        root->left = insert(root->left, data);
    }else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

int getNodeCount(Node* root){
    if(root == NULL) return 0;
    return getNodeCount(root->right) + getNodeCount(root->left) + 1;
}

void inOrder(Node* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL) return;
    inOrder(root->left);
    inOrder(root->right);
    cout<<root->data<<" ";
}

void deleteNodes(Node* root){
    if(root == NULL) return;
    deleteNodes(root->left);
    deleteNodes(root->right);
    delete root;
}

Node* deleteTree(Node* root){
    deleteNodes(root);
    return NULL;
}

bool isInTree(Node* root, int data){
    if(root == NULL) return false;
    else if(data < root->data) return isInTree(root->left,data);
    else if(data > root->data) return isInTree(root->right,data);
    else return true;
}

Node* getNode(Node* root, int data){
    if(root == NULL) return NULL;
    else if(data < root->data) return getNode(root->left,data);
    else if(data > root->data) return getNode(root->right,data);
    else return root;
}

int getMin(Node* root){
    if(root->left == NULL) return root->data;
    return getMin(root->left);
}

Node* getMinNode(Node* root){
    if(root->left == NULL) return root;
    return getMinNode(root->left);
}

int getMax(Node* root){
    if(root->right == NULL) return root->data;
    return getMax(root->right);
}

bool isBSTHelper(Node* root, int lower, int upper){
    if(root == NULL) return true;
    if( isBSTHelper(root->left, lower, root->data) &&
        isBSTHelper(root->right, root->data, upper) &&
        root->data < upper && root->data > lower
    ) return true;
    return false;
}

bool isBST(Node* root){
    return isBSTHelper(root, INT32_MIN, INT32_MAX);
}

Node* findSuccessor(Node* root, int value){
    if(!isInTree(root, value)) return NULL;
    Node* current = getNode(root, value);
    Node* ancestor = root;
    Node* successor = NULL;;

    if(current->right != NULL){
        return getMinNode(current->right);
    }else{
        while(ancestor != current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

int findSuccessorData(Node* root, int value){
    Node* successor = findSuccessor(root, value);
    if(successor==NULL) return -1;
    else return successor->data;
}


Node* deleteVal(Node* root, int value){
    if(root == NULL) return root;
    if(value < root->data) root->left =  deleteVal(root->left, value);
    else if(value > root->data) root->right = deleteVal(root->right, value);
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }else if(root->right == NULL){
            root = root->left;
        }else if(root->left == NULL){
            root = root->right;
        }else{
            int val = getMin(root->right);
            root->right = deleteVal(root->right, val);
            root->data = val;
        }
    }
    return root;
}

int getHeightByEdges(Node* root){
    if(root == NULL) return -1;
    int left = getHeightByEdges(root->left);
    int right = getHeightByEdges(root->right);
    return max(left, right) + 1;
}

int main(){
    Node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 5);
    root = deleteTree(root);
    root = insert(root, 12);
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 18);
    root = insert(root, 21);
    root = insert(root, 9);
    root = insert(root, -21);
    root = deleteVal(root, -21);
    cout<<"\nInorder :"; inOrder(root);
    cout<<"\nPreOrder :"; preOrder(root);
    cout<<"\nPostOrder :"; postOrder(root);
    cout<<"\nNodeCount: "<<getNodeCount(root);
    cout<<"\nIs 10 in Tree ? "<<isInTree(root, 18);
    cout<<"\nMinimum Value: "<<getMin(root);
    cout<<"\nMaximum Value: "<<getMax(root);
    cout<<"\nIs this a BST ? "<<isBST(root);
    cout<<"\nSuccessor of 6: "<<findSuccessorData(root, 6);
    cout<<"\nHeight of Tree: "<<getHeightByEdges(root);
}