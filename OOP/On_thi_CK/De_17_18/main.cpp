#include"caSi.h"

int main(){
    vector<CaSi*> list;
    int n;
    cout << "Nhap so luong ca si: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        int type;
        cout << "Nhap loai ca si (1. Noi tieng, 2. Chua noi tieng): ";
        cin >> type;
        CaSi* caSi;
        if(type == 1){
            caSi = new CaSiNoiTieng();
        }else if(type == 2){
            caSi = new CaSiChuaNoiTieng();
        }
        caSi->Nhap();
        list.push_back(caSi);
    }
    cout << "Danh sach ca si: " << endl;
    for(int i = 0; i < n; i++){
        list[i]->Xuat();
    }

    cout << "Ca si co luong cao nhat: " << endl;
    int max = list[0]->TinhLuong();
    CaSi *maxCaSi = list[0];
    for(int i = 1; i < n; i++){
        if(list[i]->TinhLuong() > max){
            max = list[i]->TinhLuong();
            maxCaSi = list[i];
        }
    }
    maxCaSi->Xuat();
}