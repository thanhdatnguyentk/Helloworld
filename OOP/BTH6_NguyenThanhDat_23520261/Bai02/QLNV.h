#include "NhanVien.h"
#include<vector>
using namespace std;
class QLNV
{
protected:
    vector<NhanVien*> danhSachNV;
public:
    void nhapDanhSachNV();
    void xuatDanhSachNVTienTien() const;
    ~QLNV();
};
QLNV::~QLNV() {
    for (NhanVien* nv : danhSachNV) {
        delete nv;
    }
}
void QLNV::nhapDanhSachNV() {
    int loai, n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Chon loai nhan vien (1. Giang vien, 2. Nghien cuu vien, 3. Nhan vien van phong): ";
        cin >> loai;
        NhanVien* nv = nullptr;

        if (loai == 1) {
            nv = new GiangVien("", "", "", 0, 0);
        } else if (loai == 2) {
            nv = new NghienCuuVien("", "", "", 0, 0);
        } else if (loai == 3) {
            nv = new NhanVienVanPhong("", "", "", 0, 0);
        } else {
            cout << "Loai nhan vien khong hop le!" << endl;
            --i;
            continue;
        }

        nv->nhapThongTin();
        danhSachNV.push_back(nv);
    }
}

void QLNV::xuatDanhSachNVTienTien() const {
    cout << "Danh sach nhan vien lao dong tien tien:\n";
    for (const NhanVien* nv : danhSachNV) {
        if (nv->laLaoDongTienTien()) {
            nv->xuatThongTin();
        }
    }
}
istream& operator>>(istream& is, QLNV& qlnv) {
    qlnv.nhapDanhSachNV();
    return is;
}

ostream& operator<<(ostream& os, const QLNV& qlnv) {
    qlnv.xuatDanhSachNVTienTien();
    return os;
}


