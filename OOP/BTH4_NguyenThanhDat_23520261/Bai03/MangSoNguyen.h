#include <iostream>
#include <vector>

class MangSoNguyen
{
private:
    std::vector<int> duLieu;

public:
    MangSoNguyen() = default;
    MangSoNguyen(int size) : duLieu(size) {}

    MangSoNguyen& operator=(const MangSoNguyen& other) {
        if (this != &other) {
            duLieu = other.duLieu;
        }
        return *this;
    }

    MangSoNguyen operator+(const MangSoNguyen& other) const {
        int newSize = std::max(duLieu.size(), other.duLieu.size());
        MangSoNguyen result(newSize);
        for (int i = 0; i < newSize; ++i) {
            if (i < duLieu.size() && i < other.duLieu.size()) {
                result.duLieu[i] = duLieu[i] + other.duLieu[i];
            } else if (i < duLieu.size()) {
                result.duLieu[i] = duLieu[i];
            } else {
                result.duLieu[i] = other.duLieu[i];
            }
        }
        return result;
    }

    MangSoNguyen& operator++() {
        for (int& num : duLieu) {
            ++num;
        }
        return *this;
    }

    friend std::istream& operator>>(std::istream& is, MangSoNguyen& arr) {
        for (int& num : arr.duLieu) {
            is >> num;
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const MangSoNguyen& arr) {
        for (const int& num : arr.duLieu) {
            os << num << " ";
        }
        return os;
    }
};
