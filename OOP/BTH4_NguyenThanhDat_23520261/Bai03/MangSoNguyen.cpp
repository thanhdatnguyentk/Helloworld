#include <iostream>
#include "MangSoNguyen.h"

int main() {
    int kichthuoc1, kichthuoc2;
    std::cout << "Nhập kích thước mảng thứ nhất: ";
    std::cin >> kichthuoc1;
    MangSoNguyen arr1(kichthuoc1);
    std::cout << "Nhập mảng thứ nhất: ";
    std::cin >> arr1;

    std::cout << "Nhập kích thước mảng thứ hai: ";
    std::cin >> kichthuoc2;
    MangSoNguyen arr2(kichthuoc2);
    std::cout << "Nhập mảng thứ hai: ";
    std::cin >> arr2;

    MangSoNguyen arr3 = arr1 + arr2;
    std::cout << "Tổng của hai mảng là: " << arr3 << std::endl;

    ++arr1;
    std::cout << "Mảng thứ nhất sau khi tăng mỗi phần tử lên 1 đơn vị: " << arr1 << std::endl;

    return 0;
}
