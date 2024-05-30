#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

typedef Node *TREE;

void createTree(TREE &root){
    root = NULL;
}

Node* createNode(int x){
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

void insertNode(TREE &root, int x){
    if (root)
    {
        if (root->data == x)
            return ;
        if (root->data > x)
            return insertNode(root->left, x);
        else
            return insertNode(root->right, x);
    }
    root = createNode(x);
    if (root == NULL)
        return ;
    return ;
}

struct pNode{
    int x;
    pNode *next;
};
typedef pNode *STACK;

void createStack(STACK &s){
    s = NULL;
}

pNode *createpNode(int x){
    pNode *p;
    p = new pNode;
    if (p == NULL)
        exit(1);
    else
    {
        p->x = x;
        p->next = NULL;
    }
    return p;
}

void push(STACK &s, int x){
    pNode *p = createpNode(x);
    p->next = s;
    s = p;
}

void convertToList(TREE root, STACK &s){
    if (root)
    {
        push(s, root->data);
        convertToList(root->left, s);
        convertToList(root->right, s);
    }
}


void sumToMap(STACK &s, STACK &m){
    for(auto i = s; i != NULL; i = i->next){
        int sum = 0;
        for (auto j = s; j != NULL; j = j->next)
        {
            if (i->x <= j->x)
                sum += j->x;
        }
        push(m, sum);
    }
}

void Sort(STACK &s){
    pNode *p = s;
    while (p != NULL)
    {
        pNode *q = p->next;
        while (q != NULL)
        {
            if (p->x < q->x)
            {
                swap(p->x, q->x);
            }
            q = q->next;
        }
        p = p->next;
    }
}
void print(STACK &s){
    pNode *p = s;
    while (p != NULL)
    {
        cout << p->x << " ";
        p = p->next;
    }
    cout << endl;
}
int main(){
    int n ;
    cin >> n;
    TREE root;
    createTree(root);
    for(int i = 1; i<= n; i++)
    {
        int x;
        cin >> x;
        insertNode(root, x);
    }
    STACK s, m;
    createStack(s);
    createStack(m);
    convertToList(root, s);
    sumToMap(s, m);
    Sort(m);
    print(m);
    return 0;
}