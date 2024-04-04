
#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
    int info;
    Node* pNext;
};

struct List
{
    Node* pHead;
    Node* pTail;
};
 
void CreateList(List &l);
void NhapList(List &l);
int DemSoPhanTu(List l);
void Split(List l, List &l1, List &l2);
void XuatList(List l);

void CreateList(List &l)
{
    l.pHead = l.pTail = NULL;
}

Node* CreateNode(int x)
{
    Node* p = new Node;
    if(p == NULL)
    {
        return NULL;
    }
    p->info = x;
    p->pNext = NULL;
    return p;
}

void pushBack(List &l, Node* p)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void push(List &l, Node* p)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void NhapList(List &l)
{
    long long n;
    cin >> n;
    while (n != 0)
    {
        pushBack(l, CreateNode(n));
        cin >> n;
    }
}
int pp[10000];
void Split(List l, List &l1, List &l2)
{
    CreateList(l1);
    CreateList(l2);
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {   
        if (pp[p->info] == 1)
        {
            continue;
        }
        if(p->info % 2 == 0)
        {
            pushBack(l1, CreateNode(p->info));
 
        }
        else
        {
            pushBack(l2, CreateNode(p->info));

        }
        pp[p->info] = 1;
    }
}
int DemSoPhanTu(List l)
{
    int dem = 0;
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        dem++;
    }
    return dem;
}

void XuatList(List l)
{
    for(Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->info << " ";
    }
}

int main()
{
	List l, l1, l2;
	CreateList(l);
	CreateList(l1);
	CreateList(l2);
	NhapList(l);
	if(DemSoPhanTu(l) == 0)
		cout << "Danh sach rong." << endl;
	else
	{
		cout << "Danh sach vua nhap la: ";
		XuatList(l);
		cout << endl;
		Split(l, l1, l2);
		cout << "Cac so chan trong danh sach la: ";
		XuatList(l1);
		cout << endl;
		cout << "Cac so le trong danh sach la: ";
		XuatList(l2);
		cout << endl;
	}
	return 0;
}

