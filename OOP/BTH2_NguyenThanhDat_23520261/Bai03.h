#ifndef DSPHANSO_H
#define DSPHANSO_H
#include "PhanSo.cpp"

class DSPhanSo
{
private:
    PhanSo *p = new PhanSo[100];
    int n;

public:
    int get_so_luong();
    PhanSo get_gia_tri_thu_i(int i);
    void set_so_luong(int n);
    void set_so_luong_thu_i(int i, PhanSo a);
    void nhap();
    void xuat();
    PhanSo tong();
    PhanSo max();
    PhanSo min();
    void SapXepTangDan();
    void SapXepNhoDan();
    DSPhanSo();
    ~DSPhanSo();
};

#endif