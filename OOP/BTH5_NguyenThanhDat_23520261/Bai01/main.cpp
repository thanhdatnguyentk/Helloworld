#include"NhanSu.h"
#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<NhanSu*> list;
    int n;
    cout << "Nhap so luong nhan su: ";
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cout << "Nhap thong tin nhan su thu " << i << endl;
        cout << "1. Giang vien" << endl;
        cout << "2. Tro giang" << endl;
        cout << "3. Nghien cuu vien" << endl;
        cout << "4. Chuyen vien" << endl;
        int type;
        cin >> type;
        cin.ignore();
        switch (type)
        {
        case 1:
        {
            GiangVien *gv = new GiangVien();
            gv->Nhap();
            list.push_back(gv);
            break;
        }
        case 2:
        {
            TroGiang *tg = new TroGiang();
            tg->Nhap();
            list.push_back(tg);
            break;
        }
        case 3:
        {
            NghienCuuVien *ncv = new NghienCuuVien();
            ncv->Nhap();
            list.push_back(ncv);
            break;
        }
        case 4:
        {
            ChuyenVien *cv = new ChuyenVien();
            cv->Nhap();
            list.push_back(cv);
            break;
        }
        default:
            break;
        }
    }
    int tongLuong = 0;
    for (NhanSu* ns : list)
    {
        tongLuong += ns->TinhLuong();
        ns->Xuat();
    }
}