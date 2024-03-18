#include<bits/stdc++.h>
#include"Bai04.h"
#include"MangMotChieu.cpp"

using namespace std;
int main(){
    MangMotChieu mang(10); // Khởi tạo mảng có kích thước 10
    mang.TaoMangNgauNhien(); // Tạo mảng ngẫu nhiên
    cout << "Mang vua tao: ";
    mang.XuatMang(); 
    int x;
    cout<< " Nhap so ban can tim";
    cin >> x;
    cout << "So lan xuat hien cua " << x << " trong mang: " << mang.DemSoLanXuatHien(x) << endl;
    if (mang.KiemTraTangDan()) {
        cout << " Mang tang dan." << endl;
    } else {
        cout << " Mang khong tang dan." << endl;
    }
    cout << " Phan le nho nhat trong mang: " << mang.TimPhanLeNhoNhat() << endl;
    cout << " So nguyen to lon nhat trong mang: " << mang.TimSoNguyenToLonNhat() << endl;

}