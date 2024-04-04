#include<bits/stdc++.h>

using namespace std;  

struct DATA
{
    long long x;
};

struct NODE
{
    DATA data;
    NODE *pNext;
};

struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

void CreateList(LIST &l)
{
    l.pHead = l.pTail = NULL;
}

NODE *CreateNode(DATA data)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        return NULL;
    }
    p->data = data;
    p->pNext = NULL;
    return p;
}

void pushBack(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void push(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void pushAfter(LIST &l, NODE *p, NODE *q)
{
    if (q == l.pTail)
    {
        pushBack(l, p);
    }
    else
    {
        p->pNext = q->pNext;
        q->pNext = p;
    }
}

void pushFront(LIST &l, NODE *p, NODE *q)
{
    if (q == l.pHead)
    {
        push(l, p);
    }
    else
    {
        NODE *k = l.pHead;
        while (k->pNext != q)
        {
            k = k->pNext;
        }
        pushAfter(l, p, k);
    }
}

void input(LIST &l, NODE *p)
{
    NODE *q = l.pHead;
    if (q == NULL)
    {
        push(l, p);
        return;
    }
    if (q->data.x >= p->data.x)
    {
        push(l, p);
        return;
    }
    while (q != NULL)
    {
        if (q->data.x >= p->data.x)
        {
            pushFront(l, p, q);
            return;
        }
        q = q->pNext;
    }
    pushBack(l, p);
}

void printList(LIST l)
{
    if (l.pHead == NULL)
    {
        cout << "NULL";
        return;
    }
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        cout << k->data.x << " ";
    }
}

int main(){
    long long n;
    cin >> n;
    LIST l;
    CreateList(l);
    for (long long i = 0; i < n; i++)
    {
        DATA data;
        cin >> data.x;
        NODE *p = CreateNode(data);
        input(l, p);
        printList(l);
        cout << endl;
    }
}