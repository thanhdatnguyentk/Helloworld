#include<bits/stdc++.h>

using namespace std;

struct Node{
    long long data;
    Node* left;
    Node* right;
};

typedef Node* TREE;

void createTree(TREE &root){
    root = NULL;
}
Node *createNode(long long data){
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

void insertNode(TREE &root, long long data){
    if(root) {
        if (root->data == data) return ;
        if (root->data > data) return insertNode(root->left, data);
        else return insertNode(root->right, data);
    }
    root = createNode(data);
    if (root == NULL) return ;
    return;
}

long long height(TREE root){
    if (root == NULL) return 0;
    else {
        int l = height(root->left);
        int r = height(root->right);
        if (l  > r) return l + 1;
        else return r + 1;
    }
}
void printCurr(TREE &root, int k) {
  if (root == NULL)
    return;
  else if (k == 1)
    cout << root->data << " ";
  else if (k > 1) {
    printCurr(root->right, k - 1);
    printCurr(root->left, k - 1);
  }
}
int main(){
    long long x = 0;
    TREE root;
    createTree(root);
    while (x != -1){
        cin >> x;
        if (x == -1) break;
        insertNode(root, x);
    }
    long long n = height(root);
    while (n > 0){
        printCurr(root, n);
        n--;
    }
}