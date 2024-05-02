#include"GiaSuc.h"
#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<GiaSuc*> list;
    int n;
    cout << "Nhap so luong gia suc: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        int type;
        cout << "Nhap loai gia suc (1. Bo, 2. Cuu, 3. De): ";
        cin >> type;
        GiaSuc* giaSuc;
        if(type == 1){
            giaSuc = new Bo();
        }else if(type == 2){
            giaSuc = new Cuu();
        }else if(type == 3){
            giaSuc = new De();
        }
        giaSuc->Nhap();
        list.push_back(giaSuc);
    }
    cout << "Danh sach gia suc: " << endl;
    for(int i = 0; i < n; i++){
        list[i]->Xuat();
    }
    cout << "So luong bo: ";
    int dem = 0;
    for (auto i : list)
    {
        if (dynamic_cast<Bo*>(i) != nullptr)
        {
            dem++;
        }
    }
    cout << dem << endl;
    cout << "So luong cuu: ";
    dem = 0;
    for (auto i : list)
    {
        if (dynamic_cast<Cuu*>(i) != nullptr)
        {
            dem++;
        }
    }
    cout << dem << endl;
    cout << "So luong de: ";
    dem = 0;
    for (auto i : list)
    {
        if (dynamic_cast<De*>(i) != nullptr)
        {
            dem++;
        }
    }
    cout << dem << endl;

    int tongSua = 0;
    for(auto i : list){
        tongSua += i->Sua();
    }
    cout << "Tong so lit sua: " << tongSua << endl;
    cout << "So tieng keu: ";
    for(auto i : list){
        i->Keu();
    }
    return 0;
}