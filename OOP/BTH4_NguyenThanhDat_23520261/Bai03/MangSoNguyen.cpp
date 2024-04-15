#include<bits/stdc++.h>
#include"MangSoNguyen.h"
#include<iostream>
using namespace std;

int main(){
    int kichthuoc1, kichthuoc2;
    cout << "Nhập kích thước mảng thứ nhất: ";
    cin >> kichthuoc1;
    MangSoNguyen arr1(kichthuoc1);
    cout << "Nhập mảng thứ nhất: ";
    cin >> arr1;

    cout << "Nhập kích thước mảng thứ hai: ";
    cin >> kichthuoc2;
    MangSoNguyen arr2(kichthuoc2);
    cout << "Nhập mảng thứ hai: ";
    cin >> arr2;

    MangSoNguyen arr3 = arr1 + arr2;
    cout << "Tổng của hai mảng là: " << arr3 << std::endl;

    ++arr1;
    cout << "Mảng thu 1 khi tăng mỗi phần tử lên 1 đơn vị: " << arr1 << std::endl;
    return 0;
}