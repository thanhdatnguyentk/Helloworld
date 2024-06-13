#include<bits/stdc++.h>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

typedef Node* TREE;

void createTree(TREE &root){
    root = NULL;
}
Node *createNode(int data){
    Node *p;
    p = new Node;
    if (p == NULL)
        exit(1);
    else{
        p->data = data;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

void insertNode(TREE &root, int data){
    if(root) {
        if (root->data == data) return ;
        if (root->data > data) return insertNode(root->left, data);
        else return insertNode(root->right, data);
    }
    root = createNode(data);
    if (root == NULL) return ;
    return;
}

void deleteNode(TREE &root, int data){
    if (root == NULL) return;
    if (root->data > data) return deleteNode(root->left, data);
    if (root->data < data) return deleteNode(root->right, data);
    if (root->left == NULL){
        Node *temp = root;
        root = root->right;
        delete temp;
        return;
    }
    if (root->right == NULL){
        Node *temp = root;
        root = root->left;
        delete temp;
        return;
    }
    Node *temp = root->right;
    while (temp->left != NULL) temp = temp->left;
    root->data = temp->data;
    deleteNode(root->right, temp->data);
}

bool search(TREE &root, int data){
    if (root == NULL) return false;
    if (root->data == data) return true;
    if (root->data > data) return search(root->left, data);
    return search(root->right, data);
}

int main(){
    int a = 1, b =0;
    TREE root;
    createTree(root);
    while (a != 0){
        cin >> a;
        if (a == 0) break;
        cin >> b;
        if (a == 1) insertNode(root, b);
        else if (a == 3) deleteNode(root, b);
        else cout << search(root , b) << endl;
    }
}