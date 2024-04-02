#ifndef PHANSO_H
#define PHANSO_H

#include <bits/stdc++.h>

using namespace std;

class PhanSo
{
private:
    int *TuSo;
    int *MauSo;

public:
    // Phep gan
    PhanSo &operator=(const PhanSo &ps);
    // Toan tu 2 ngoi
    PhanSo operator+(const PhanSo &ps);
    PhanSo operator-(const PhanSo &ps);
    PhanSo operator*(const PhanSo &ps);
    PhanSo operator/(const PhanSo &ps);
    PhanSo& operator+=(const PhanSo &ps);
    PhanSo& operator-=(const PhanSo &ps);
    PhanSo& operator*=(const PhanSo &ps);
    PhanSo& operator/=(const PhanSo &ps);
    // Toan tu so sanh
    bool operator==(const PhanSo &ps);
    bool operator!=(const PhanSo &ps);
    bool operator>(const PhanSo &ps);
    bool operator<(const PhanSo &ps);
    bool operator>=(const PhanSo &ps);
    bool operator<=(const PhanSo &ps);
    // Toan tu tien to hau to ngoi
    PhanSo &operator++();
    PhanSo &operator--();
    PhanSo operator++(int);
    PhanSo operator--(int);
    // toan tu nhap xuat
    friend istream &operator>>(istream &is, PhanSo &ps)
    {
        cout << "Nhap tu so: ";
        is >> *ps.TuSo;
        cout << "Nhap mau so: ";
        is >> *ps.MauSo;
        return is;
    }
    friend ostream &operator<<(ostream &os, PhanSo &ps)
    {
        os << *ps.TuSo << "/" << *ps.MauSo;
        return os;
    }
    // Ham tao
    PhanSo();
    // Ham huy
    ~PhanSo();
};
// Ham gan
PhanSo& PhanSo::operator=(const PhanSo &ps)
{
    *TuSo = *ps.TuSo;
    *MauSo = *ps.MauSo;
    return *this;
}
// Toan tu 2 ngoi
PhanSo PhanSo::operator+(const PhanSo &ps)
{
    PhanSo temp;
    temp.TuSo = new int;
    temp.MauSo = new int;
    *temp.TuSo = *TuSo * *ps.MauSo + *MauSo * *ps.TuSo;
    *temp.MauSo = *MauSo * *ps.MauSo;
    return temp;
}
PhanSo PhanSo::operator-(const PhanSo &ps)
{
    PhanSo temp;
    temp.TuSo = new int;
    temp.MauSo = new int;
    *temp.TuSo = *TuSo * *ps.MauSo - *MauSo * *ps.TuSo;
    *temp.MauSo = *MauSo * *ps.MauSo;
    return temp;
}
PhanSo PhanSo::operator*(const PhanSo &ps)
{
    PhanSo temp;
    temp.TuSo = new int;
    temp.MauSo = new int;
    *temp.TuSo = *TuSo * *ps.TuSo;
    *temp.MauSo = *MauSo * *ps.MauSo;
    return temp;
}
PhanSo PhanSo::operator/(const PhanSo &ps)
{
    PhanSo temp;
    temp.TuSo = new int;
    temp.MauSo = new int;
    *temp.TuSo = *TuSo * *ps.MauSo;
    *temp.MauSo = *MauSo * *ps.TuSo;
    return temp;
}
PhanSo& PhanSo::operator+=(const PhanSo &ps)
{
    *TuSo = *TuSo * *ps.MauSo + *MauSo * *ps.TuSo;
    *MauSo = *MauSo * *ps.MauSo;
    return *this;
}
PhanSo& PhanSo::operator-=(const PhanSo &ps)
{
    *TuSo = *TuSo * *ps.MauSo - *MauSo * *ps.TuSo;
    *MauSo = *MauSo * *ps.MauSo;
    return *this;
}
PhanSo& PhanSo::operator*=(const PhanSo &ps)
{
    *TuSo = *TuSo * *ps.TuSo;
    *MauSo = *MauSo * *ps.MauSo;
    return *this;
}
PhanSo& PhanSo::operator/=(const PhanSo &ps)
{
    *TuSo = *TuSo * *ps.MauSo;
    *MauSo = *MauSo * *ps.TuSo;
    return *this;
}
// Toan tu so sanh
bool PhanSo::operator==(const PhanSo &ps)
{
    return *TuSo * *ps.MauSo == *MauSo * *ps.TuSo;
}
bool PhanSo::operator!=(const PhanSo &ps)
{
    return *TuSo * *ps.MauSo != *MauSo * *ps.TuSo;
}
bool PhanSo::operator>(const PhanSo &ps)
{
    return *TuSo * *ps.MauSo > *MauSo * *ps.TuSo;
}
bool PhanSo::operator<(const PhanSo &ps)
{
    return *TuSo * *ps.MauSo < *MauSo * *ps.TuSo;
}
bool PhanSo::operator>=(const PhanSo &ps)
{
    return *TuSo * *ps.MauSo >= *MauSo * *ps.TuSo;
}
bool PhanSo::operator<=(const PhanSo &ps)
{
    return *TuSo * *ps.MauSo <= *MauSo * *ps.TuSo;
}
// Toan tu tien to hau to ngoi
PhanSo& PhanSo::operator++()
{
    *TuSo = *TuSo + *MauSo;
    return *this;
}
PhanSo& PhanSo::operator--()
{
    *TuSo = *TuSo - *MauSo;
    return *this;
}
PhanSo PhanSo::operator++(int)
{
    PhanSo temp = *this;
    *TuSo = *TuSo + *MauSo;
    return temp;
}
PhanSo PhanSo::operator--(int)
{
    PhanSo temp = *this;
    *TuSo = *TuSo - *MauSo;
    return temp;
}
// Ham tao
PhanSo::PhanSo()
{
    TuSo = new int;
    MauSo = new int;
    *TuSo = 0;
    *MauSo = 1;
}
// Ham huy
PhanSo::~PhanSo()
{
    delete TuSo;
    delete MauSo;
    cout << "Da huy phan so" << endl;
}


#endif