#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int info;
    Node* pNext;
    Node* pPrev;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

void createList(List &l){
    l.pHead = l.pTail = NULL;
}
Node* createNode(int x){
    Node* p = new Node;
    if(p == NULL){
        return NULL;
    }
    p->info = x;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}
void pushBack(List &l, Node* p){
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else{
        p->pPrev = l.pTail;
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void push(List &l, Node* p){
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else{
        l.pHead->pPrev = p;
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void sumList(List &l, List l1, List l2){
    Node* p1 = l1.pHead;
    Node* p2 = l2.pHead;
    int sum = 0;
    while(p1 != NULL && p2 != NULL){
        sum += p1->info + p2->info;
        if (sum >= 10){
            Node* p = createNode(sum % 10);
            pushBack(l, p);
            sum = 1;
        }
        else{
            Node* p = createNode(sum);
            pushBack(l, p);
            sum = 0;
        }
        p1 = p1->pNext;
        p2 = p2->pNext;
    }
    while(p1 != NULL){
        sum += p1->info;
        if (sum >= 10){
            Node* p = createNode(sum % 10);
            pushBack(l, p);
            sum = 1;
        }
        else{
            Node* p = createNode(sum);
            pushBack(l, p);
            sum = 0;
        }
        p1 = p1->pNext;
    }
    while(p2 != NULL){
        sum += p2->info;
        if (sum >= 10){
            Node* p = createNode(sum % 10);
            pushBack(l, p);
            sum = 1;
        }
        else{
            Node* p = createNode(sum);
            pushBack(l, p);
            sum = 0;
        }
        p2 = p2->pNext;
    }
    if (sum == 1){
        Node* p = createNode(1);
        pushBack(l, p);
    }
}

int main(){
    long long n;
    cin >> n;
    List l1;
    createList(l1);
    while(n != -1){
        Node* p = createNode(n);
        pushBack(l1, p);
        cin >> n;
    }
    cin >> n;
    List l2;
    createList(l2);
    while(n != -1){
        Node* p = createNode(n);
        pushBack(l2, p);
        cin >> n;
    }
    List sum;
    createList(sum);
    sumList(sum, l1, l2);
    for(Node* p = sum.pTail; p != NULL; p = p->pPrev){
        cout << p->info;
    }
}
