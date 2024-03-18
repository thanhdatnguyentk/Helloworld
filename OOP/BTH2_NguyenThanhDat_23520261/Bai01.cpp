#include<bits/stdc++.h>
#include"Bai01.h"
#include"NhanVien.cpp"
using namespace std;

int main(){
    NhanVien a, b, c;
    long long day = 1;
    string name = "Nguyen Thanh Dat";
    a.nhap();
    a.xuat();
    cin.ignore();
    getline(cin,name);
    cin >> day;
    b = NhanVien(name, day);
    b.xuat();
    c = b;
    c.xuat();
    a.~NhanVien();
    b.~NhanVien();
    c.~NhanVien();
}
