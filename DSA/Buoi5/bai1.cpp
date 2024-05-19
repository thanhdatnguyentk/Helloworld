#include<bits/stdc++.h>
#include<iostream> // Add missing header

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->left != NULL) {
            q.push(temp->left);
        } else {
            temp->left = createNode(data);
            return root;
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        } else {
            temp->right = createNode(data);
            return root;
        }
    }
    return root;
}

void NLR(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    NLR(root->left);
    NLR(root->right);
}

int main(){
    int n;
    cin >> n;
    Node* tree;
    for (int i = 1; i<= n;i++)
    {
        int a;
        cin >> a;
        tree = insert(tree, a);
        NLR(tree);
        cout << endl;
    }
    NLR(tree);
}