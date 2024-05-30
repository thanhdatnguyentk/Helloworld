#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
typedef Node *TREE;

void createTree(TREE &root) {
    root = NULL;
}

Node *createNode(int x){
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

int insertNode(TREE &root, int x) {
    if (root) {
        if (root->data == x) return 0;
        if (root->data > x) return insertNode(root->left, x);
        else return insertNode(root->right, x);
    }
    root = createNode(x);
    if (root == NULL) return -1;
    return 1;
}

void NLR(TREE root) {
    if (root) {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(TREE root) {
    if (root) {
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}
void LRN(TREE root) {
    if (root) {
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}
int height(TREE root) {
    if (root == NULL) return 0;
    else {
        int l = height(root->left);
        int r = height(root->right);
        if (l > r) return l + 1;
        else return r + 1;
    }
}

void duyetLevelOrder(TREE root, int n){
    if (root){
        if (n == 1) {
            cout << root->data << " ";
            return ;
        }
        else
        {
            duyetLevelOrder(root->left, n - 1);
            duyetLevelOrder(root->right, n - 1);
        }
    }
    return ;
}

void levelOrder(TREE root){
    int n = height(root);
    for (int i = 1; i <= n; i++){
        duyetLevelOrder(root, i);
    }
}

struct LNode{
    int data;
    LNode* next;
};

typedef LNode *List;

void createList(List &l){
    l = NULL;
}

void createLNode(LNode* &p, int x){
    p = new LNode;
    p->data = x;
    p->next = NULL;
}

void push(List &l, int x){
    LNode *p;
    createLNode(p, x);
    if (l == NULL){
        l = p;
    }
    else{
        p->next = l;
        l = p;
    }
}
void push_back(List &l, int x){
    LNode *p;
    createLNode(p, x);
    if (l == NULL){
        l = p;
    }
    else{
        LNode *q = l;
        while (q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }
}

void insertAfter(List &l, int x, int y){
    LNode *p = l;
    while (p != NULL && p->data != x){
        p = p->next;
    }
    if (p != NULL){
        LNode *q;
        createLNode(q, y);
        q->next = p->next;
        p->next = q;
    }
    else{
        push(l, y);
    }
}

void printList(List l){
    LNode *p = l;
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}

int pp[10005];

int main(){
    int x;
    cin >> x;
    List l;
    createList(l);
    while(x != 3){
        if (x == 0){
            int a;
            cin >> a;
            push(l, a);
        }
        else if(x == 1){
            int a;
            cin >> a;
            push_back(l, a);
        }
        else if (x == 2){
            int a, b;
            cin >> a >> b;
            insertAfter(l, a, b);
        }
        cin >> x;
    }
    TREE root;
    createTree(root);
    for (LNode *i = l; i != NULL; i = i->next){
        if (pp[i->data] == 0)
            insertNode(root, i->data);
        pp[i->data] = 1;
    }
    printList(l);
    cout << endl;
    LNR(root);
    cout << height(root) - 1 << endl;

}