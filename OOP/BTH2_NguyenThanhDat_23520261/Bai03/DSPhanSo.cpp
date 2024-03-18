#include "Bai03.h"

int DSPhanSo::get_so_luong()
{
    return this->n;
}

PhanSo DSPhanSo::get_gia_tri_thu_i(int i)
{
    return *(p + i);
}
void DSPhanSo::set_so_luong(int n)
{
    this->n = n;
}
void DSPhanSo::set_so_luong_thu_i(int i, PhanSo a){
    *(p+i) = a;
}

void DSPhanSo::nhap()
{
    cout << " Moi ban nhap so luong phan so: ";
    cin >> this->n;
    for (int i = 0; i < n; i++)
    {
        cout << " Moi ban nhap phan so thu " << i + 1 << endl;
        (p + i)->Nhap();
    }
}
void DSPhanSo::xuat()
{
    for (int i = 0; i < n; i++)
    {
        cout << " Phan so thu " << i + 1 << endl;
        (p + i)->Xuat();
    }
}
PhanSo DSPhanSo::tong()
{
    PhanSo res;
    for (int i = 0; i < n; i++)
    {
        res = res + *(p + i);
    }
    return res;
}
PhanSo DSPhanSo::max()
{
    PhanSo res;
    for (int i = 0; i < n; i++)
    {
        res = res.better(*(p + i));
    }
    return res;
}
PhanSo DSPhanSo::min()
{
    PhanSo res;
    res = *p;
    for (int i = 1; i < n; i++)
    {
        res = res.worse(*(p + i));
    }
    return res;
}
void DSPhanSo::SapXepTangDan()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((p + i)->better(*(p + j)) == *(p + i))
            {
                PhanSo temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }
}
void DSPhanSo::SapXepNhoDan()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (!((p + i)->better(*(p + j)) == *(p + i)))
            {
                PhanSo temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }
}

DSPhanSo::DSPhanSo()
{
    this->set_so_luong(0);
}
DSPhanSo::~DSPhanSo(){
    cout << " Da huy danh sach ";
}