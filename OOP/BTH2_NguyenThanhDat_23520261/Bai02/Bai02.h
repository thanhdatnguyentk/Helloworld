#ifndef PHANSO_H
#define PHANSO_H
#include<bits/stdc++.h>

using namespace std;

class PhanSo
{
private:
    int mau, tu;
public:
    void Nhap();
    void Xuat();
    void GiaTri();
    PhanSo operator+(const PhanSo a);
    PhanSo operator-(const PhanSo a);
    PhanSo operator*(const PhanSo a);
    PhanSo operator/(const PhanSo a);
    bool operator==(const PhanSo a);

    int get_mau();
    int get_tu();
    void set_mau(int a);
    void set_tu(int a);
    PhanSo( PhanSo &temp);
    PhanSo();
    ~PhanSo();
    PhanSo better(PhanSo &temp);
    PhanSo worse(PhanSo &temp);

};

#endif
