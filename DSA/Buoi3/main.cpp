#include <bits/stdc++.h>

using namespace std;

struct sinhVien
{
    string maSV;
    string hoTen;
    float diemTB;
};

struct node
{
    sinhVien data;
    node *next;
};

struct listSV
{
    node *head;
    node *tail;
};
void createList(listSV &l);
node *createNode(sinhVien x);
void addHead(listSV &l, node *temp);
void inputList(listSV &l);
void printList(listSV l);
void searchList(listSV l);
void searchListByName(listSV l);
void deleteList(listSV &l);
void printAverage5(listSV l);
void sortList(listSV &l);
void printXLList(listSV l);
void addSinhVienAsSort(listSV &l, sinhVien x);


void createList(listSV &l)
{
    l.head = NULL;
    l.tail = NULL;
}

node *createNode(sinhVien x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void addHead(listSV &l, node *temp)
{
    if (l.head == NULL)
    {
        l.head = temp;
        l.tail = temp;
    }
    else
    {
        temp->next = l.head;
        l.head = temp;
    }
}

void inputList(listSV &l)
{
    sinhVien x;
    cout << "Nhap so sinh vien: ";
    getline(cin, x.maSV);

    while ( x.maSV.length() != 1)
    {
        cout << "Nhap ho ten: ";
        getline(cin, x.hoTen);
        cout << "Nhap diem trung binh: ";
        cin >> x.diemTB;
        node *temp = createNode(x);
        addHead(l, temp);
        cout << "Nhap so sinh vien: ";
        cin.ignore();   
        getline(cin, x.maSV);
    }
    cout << " Nhap xong danh sach sinh vien" << endl;
}

void printList(listSV l)
{
    cout << "Danh sach sinh vien:" << endl;
    for (node *i = l.head; i != NULL; i = i->next)
    {
        cout << i->data.maSV << " " << i->data.hoTen << " " << i->data.diemTB << endl;
    }
}
void searchList(listSV l)
{
    string ma;
    cout << "Nhap ma sinh vien can tim: ";
    cin >> ma;
    for (node *i = l.head; i != NULL; i = i->next)
    {
        if (i->data.maSV == ma)
        {
            cout << i->data.maSV << " " << i->data.hoTen << " " << i->data.diemTB << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien co ma " << ma << endl;
}
void searchListByName(listSV l)
{
    string hoTen;
    cout << "Nhap ten sinh vien can tim: ";
    cin.ignore();
    getline(cin, hoTen);
    for (node *i = l.head; i != NULL; i = i->next)
    {
        if (i->data.hoTen == hoTen)
        {
            cout << i->data.maSV << " " << i->data.hoTen << " " << i->data.diemTB << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien co ten " << hoTen << endl;
}

void deleteList(listSV &l)
{
    string ma;
    cout << "Nhap ma sinh vien can xoa: ";
    cin >> ma;
    node *prev = NULL;
    for (node *i = l.head; i != NULL; i = i->next)
    {
        if (i->data.maSV == ma)
        {
            if (prev == NULL)
            {
                l.head = i->next;
            }
            else
            {
                prev->next = i->next;
            }
            delete i;
            cout << "Xoa thanh cong sinh vien co ma " << ma << endl;
            return;
        }
        prev = i;
    }
    cout << "Khong tim thay sinh vien co ma " << ma << endl;
}

void printAverage5(listSV l)
{
    cout << "Cac sinh vien co diem trung binh >= 5:" << endl;
    for (node *i = l.head; i != NULL; i = i->next)
    {
        if (i->data.diemTB >= 5)
        {
            cout << i->data.maSV << " " << i->data.hoTen << " " << i->data.diemTB << endl;
        }
    }
}

void sortList(listSV &l)
{
    for (node *i = l.head; i != NULL; i = i->next)
    {
        for (node *j = i->next; j != NULL; j = j->next)
        {
            if (i->data.diemTB > j->data.diemTB)
            {
                swap(i->data, j->data);
            }
        }
    }
    cout <<" Danh sach da duoc sap xep" << endl;
}

void printXLList(listSV l)
{
    for (node *i = l.head; i != NULL; i = i->next)
    {
        cout << i->data.maSV << " " << i->data.hoTen << " " << i->data.diemTB << " ";
        if (i->data.diemTB <= 3.5)
        {
            cout << " Loai Kem" << endl;
        }
        else if (i->data.diemTB <= 5)
        {
            cout << " Loai Yeu";
        }
        else if (i->data.diemTB <= 6.5)
        {
            cout << " Loai Trung Binh";
        }
        else if (i->data.diemTB <= 7)
        {
            cout << " Loai Trung Binh Kha";
        }
        else if (i->data.diemTB <= 8)
        {
            cout << " Loai Kha";
        }
        else if (i->data.diemTB <= 9)
        {
            cout << " Loai Gioi";
        }
        else
        {
            cout << " Loai Xuat Sac";
        }
        cout << endl;
    }
}

void addSinhVienAsSort(listSV &l, sinhVien x)
{
    node *temp = createNode(x);
    if (l.head == NULL)
    {
        l.head = temp;
        l.tail = temp;
    }
    else
    {
        if (l.head->data.diemTB > x.diemTB)
        {
            temp->next = l.head;
            l.head = temp;
        }
        else if (l.tail->data.diemTB < x.diemTB)
        {
            l.tail->next = temp;
            l.tail = temp;
        }
        else
        {
            for (node *i = l.head; i != NULL; i = i->next)
            {
                if (i->next->data.diemTB > x.diemTB)
                {
                    temp->next = i->next;
                    i->next = temp;
                    return;
                }
            }
        }
    }
    cout << "Them sinh vien thanh cong" << endl;
}
int main()
{
    listSV l;
    createList(l);
    inputList(l);
    printList(l);
    searchList(l);
    searchListByName(l);
    deleteList(l);
    printAverage5(l);
    printXLList(l);
    sortList(l);
    printList(l);
    addSinhVienAsSort(l, {"08", "Nguyen Van Hanh", 8});
    printList(l);
    return 0;
}