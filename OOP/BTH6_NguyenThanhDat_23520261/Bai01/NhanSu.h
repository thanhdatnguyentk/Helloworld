#ifndef NHANSU_H
#define NHANSU_H
#include<bits/stdc++.h>

using namespace std;

class Canbo{
    private:
        string mscb, fullName, birthDay;
    public:
        double salary;
        virtual void TinhLuong()  = 0;
        void Nhap();
        void Xuat();
        ~Canbo();
};

void Canbo :: Nhap() {
    cout << "Nhap ma so can bo: ";
    cin >> mscb;
    cout << "Nhap ho ten can bo: ";
    cin.ignore();
    getline(cin, fullName);
    cout << "Nhap ngay sinh: ";
    cin.ignore();
    getline(cin, birthDay);
}

void Canbo :: Xuat() {
    cout << "Ma so can bo: " << mscb << endl;
    cout << "Ho ten can bo: " << fullName << endl;
    cout << "Ngay sinh: " << birthDay << endl;
}

Canbo :: ~Canbo() {
    cout << "Da huy doi tuong " << endl;
}

class CBNhaNuoc : public Canbo {
    private:
        double luongCoBan, heSoLuong, heSoPhuCap;
    public:
        void TinhLuong()  {
            this->salary = luongCoBan * heSoLuong * heSoPhuCap;
        }
        void Nhap();
        void Xuat();
        ~CBNhaNuoc();
};

void CBNhaNuoc :: Nhap() {
    Canbo :: Nhap();
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
    cout << "Nhap he so luong: ";
    cin >> heSoLuong;
    cout << "Nhap he so phu cap: ";
    cin >> heSoPhuCap;
}
void CBNhaNuoc :: Xuat() {
    Canbo :: Xuat();
    cout << "Luong :" << salary << endl;
}

CBNhaNuoc :: ~CBNhaNuoc() {
    cout << "Da huy doi tuong " << endl;
}

class CBNgoai : public Canbo {
    private:
        double tienCong, soNgayCong, heSoVuotGio;
    public:
        void TinhLuong()  {
            this->salary = tienCong * soNgayCong * heSoVuotGio;
        }
        void Nhap();
        void Xuat();
        ~CBNgoai();
};

void CBNgoai :: Nhap() {
    Canbo :: Nhap();
    cout << "Nhap tien cong: ";
    cin >> tienCong;
    cout << "Nhap so ngay cong: ";
    cin >> soNgayCong;
    cout << "Nhap he so vuot gio: ";
    cin >> heSoVuotGio;
}
void CBNgoai :: Xuat() {
    Canbo :: Xuat();
    cout << "Luong :" << salary << endl;
}

CBNgoai :: ~CBNgoai() {
    cout << "Da huy doi tuong " << endl;
}


#endif