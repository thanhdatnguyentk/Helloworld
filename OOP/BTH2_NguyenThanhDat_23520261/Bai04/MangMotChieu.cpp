#include"Bai04.h"

MangMotChieu::MangMotChieu(int n) {
    size = n;
    arr = new int[size];
}

MangMotChieu::~MangMotChieu() {
    delete[] arr;
}
void MangMotChieu::TaoMangNgauNhien() {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Giả sử mảng chứa số nguyên từ 0 đến 99
    }
}
void MangMotChieu::XuatMang() {

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int MangMotChieu::DemSoLanXuatHien(int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}

bool MangMotChieu::KiemTraTangDan() {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}
    
int MangMotChieu::TimPhanLeNhoNhat() {
    int min_odd = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0 && arr[i] < min_odd) {
            min_odd = arr[i];
        }
    }
    return min_odd;
}

int MangMotChieu::TimSoNguyenToLonNhat() {
    int max_prime = 0;
    for (int i = 0; i < size; i++) {
        if (KiemTraSoNguyenTo(arr[i]) && arr[i] > max_prime) {
            max_prime = arr[i];
        }
    }
    return max_prime;
}

bool MangMotChieu::KiemTraSoNguyenTo(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}