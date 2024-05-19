#include "QLNV.h"
#include <iostream>

int main() {
    QLNV qlnv;

    // Nhập thông tin danh sách nhân viên
    cout << "Nhap thong tin danh sach nhan vien:\n";
    cin >> qlnv;

    // Xuất thông tin danh sách nhân viên lao động tiên tiến
    cout << "\nDanh sach nhan vien lao dong tien tien:\n";
    cout << qlnv;

    return 0;
}
