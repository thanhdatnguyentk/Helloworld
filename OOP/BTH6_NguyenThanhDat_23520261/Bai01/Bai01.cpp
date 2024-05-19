#include"NhanSu.h"
#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<Canbo*> list, NN, Ngoai;
    int n;
    cout << "Nhap so luong can bo: " ;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cout << "Nhan su thu "<< i <<" La nhan su thuoc bien che hay la hop dong: " << endl;
        cout << "1. Thuoc bien che" << endl;
        cout << "2. Hop dong"<< endl;
        cin >> x;
       while (x != 1 && x != 2) {
            cout << "Moi ban nhap lai :" << endl;
            cin >> x;
        }
        if (x == 1) {
            CBNhaNuoc *cb = new CBNhaNuoc;
            cb -> Nhap();
            list.push_back(cb);
            NN.push_back(cb);
        }
        else
        {
            CBNgoai *cb = new CBNgoai;
            cb -> Nhap();
            list.push_back(cb);
            Ngoai.push_back(cb);
        }
    }
    cout << "Danh sach can bo: " << endl;
    for(auto i : list){
        i->Xuat();
    }
    cout << "Danh sach can bo nha nuoc: " << endl;
    for(auto i : NN){
        i->Xuat();
    }
    cout << "Danh sach can bo ngoai nha nuoc: " << endl;
    for(auto i : Ngoai){
        i->Xuat();
    }

    double tongLuong = 0;
    for(auto i : list){
        i->TinhLuong();
        tongLuong += i->salary;
    }

    cout << "Tong luong cua cong ty la: ";
    cout << tongLuong << endl;
}