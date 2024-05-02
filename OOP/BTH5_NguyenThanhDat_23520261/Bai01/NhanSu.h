#ifndef NHANSU_H
#define NHANSU_H

#include <bits/stdc++.h>

using namespace std;

class NhanSu
{
    protected:
        string name;
        string birth;
        int code;
    public:
        virtual double TinhLuong() = 0;
        NhanSu();
        NhanSu(string name, string birth, int code);
        void Nhap();
        void Xuat();
        ~NhanSu();
};

class GiangVien : public NhanSu
{
    private:
        string hocHam;
        string hocVi;
        int soNamGiangDay;
        string dsCacMonDangDay[100];
        int soMonDangDay;
    public:
        GiangVien();
        GiangVien(string name, string birth, int code, string hocHam, string hocVi, int soNamGiangDay, string dsCacMonDangDay[]);
        double TinhLuong();
        void Nhap();
        void Xuat();
        ~GiangVien();

};
class TroGiang : public NhanSu
{
    private:
        int soMonTroGiang;
    public:
        TroGiang();
        TroGiang(string name, string birth, int code, int soMonTroGiang);
        double TinhLuong();
        void Nhap();
        void Xuat();
        ~TroGiang();
};

class NghienCuuVien : public NhanSu
{
    private:
        string duAnNghienCuuDangThamGia[100];
        int soNamKinhNghiemNghienCuu;
        
    public:
        NghienCuuVien();
        NghienCuuVien(string name, string birth, int code, string duAnNghienCuuDangThamGia[], int soNamKinhNghiemNghienCuu);
        double TinhLuong();
        void Nhap();
        void Xuat();
        ~NghienCuuVien();
};

class ChuyenVien : public NhanSu
{
    private:
        string dsDuAnGiaoDuc[100];
        int soNamKinhNghiemLamViec;
    public:
        ChuyenVien();
        ChuyenVien(string name, string birth, int code, string dsDuAnGiaoDuc[], int soNamKinhNghiemLamViec);
        double TinhLuong();
        void Nhap();
        void Xuat();
        ~ChuyenVien();
};

//   NHAN SU
NhanSu :: NhanSu(){
    name = "";
    birth = "";
    code = 0;

}
NhanSu :: NhanSu(string name, string birth, int code){
    this->name = name;
    this->birth = birth;
    this->code = code;
}
void NhanSu :: Nhap(){
    cout << "Nhap ten: ";
    getline(cin, this->name);
    cout << "Nhap ngay sinh: ";
    getline(cin, this->birth);
    cout << "Nhap ma so: ";
    cin >> this->code;
}

void NhanSu :: Xuat(){
    cout << "Ten: " << this->name << endl;
    cout << "Ngay sinh: " << this->birth << endl;
    cout << "Ma so: " << this->code << endl;
}
NhanSu :: ~NhanSu(){
    cout << " Nhan vien: " << this->name << " da bi huy" << endl;
}

//  GIANG VIEN
GiangVien :: GiangVien() : NhanSu(){
    hocHam = "";
    hocVi = "";
    soNamGiangDay = 0;
    for (int i = 0; i < 100; i++)
    {
        dsCacMonDangDay[i] = "";
    }
}
GiangVien :: GiangVien(string name, string birth, int code, string hocHam, string hocVi, int soNamGiangDay, string dsCacMonDangDay[]) : NhanSu(name, birth, code)
{
    int dem = 0;
    this->hocHam = hocHam;
    this->hocVi = hocVi;
    this->soNamGiangDay = soNamGiangDay;
    for (int i = 0; i < 100; i++)
    {
        this->dsCacMonDangDay[i] = dsCacMonDangDay[i];
        if (dsCacMonDangDay[i] != "")
        {
            dem++;
        }
    }
    this->soMonDangDay = dem;
}
double GiangVien :: TinhLuong(){
    return (soMonDangDay * soNamGiangDay * 0.12) * 20000;
}
void GiangVien :: Nhap(){
    NhanSu::Nhap();
    
    cout << "Nhap hoc ham: ";
    cin.ignore();
    getline(cin, this->hocHam);

    cout << "Nhap hoc vi: ";
    getline(cin, this->hocVi);
    cout << "Nhap so nam giang day: ";
    cin >> this->soNamGiangDay;
    cout << "Nhap so mon dang day: ";
    cin >> this->soMonDangDay;
    for (int i = 0; i < this->soMonDangDay; i++)
    {
        cout << "Nhap mon dang day thu " << i + 1 << ": ";
        getline(cin, this->dsCacMonDangDay[i]);
    }
}
void GiangVien :: Xuat() {
    NhanSu::Xuat();
    cout << "Hoc ham: " << this->hocHam << endl;
    cout << "Hoc vi: " << this->hocVi << endl;
    cout << "So nam giang day: " << this->soNamGiangDay << endl;
    cout << "Danh sach cac mon dang day: " << endl;
    for (int i = 0; i < this->soMonDangDay; i++)
    {
        cout << this->dsCacMonDangDay[i] << endl;
    }
    cout << "Luong: " << this->TinhLuong() << endl;
}
//  TRO GIANG
TroGiang :: TroGiang() : NhanSu(){
    soMonTroGiang = 0;
}
TroGiang :: TroGiang(string name, string birth, int code, int soMonTroGiang) : NhanSu(name, birth, code){
    this->soMonTroGiang = soMonTroGiang;
}
double TroGiang :: TinhLuong(){
    return soMonTroGiang * 0.3 * 18000;
}
void TroGiang :: Nhap(){
    NhanSu::Nhap();
    cout << "Nhap so mon tro giang: ";
    cin >> this->soMonTroGiang;
}
void TroGiang :: Xuat() {
    NhanSu::Xuat();
    cout << "So mon tro giang: " << this->soMonTroGiang << endl;
    cout << "Luong: " << this->TinhLuong() << endl;
}
TroGiang :: ~TroGiang() {
    cout << "Tro giang: " << this->name << " da bi huy" << endl;
}
//  NGHIEN CUU VIEN
NghienCuuVien :: NghienCuuVien() : NhanSu(){
    soNamKinhNghiemNghienCuu = 0;
    for (int i = 0; i < 100; i++)
    {
        duAnNghienCuuDangThamGia[i] = "";
    }
}
NghienCuuVien :: NghienCuuVien(string name, string birth, int code, string duAnNghienCuuDangThamGia[], int soNamKinhNghiemNghienCuu) : NhanSu(name, birth, code){
    int dem = 0;
    this->soNamKinhNghiemNghienCuu = soNamKinhNghiemNghienCuu;
    for (int i = 0; i < 100; i++)
    {
        this->duAnNghienCuuDangThamGia[i] = duAnNghienCuuDangThamGia[i];
        if (duAnNghienCuuDangThamGia[i] != "")
        {
            dem++;
        }
    }
    this->soNamKinhNghiemNghienCuu = dem;
}
int soDuAnBatDauBangChuD(string x[]){
    int dem = 0;
    for (int i = 0; i < 100; i++)
    {
        if ( x[i][0] == 'D')
        {
            dem++;
        }
    }
    return dem;
}
double NghienCuuVien :: TinhLuong(){
    return (this->soNamKinhNghiemNghienCuu * 2 + soDuAnBatDauBangChuD(this->duAnNghienCuuDangThamGia)) * 20000;
}
void NghienCuuVien :: Nhap(){
    NhanSu::Nhap();
    cout << "Nhap so nam kinh nghiem nghien cuu: ";
    cin >> this->soNamKinhNghiemNghienCuu;
    for (int i = 0; i < this->soNamKinhNghiemNghienCuu; i++)
    {
        cout << "Nhap du an nghien cuu dang tham gia thu " << i + 1 << ": ";
        getline(cin, this->duAnNghienCuuDangThamGia[i]);
    }
}
void NghienCuuVien :: Xuat() {
    NhanSu::Xuat();
    cout << "So nam kinh nghiem nghien cuu: " << this->soNamKinhNghiemNghienCuu << endl;
    cout << "Danh sach cac du an nghien cuu dang tham gia: " << endl;
    for (int i = 0; i < this->soNamKinhNghiemNghienCuu; i++)
    {
        cout << this->duAnNghienCuuDangThamGia[i] << endl;
    }
    cout << "Luong: " << this->TinhLuong() << endl;
}
NghienCuuVien :: ~NghienCuuVien() {
    cout << "Nghien cuu vien: " << this->name << " da bi huy" << endl;
}
//  CHUYEN VIEN
ChuyenVien :: ChuyenVien() : NhanSu(){
    soNamKinhNghiemLamViec = 0;
    for (int i = 0; i < 100; i++)
    {
        dsDuAnGiaoDuc[i] = "";
    }
}
ChuyenVien :: ChuyenVien(string name, string birth, int code, string dsDuAnGiaoDuc[], int soNamKinhNghiemLamViec) : NhanSu(name, birth, code){
    int dem = 0;
    this->soNamKinhNghiemLamViec = soNamKinhNghiemLamViec;
    for (int i = 0; i < 100; i++)
    {
        this->dsDuAnGiaoDuc[i] = dsDuAnGiaoDuc[i];
        if (dsDuAnGiaoDuc[i] != "")
        {
            dem++;
        }
    }
    this->soNamKinhNghiemLamViec = dem;
}
int soDuAnBatDauBangChuT(string x[]){
    int dem = 0;
    for (int i = 0; i < 100; i++)
    {
        if ( x[i][0] == 'T')
        {
            dem++;
        }
    }
    return dem;
}
double ChuyenVien :: TinhLuong(){
    return (this->soNamKinhNghiemLamViec * 4 + soDuAnBatDauBangChuT(this->dsDuAnGiaoDuc)) * 18000;
}
void ChuyenVien :: Nhap(){
    NhanSu::Nhap();
    cout << "Nhap so nam kinh nghiem lam viec: ";
    cin >> this->soNamKinhNghiemLamViec;
    for (int i = 0; i < this->soNamKinhNghiemLamViec; i++)
    {
        cout << "Nhap du an giao duc thu " << i + 1 << ": ";
        getline(cin, this->dsDuAnGiaoDuc[i]);
    }
}
void ChuyenVien :: Xuat() {
    NhanSu::Xuat();
    cout << "So nam kinh nghiem lam viec: " << this->soNamKinhNghiemLamViec << endl;
    cout << "Danh sach cac du an giao duc: " << endl;
    for (int i = 0; i < this->soNamKinhNghiemLamViec; i++)
    {
        cout << this->dsDuAnGiaoDuc[i] << endl;
    }
    cout << "Luong: " << this->TinhLuong() << endl;
}

ChuyenVien :: ~ChuyenVien() {
    cout << "Chuyen vien: " << this->name << " da bi huy" << endl;
}


#endif