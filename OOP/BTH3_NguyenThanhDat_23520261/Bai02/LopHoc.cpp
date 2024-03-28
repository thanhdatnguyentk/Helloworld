#include"Bai02.h"

LopHoc::LopHoc(/* args */)
{
}   

bool HocSinh::exits(vector<HocSinh> list)
{
    string name = getName();
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].getName() == name)
        {
            return true;
        }
    }
    return false;
}

void LopHoc::addStudent()
{
    HocSinh temp;
    temp.Nhap();
    if (temp.exits(list))
    {
        cout << "Da co hoc sinh trong lop" << endl;
        return;
    }
    list.push_back(temp);
    cout << "Them hoc sinh thanh cong" << endl;
}

void LopHoc::showList()
{
    for (int i = 0; i < list.size(); i++)
    {
        list[i].Xuat();
    }
}

void LopHoc::showStudent()
{
    for(auto i : list){
        if (i.getDiem() >= 8)
        {
            i.Xuat();
        }
    }
}

void LopHoc::removeStudent()
{
    string name;
    cout << "Nhap ten hoc sinh can xoa: ";
    getline(cin, name);
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].getName() == name)
        {
            list.erase(list.begin() + i);
            cout << "Xoa hoc sinh thanh cong" << endl;
            return;
        }
    }
    cout << "Khong co hoc sinh trong lop" << endl;
}

void LopHoc::searchStudent()
{
    string name;
    getline(cin, name);
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].getName() == name)
        {
            list[i].Xuat();
            return;
        }
    }
}

LopHoc::~LopHoc()
{
    cout << "Da huy lop hoc" << endl;
}