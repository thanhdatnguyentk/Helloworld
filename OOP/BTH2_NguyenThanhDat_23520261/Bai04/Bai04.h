#ifndef MANGMOTCHIEU_H
#define MANGMOTCHIEU_H
#include <bits/stdc++.h>
using namespace std;
class MangMotChieu{
private:
    int *arr;
    int size;
public:
    MangMotChieu(int n);
   ~MangMotChieu();
    void TaoMangNgauNhien();
    void XuatMang();
    int DemSoLanXuatHien(int x);
    bool KiemTraTangDan();
    int TimPhanLeNhoNhat();
    int TimSoNguyenToLonNhat();
    bool KiemTraSoNguyenTo(int n);
};

#endif