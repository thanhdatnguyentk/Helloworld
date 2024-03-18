#include<bits/stdc++.h>
#include"Bai02.h"
#include"PhanSo.cpp"
using namespace std;

int main(){
    PhanSo a, b, c;
    a.Nhap();
    b.Nhap();

    c = a + b;
    cout << " + :" << endl;
    c.Xuat();

    c = a - b;
    cout << " - :" << endl;
    c.Xuat();
    
    c = a * b;
    cout << " * :" << endl;
    c.Xuat();

    c = a / b;
    cout << " / :" << endl;
    c.Xuat();

    c.~PhanSo();
}
