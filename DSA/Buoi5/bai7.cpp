#include<bits/stdc++.h>

using namespace std;

struct Data
{
    string code;
    public:
        bool operator>(Data x){
            return this->code > x.code;
        }
        bool operator<(Data x){
            return this->code < x.code;
        }
        bool operator==(Data x){
            return this->code == x.code;
        }
};



struct Node{
    Data data;
    Node* left;
    Node* right;
};

typedef Node* TREE;

void createTree(TREE &root){
    root = NULL;
};
Node *createNode(Data x){
    Node *p;
    p = new Node;
    if (p == NULL)
        exit(1);
    else
    {
        p->data = x;
        p->left = NULL;
        p->right = NULL; 
    }
    return p;
}

void insertNode(TREE &root, Data x) {
    if (root) {
        if (root->data == x) return ;
        if (root->data > x) return insertNode(root->left, x);
        else return insertNode(root->right, x);
    }
    root = createNode(x);
    if (root == NULL) return ;
    return ;
}

bool search(TREE &root, Data x){
    if (root == NULL) return false;
    if(root->data == x) return true;
    if(root->data > x) return search(root->left, x);
    else return search(root->right, x);
}

void deleteNode(TREE &root, Data x){
    if(root == NULL) return;
    if(root->data > x) return deleteNode(root->left, x);
    if(root->data < x) return deleteNode(root->right, x);
    if(root->data == x){
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else{
            Node *temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            deleteNode(root->right, temp->data);
        }
    }
}

int main(){
    int n;
    cin >> n;
    TREE root;
    createTree(root);
    while (n != 0){
        string x;
        cin >> x;
        if (n == 1){
            Data temp;
            temp.code = x;
            insertNode(root, temp);
        }
        if (n == 2){
            Data temp;
            temp.code = x;
            if(search(root, temp)) cout << "1" << endl;
            else cout << "0" << endl;
        }
        if (n == 3){
            Data temp;
            temp.code = x;
            deleteNode(root, temp);
        }
        cin >> n;
    }
}