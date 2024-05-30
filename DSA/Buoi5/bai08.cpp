#include<bits/stdc++.h>

using namespace std;

struct pNode{
    int x, y =1;
    pNode *next;
};

typedef pNode *STACK;

void createStack(STACK &s){
    s = NULL;
}

pNode *createNode(int x){
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
    pNode *p = createNode(x);
    p->next = s;
    s = p;
}
pNode* search(STACK &s, int x){
    pNode *p = s;
    while (p != NULL)
    {
        if (p->x == x)
            return p;
        p = p->next;
    }
    return NULL;
}

void print(STACK &s){
    pNode *p = s;
    while (p != NULL)
    {
        cout << p->x << " " << p->y << endl;
        p = p->next;
    }
    cout << endl;
}
void Sort(STACK &s){
    pNode *p = s;
    while (p != NULL)
    {
        pNode *q = p->next;
        while (q != NULL)
        {
            if (p->x > q->x)
            {
                swap(p->x, q->x);
                swap(p->y, q->y);
            }
            q = q->next;
        }
        p = p->next;
    }
}

int main(){
    int n;
    STACK s;
    createStack(s);

    while(cin >> n && n != 0){
        pNode* p = search(s, n);
        if (p == NULL)
            push(s, n);
        else 
            p->y++;
    }
    Sort(s);
    print(s);
}

