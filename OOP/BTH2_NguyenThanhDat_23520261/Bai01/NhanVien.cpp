#include"Bai01.h"

NhanVien::NhanVien(){

}
NhanVien::NhanVien(string HoVaTen, long long Day){
    this->HoVaTen = HoVaTen;
    this->Day = Day;
    string c = to_string(Day);
    this->MaSoNhanVien = c + HoVaTen;
    if (Day < 365) this->ChucDanh = "Nhan vien";
    else if (Day < 730) this->ChucDanh = "Quan ly";
    else if (Day < 1460) this->ChucDanh = "Truong phong";
    else this->ChucDanh = "Truong ban quan ly";

    
    if (ChucDanh == "Nhan vien")
        this->HeSoLuong = 1.0;
    else if (ChucDanh == "Quan ly")
        this->HeSoLuong = 1.5;
    else if (ChucDanh == "Truong phong")
        this->HeSoLuong = 2.25;
    else if (ChucDanh == "Truong ban quan ly")
        this->HeSoLuong = 4.0;
}

NhanVien::NhanVien(const NhanVien &temp) {
    ChucDanh = temp.ChucDanh;
    HeSoLuong = temp.HeSoLuong;
    Day = temp.Day;
    HoVaTen = "";
    MaSoNhanVien = "";
}

void NhanVien::nhap(){
    cout << "  Moi ban nhap ho va ten: ";
    getline(cin, this->HoVaTen);
    cout << "  Moi ban nhap so ngay lam viec: ";
    cin >> this->Day;
    cout << "  Moi ban nhap ma so nhan vien: ";
    cin.ignore();
    getline(cin, this->MaSoNhanVien);
    cout << "  Moi ban nhap chuc danh: ";
    getline(cin, this->ChucDanh);
    cout << "  Moi ban nhap he so luong: ";
    cin >> this->HeSoLuong;
}

void NhanVien::xuat(){
    cout << "   Ho va ten la: ";
    cout << this->HoVaTen << endl;
    cout << "   So ngay lam viec la: ";
    cout << this->Day << endl;
    cout << "   Ma so nhan vien la: ";
    cout << this->MaSoNhanVien << endl;
    cout << "   Chuc danh la: ";
    cout << this->ChucDanh << endl;
    cout << "   He so luong la: ";
    cout << this->HeSoLuong << endl;
}

 NhanVien::~ NhanVien()
{
    cout << "Da xoa nhan vien: " << GetCode() << endl;
}
