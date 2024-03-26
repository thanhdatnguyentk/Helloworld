#ifndef HOCSINH_H
#define HOCSINH_H
#include <bits/stdc++.h>
using namespace std;

bool check(string s);

class HocSinh
{
private:
    string name;
    string code;
    string phoneNumber;
    float diem;

public:
    void Nhap();
    void Xuat();
    string getCode()
    {
        return code;
    }
    string getName()
    {
        return name;
    }
    string getPhoneNumber()
    {
        return phoneNumber;
    }
    float getDiem()
    {
        return diem;
    }
    void setCode(string s)
    {
        code = s;
    }
    void setName(string s)
    {
        name = s;
    }
    void setPhoneNumber(string s)
    {
        phoneNumber = s;
    }
    void setDiem(float s)
    {
        diem = s;
    }
    HocSinh();
    bool exits(vector<HocSinh> list);
    ~HocSinh();
};

HocSinh::HocSinh(/* args */)
{
}

HocSinh::~HocSinh()
{
}

void HocSinh::Nhap()
{
    cout << "Nhap ten hoc sinh: ";

    getline(cin, name);
    cout << "Nhap ma hoc sinh: ";

    getline(cin, code);
    while (code.length() != 8)
    {
        cout << "Ma hoc sinh phai co 8 ki tu. Nhap lai: ";

        getline(cin, code);
    }
    cout << "Nhap so dien thoai: ";

    getline(cin, phoneNumber);
    while (phoneNumber.length() != 10 || check(phoneNumber) == false)
    {
        cout << "So dien thoai phai co 10 ki tu. Va 10 ki tu phai la so. Moi nhap lai: ";

        getline(cin, phoneNumber);
    }
    cout << "Nhap diem: ";
    cin >> diem;
    while (diem < 0 || diem > 10)
    {
        cout << "Diem phai tu 0 den 10. Nhap lai: ";
        cin >> diem;
    }
}

void HocSinh::Xuat()
{
    cout << "Ten hoc sinh: " << name << endl;
    cout << "Ma hoc sinh: " << code << endl;
    cout << "So dien thoai: " << phoneNumber << endl;
    cout << "Diem: " << diem << endl;
}
bool check(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return false;
        }
    }
    return true;
}
#endif