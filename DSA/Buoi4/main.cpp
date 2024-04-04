#include <iostream>
using namespace std;

struct DATA{
    int x;
};

struct NODE{
    DATA data;
    NODE* pNext;
};

struct LIST{
    NODE* pHead;
    NODE* pTail;
};

void CreateList(LIST &l){
    l.pHead = l.pTail = NULL;
}

NODE* CreateNode(DATA data){
    NODE* p = new NODE;
    if(p == NULL){
        return NULL;
    }
    p->data = data;
    p->pNext = NULL;
    return p;
}

void pushBack(LIST &l, NODE* p){
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;
    }else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void push(LIST &l, NODE* p){
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;
    }else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void pushAfter(LIST &l, NODE* p, NODE* q){
    if(q == NULL){
        return;
    }
    if(q == l.pTail){
        pushBack(l, p);
    }else{
        p->pNext = q->pNext;
        q->pNext = p;
    }
}

void printList(LIST l){
    for(NODE* k = l.pHead; k != NULL; k = k->pNext){
        cout << k->data.x << " ";
    }
    cout << endl;
}

void deleteList(LIST &l){
    NODE* k = l.pHead;
    while(k != NULL){
        NODE* p = k;
        k = k->pNext;
        delete p;
    }
    l.pHead = l.pTail = NULL;
}

int main()
{
    long long n;
    cin >> n;
    if (n== 0){
        cout <<"Danh sach rong.";
        return 0;
    }
    LIST l;
    CreateList(l);
    while (n != 0){
        DATA data;
        data.x = n;
        push(l, CreateNode(data));
        cin >> n;
    }
    cout <<"Danh sach vua nhap la: ";
    printList(l);
}