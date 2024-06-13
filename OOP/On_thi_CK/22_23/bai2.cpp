#include<bits/stdc++.h>

using namespace std;

class IntArr
{
private:
    int count;   // tổng số lượng phần tử có trong values
    int *values; // mảng các số nguyên đang có trong đối tượng hiện tại
public:
    // Sinh viên bổ sung đầy đủ các thành phần cần thiết để hàm main hoạt động như mong đợi
    int get(){
        return this->count;
    }
    int get_value(int x){
        return *(this->values + x)
    }
    IntArr(){
        count = 0;
        values = NULL;
    }
    IntArr(int x, int y){
        this->count = x;
        values = new int[x];

        for (int i = 0; i < x; i++)
            {
                *(this->values + i) = y;
            }
    }
    IntArr(int x){
        this->count = x;
        values = new int[x];

        for (int i = 0; i < x; i++)
        {
            *(this->values + i) = 0;
        }
    }
    IntArr concat(IntArr x){
        IntArr temp;
        temp.count = this->count + x.count;
        temp.values = new int[temp.count];
        for (int i = 0; i < this->count; i++)
        {
            *(temp.values + i) = *(this->values + i);
        }
        for (int i = 0; i < x.count; i++)
        {
            *(temp.values + i + this->count) = *(x.values + i);
        }
        return temp;
    }

    int push(int x);
    friend istream &operator>>(istream &is, IntArr &x)
    {
        if (x.values != NULL)
        {
            delete[] x.values;
        }
        cout << "Nhap so luong phan tu: ";
        is >> x.count;
        x.values = new int[x.count];
        for (int i = 0; i < x.count; i++)
        {
            cout << "Nhap phan tu thu " << i + 1 << ": ";
            is >> *(x.values + i);
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, IntArr &x)
    {
        for (int i = 0; i < x.count; i++)
        {
            os << *(x.values + i) << " ";
        }
        return os;
    }
};
int main()
{
    IntArr l1;                 // tạo mảng không chứa bất kì phần tử nào
    IntArr l2(3, 2);           // tạo một mảng với 3 phần tử, tất cả phần tử đều có giá trị là 2
    IntArr l3(2);              // tạo một mảng với 2 phần tử, tất cả phần tử đều có giá trị là 0
    IntArr l4 = l2.concat(l3); // tạo ra một IntArr mới có nội dung là kết quả của việc nối cácphần tử l3 vào cuối các phần tử của l2 theo thứ tự
    l2.push(3);                // thêm số 3 vào cuối danh sách trong đối tượng l2
    cin >> l2;                 // Xoá các giá trị hiện có trong l2 và cho phép người dùng nhập số lượng phần tửmới và giá trị các phần tử mới vào l2(cần xoá các vùng nhớ không sử dụng nếu có)
    cout << l2;                // in ra các số nguyên có trong danh sách
    // Khi vượt quá phạm vi sử dụng cần huỷ tất cả các vùng nhớ được cấp phát cho các valuescủa IntArr
    return 0;
}

int IntArr::push(int x){
    this->count++;
    int *temp = new int[this->count];
    for (int i = 0; i < this->count - 1; i++)
    {
        *(temp + i) = *(this->values + i);
    }
    *(temp + this->count - 1) = x;
    delete[] this->values;
    this->values = temp;
    return 1;
}