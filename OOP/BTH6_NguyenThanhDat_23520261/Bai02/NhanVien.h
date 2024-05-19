#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class NhanVien
{
protected:
    string maSo;
    string hoTen;
    string ngaySinh;
public:
    NhanVien(string maSo, string hoTen, string ngaySinh);
    virtual void nhapThongTin();
    virtual void xuatThongTin() const;
    virtual bool laLaoDongTienTien() const = 0;
    virtual ~NhanVien() {}
};
class GiangVien : public NhanVien {
private:
    int soTietGiangDay;
    int soDeTaiKhoaLuan;

public:
    GiangVien(string maSo, string hoTen, string ngaySinh, int soTietGiangDay, int soDeTaiKhoaLuan);

    void nhapThongTin() override;

    void xuatThongTin() const override;

    bool laLaoDongTienTien() const override;
};
class  NghienCuuVien : public NhanVien
{
private:
    int soDeTaiNghienCuu;
    int soBaiBaoKhoaHoc;
public:
    NghienCuuVien(string maSo,string hoTen, string ngaySinh, int soTietGiangDay, int soDeTaiKhoaLuan);
    void nhapThongTin() override;
    void xuatThongTin() const override;
    bool laLaoDongTienTien() const override;
    ~ NghienCuuVien();
};
class NhanVienVanPhong : public NhanVien
{
private:
    int soLopBoiduong;
    int soGioLaoDongCongIch;
public:
    NhanVienVanPhong(string maSo, string hoTen, string ngaySinh, int soLopBoiduong, int soGioLaoDongCongIch);
    void nhapThongTin() override;
    void xuatThongTin() const override;
    bool laLaoDongTienTien() const override;
    ~NhanVienVanPhong();
};
NhanVien::NhanVien(string maSo, string hoTen, string ngaySinh): maSo(maSo),hoTen(hoTen),ngaySinh(ngaySinh) {}
void NhanVien::nhapThongTin() {
    cout << "Nhap ma so: ";
    cin >> maSo;
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap ngay sinh: ";
    cin >> ngaySinh;
}
void NhanVien::xuatThongTin() const {
     cout << "Ma so: " << maSo << ", Ho ten: " << hoTen
         << ", Ngay sinh: " <<ngaySinh << endl;
}
bool NhanVien::laLaoDongTienTien() const {
    return true;
}
GiangVien::GiangVien(string maNV, string hoTen, string ngaySinh, int soTietGiangDay, int soDeTaiKhoaLuan)
    : NhanVien(maNV, hoTen, ngaySinh), soTietGiangDay(soTietGiangDay), soDeTaiKhoaLuan(soDeTaiKhoaLuan) {}

void GiangVien::nhapThongTin() {
    NhanVien::nhapThongTin();
    cout << "Nhap so tiet giang day: ";
    cin >> soTietGiangDay;
    cout << "Nhap so de tai khoa luan: ";
    cin >> soDeTaiKhoaLuan;
}

void GiangVien::xuatThongTin() const {
    NhanVien::xuatThongTin();
    cout << ", So tiet giang day: " << soTietGiangDay << ", So de tai khoa luan: " << soDeTaiKhoaLuan << endl;
}

bool GiangVien::laLaoDongTienTien() const {
    return soTietGiangDay >= 300 && soDeTaiKhoaLuan >= 5;
}
NghienCuuVien::NghienCuuVien(string maNV, string hoTen, string ngaySinh, int soDeTaiNghienCuu, int soBaiBaoKhoaHoc)
    : NhanVien(maNV, hoTen, ngaySinh), soDeTaiNghienCuu(soDeTaiNghienCuu), soBaiBaoKhoaHoc(soBaiBaoKhoaHoc)  {}
void NghienCuuVien::nhapThongTin() {
    NhanVien::nhapThongTin();
    cout << "Nhap so de tai nghien cuu: ";
    cin >> soDeTaiNghienCuu;
    cout << "Nhap so bai bao khoa hoc: ";
    cin >> soBaiBaoKhoaHoc;
}
void NghienCuuVien::xuatThongTin() const {
    NhanVien::xuatThongTin();
    cout << ", So de tai nghien cuu: " << soDeTaiNghienCuu << ", So bai bao khoa hoc: " << soBaiBaoKhoaHoc << endl;
}
NghienCuuVien::~NghienCuuVien() {}
bool NghienCuuVien::laLaoDongTienTien() const {
    return soDeTaiNghienCuu >= 1 && soBaiBaoKhoaHoc >= 2;
}
NhanVienVanPhong::NhanVienVanPhong(string maSo, string hoTen, string ngaySinh, int soLopBoiduong, int soGioLaoDongCongIch)
    : NhanVien(maSo, hoTen, ngaySinh), soLopBoiduong(soLopBoiduong), soGioLaoDongCongIch(soGioLaoDongCongIch) {}

void NhanVienVanPhong::nhapThongTin() {
    NhanVien::nhapThongTin();
    cout << "Nhap so lop boi duong: ";
    cin >> soLopBoiduong;
    cout << "Nhap so gio lao dong cong ich: ";
    cin >> soGioLaoDongCongIch;
}

void NhanVienVanPhong::xuatThongTin() const {
    NhanVien::xuatThongTin();
    cout << ", So lop boi duong: " << soLopBoiduong << ", So gio lao dong cong ich: " << soGioLaoDongCongIch << endl;
}
NhanVienVanPhong::~NhanVienVanPhong() {}
bool NhanVienVanPhong::laLaoDongTienTien() const {
    return soLopBoiduong >= 1 && soGioLaoDongCongIch >= 20;
}
#endif