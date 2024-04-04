#include <iostream>
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
    if (q == NULL)
    {
        return;
    }
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

void printList(LIST l)
{
    if (l.pHead == NULL)
    {
        cout <<"NULL";
        return;
    }
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        cout << k->data.x << " ";
    }
    cout << endl;
}
int size(LIST l)
{
    int count = 0;
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        count++;
    }
    return count;
}

int index(LIST l, NODE *p)
{
    int count = 1;
    for (NODE *k = l.pHead; k != p; k = k->pNext)
    {
        count++;
    }
    return count;
}

bool prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int check(LIST l)
{
    int count = 0;
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (prime(k->data.x) == 1 && index(l, k) % 2 == 1)
        {
            count++;
        }
    }
    return count;
}
// int pp[10000];
void printAttemp(LIST l)
{
    cout << "So lan xuat hien cua tung phan tu trong danh sach la:" << endl;
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (pp[k->data.x] == 0)
        {
            int count = 1;
            for (NODE *h = k->pNext; h != NULL; h = h->pNext)
            {
                if (h->data.x == k->data.x)
                {
                    count++;
                }
            }
            cout << k->data.x << ": " << count << endl;
            pp[k->data.x] = 1;
        }
    }
}

void split(LIST l, LIST &l1, LIST &l2)
{
    CreateList(l1);
    CreateList(l2);
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (pp[k->data.x] == 1)
        {
            continue;
        }
        if (k->data.x % 2 == 0)
        {
            pushBack(l1, CreateNode(k->data));
        }
        else
        {
            pushBack(l2, CreateNode(k->data));
        }
        pp[k->data.x] = 1;
    }
    cout << "Cac so chan trong danh sach la: ";
    printList(l1);
    cout << "Cac so le trong danh sach la: ";
    printList(l2);
}

void deleteNode(LIST &l, NODE *p)
{
    if (p == NULL)
    {
        return;
    }
    if (p == l.pHead)
    {
        l.pHead = l.pHead->pNext;
        delete p;
    }
    else
    {
        NODE *k = l.pHead;
        while (k->pNext != p)
        {
            k = k->pNext;
        }
        k->pNext = p->pNext;
        delete p;
    }
}

void selection(LIST &l, int n, int p)
{
    if (n == 1)
    {
        push(l, CreateNode({p}));
    }
    else if (n == 2)
    {
        pushBack(l, CreateNode({p}));
    }
    else if (n == 3)
    {
        NODE *k = l.pHead;
        while(k != NULL)
        {
            NODE *h = k->pNext;
            if(k->data.x == p)
            {
                deleteNode(l, k);
            }
            k = h;
        }
    }
    else if (n == 4)
    {
        cout << check(l) << endl;
    }
    else if (n == 5)
    {
        printAttemp(l);
    }
    else if (n == 6)
    {
        LIST l1, l2;
        split(l, l1, l2);
    }
}
void search(LIST l, int x)
{
    int count = 0;
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        count++;
        if (count == x)
        {
            /* code */
            cout << k->data.x << endl;
            return;
        }   
    }
}

void deleteList(LIST &l)
{
    NODE *k = l.pHead;
    while (k != NULL)
    {
        NODE *p = k;
        k = k->pNext;
        delete p;
    }
    l.pHead = l.pTail = NULL;
}

int main()
{
    long long n;
    cin >> n;
    LIST l;
    CreateList(l);
    while (n != 0)
    {
        DATA data;
        data.x = n;
        pushBack(l, CreateNode(data));
        cin >> n;
    }
    int m = size(l) / 2 + 1;
    search(l, m);
}