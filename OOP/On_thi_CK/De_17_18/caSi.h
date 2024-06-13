#ifndef CASI_H
#define CASI_H

#include<bits/stdc++.h>

using namespace std;

class CaSi
{
    protected:
        string ten;
        int nam;
        int soDia;
        int soBuoi;
    public:
        virtual void Nhap() = 0;
        void Xuat();
        virtual int TinhLuong() = 0;
};


void CaSi::Xuat()
{
    cout << "Ten ca si: " << ten << endl;
    cout << "Nam sinh: " << nam << endl;
    cout << "So dia: " << soDia << endl;
    cout << "So buoi: " << soBuoi << endl;
}

class CaSiNoiTieng : public CaSi
{
    private:
        int soGame;
    public:
        void Nhap();
        int TinhLuong();
};

void CaSiNoiTieng::Nhap()
{
    cout << "Nhap ten ca si: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Nhap nam sinh: ";
    cin >> nam;
    cout << "Nhap so dia: ";
    cin >> soDia;
    cout << "Nhap so buoi: ";
    cin >> soBuoi;
    cout << "Nhap so game: ";
    cin >> soGame;
}

int CaSiNoiTieng::TinhLuong()
{
    return 5000000 + 500000 * nam + 1200 * soDia + 500000 * soBuoi + 500000 * soGame;
}

class CaSiChuaNoiTieng : public CaSi
{
    public:
        void Nhap();
        int TinhLuong();
};

void CaSiChuaNoiTieng::Nhap()
{
    cout << "Nhap ten ca si: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Nhap nam sinh: ";
    cin >> nam;
    cout << "Nhap so dia: ";
    cin >> soDia;
    cout << "Nhap so buoi: ";
    cin >> soBuoi;
}

int CaSiChuaNoiTieng::TinhLuong()
{
    return 3000000 + 500000 * nam + 1000 * soDia + 200000 * soBuoi;
}


#endif 
