#include"DSPhanSo.cpp"
#include<bits/stdc++.h>
#include"Bai03.h"

int main(){
    DSPhanSo a;
    a.nhap();
    a.xuat();
    PhanSo c = a.tong();
    cout << " Tong cua danh sach la: " << endl;
    c.Xuat();
    c = a.max();
    cout << " Gia tri lon nhat cua danh sach la: " << endl;
    c.Xuat();
    c = a.min();
    cout << " Gia tri nho nhat cua danh sach la: " << endl;
    c.Xuat();
    a.SapXepTangDan();
    cout << " Day da duoc sap xep tang dan la:" << endl;
    a.xuat();
    a.SapXepNhoDan();
    cout << " Day da duoc sap xep nho dan la:" << endl;
    a.xuat();
}