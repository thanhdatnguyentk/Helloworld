#ifndef NHANVIEN_H
#define NHANVIEN_H


#include <bits/stdc++.h>

using namespace std;

class NhanVien{
private:
    /* data */
    string HoVaTen;
    long long Day;
    string MaSoNhanVien;
    string ChucDanh;
    float HeSoLuong;

public:
    string GetName()
    {
        return HoVaTen;
    }
    long long GetDay()
    {
        return Day;
    }
    string GetCode()
    {
        return MaSoNhanVien;
    }
    string GetTitle()
    {
        return ChucDanh;
    }
    float GetSalary()
    {
        return HeSoLuong;
    }

    void SetName(string name)
    {
        this->HoVaTen = name;
    }
    void SetDay(long long day)
    {
        this->Day = day;
    }
    void SetCode(string code)
    {
        this->MaSoNhanVien = code;
    }
    void SetTitle(string title)
    {
        this->ChucDanh = title;
    }
    void SetSalary(float salary)
    {
        this->HeSoLuong = salary;
    }
    NhanVien(string HoVaTen, long long day);
    void nhap();
    void xuat();
    NhanVien(const NhanVien &temp);
    NhanVien();
    ~NhanVien();
};
#endif