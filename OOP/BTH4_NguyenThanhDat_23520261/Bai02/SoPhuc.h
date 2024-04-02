#ifndef SOPHUC_H
#define SOPHUC_H

#include <bits/stdc++.h>

using namespace std;

class SoPhuc
{
private:
    float *PhanThuc;
    float *PhanAo;
public:
    // Phep gan
    SoPhuc &operator=(const SoPhuc &sp);
    // Toan tu 2 ngoi
    SoPhuc operator+(const SoPhuc &sp);
    SoPhuc operator-(const SoPhuc &sp);
    SoPhuc operator*(const SoPhuc &sp);
    SoPhuc operator/(const SoPhuc &sp);
    SoPhuc& operator+=(const SoPhuc &sp);
    SoPhuc& operator-=(const SoPhuc &sp);
    SoPhuc& operator*=(const SoPhuc &sp);
    SoPhuc& operator/=(const SoPhuc &sp);
    // Toan tu so sanh
    bool operator==(const SoPhuc &sp);
    bool operator!=(const SoPhuc &sp);
    bool operator>(const SoPhuc &sp);
    bool operator<(const SoPhuc &sp);
    bool operator>=(const SoPhuc &sp);
    bool operator<=(const SoPhuc &sp);
    // Toan tu tien to hau to ngoi
    SoPhuc &operator++();
    SoPhuc &operator--();
    SoPhuc operator++(int);
    SoPhuc operator--(int);
    // toan tu nhap xuat
    friend istream &operator>>(istream &is, SoPhuc &sp)
    {
        cout << "Nhap phan thuc: ";
        is >> *sp.PhanThuc;
        cout << "Nhap phan ao: ";
        is >> *sp.PhanAo;
        return is;
    }
    friend ostream &operator<<(ostream &os, SoPhuc &sp)
    {
        os << *sp.PhanThuc << " + " << *sp.PhanAo << "i";
        return os;
    }
    // Ham tao
    SoPhuc();
    // Ham huy
    ~SoPhuc();
};
// Ham gan
SoPhuc& SoPhuc::operator=(const SoPhuc &sp)
{
    *PhanThuc = *sp.PhanThuc;
    *PhanAo = *sp.PhanAo;
    return *this;
}
// Ham tao
SoPhuc::SoPhuc()
{
    PhanThuc = new float;
    PhanAo = new float;
}
// Ham huy
SoPhuc::~SoPhuc()
{
    delete PhanThuc;
    delete PhanAo;
}
// Toan tu 2 ngoi
SoPhuc SoPhuc::operator+(const SoPhuc &sp)
{
    SoPhuc temp;
    temp.PhanThuc = new float;
    temp.PhanAo = new float;
    *temp.PhanThuc = *PhanThuc + *sp.PhanThuc;
    *temp.PhanAo = *PhanAo + *sp.PhanAo;
    return temp;
}
SoPhuc SoPhuc::operator-(const SoPhuc &sp)
{
    SoPhuc temp;
    temp.PhanThuc = new float;
    temp.PhanAo = new float;
    *temp.PhanThuc = *PhanThuc - *sp.PhanThuc;
    *temp.PhanAo = *PhanAo - *sp.PhanAo;
    return temp;
}
SoPhuc SoPhuc::operator*(const SoPhuc &sp)
{
    SoPhuc temp;
    temp.PhanThuc = new float;
    temp.PhanAo = new float;
    *temp.PhanThuc = *PhanThuc * *sp.PhanThuc - *PhanAo * *sp.PhanAo;
    *temp.PhanAo = *PhanThuc * *sp.PhanAo + *PhanAo * *sp.PhanThuc;
    return temp;
}
SoPhuc SoPhuc::operator/(const SoPhuc &sp)
{
    SoPhuc temp;
    temp.PhanThuc = new float;
    temp.PhanAo = new float;
    *temp.PhanThuc = (*PhanThuc * *sp.PhanThuc + *PhanAo * *sp.PhanAo) / (*sp.PhanThuc * *sp.PhanThuc + *sp.PhanAo * *sp.PhanAo);
    *temp.PhanAo = (*PhanAo * *sp.PhanThuc - *PhanThuc * *sp.PhanAo) / (*sp.PhanThuc * *sp.PhanThuc + *sp.PhanAo * *sp.PhanAo);
    return temp;
}
SoPhuc& SoPhuc::operator+=(const SoPhuc &sp)
{
    *PhanThuc = *PhanThuc + *sp.PhanThuc;
    *PhanAo = *PhanAo + *sp.PhanAo;
    return *this;
}
SoPhuc& SoPhuc::operator-=(const SoPhuc &sp)
{
    *PhanThuc = *PhanThuc - *sp.PhanThuc;
    *PhanAo = *PhanAo - *sp.PhanAo;
    return *this;
}
SoPhuc& SoPhuc::operator*=(const SoPhuc &sp)
{
    *PhanThuc = *PhanThuc * *sp.PhanThuc - *PhanAo * *sp.PhanAo;
    *PhanAo = *PhanThuc * *sp.PhanAo + *PhanAo * *sp.PhanThuc;
    return *this;
}
SoPhuc& SoPhuc::operator/=(const SoPhuc &sp)
{
    *PhanThuc = (*PhanThuc * *sp.PhanThuc + *PhanAo * *sp.PhanAo) / (*sp.PhanThuc * *sp.PhanThuc + *sp.PhanAo * *sp.PhanAo);
    *PhanAo = (*PhanAo * *sp.PhanThuc - *PhanThuc * *sp.PhanAo) / (*sp.PhanThuc * *sp.PhanThuc + *sp.PhanAo * *sp.PhanAo);
    return *this;
}
// Toan tu so sanh
bool SoPhuc::operator==(const SoPhuc &sp)
{
    return *PhanThuc == *sp.PhanThuc && *PhanAo == *sp.PhanAo;
}
bool SoPhuc::operator!=(const SoPhuc &sp)
{
    return *PhanThuc != *sp.PhanThuc || *PhanAo != *sp.PhanAo;
}
bool SoPhuc::operator>(const SoPhuc &sp)
{
    return *PhanThuc > *sp.PhanThuc && *PhanAo > *sp.PhanAo;
}
bool SoPhuc::operator<(const SoPhuc &sp)
{
    return *PhanThuc < *sp.PhanThuc && *PhanAo < *sp.PhanAo;
}
bool SoPhuc::operator>=(const SoPhuc &sp)
{
    return *PhanThuc >= *sp.PhanThuc && *PhanAo >= *sp.PhanAo;
}
bool SoPhuc::operator<=(const SoPhuc &sp)
{
    return *PhanThuc <= *sp.PhanThuc && *PhanAo <= *sp.PhanAo;
}
// Toan tu tien to hau to ngoi
SoPhuc& SoPhuc::operator++()
{
    *PhanThuc = *PhanThuc + 1;
    return *this;
}
SoPhuc& SoPhuc::operator--()
{
    *PhanThuc = *PhanThuc - 1;
    return *this;
}
SoPhuc SoPhuc::operator++(int)
{
    SoPhuc temp = *this;
    *PhanThuc = *PhanThuc + 1;
    return temp;
}
SoPhuc SoPhuc::operator--(int)
{
    SoPhuc temp = *this;
    *PhanThuc = *PhanThuc - 1;
    return temp;
}



#endif