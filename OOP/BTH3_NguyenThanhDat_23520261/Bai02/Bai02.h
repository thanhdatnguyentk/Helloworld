#ifndef LOPHOC_H
#define LOPHOC_H
#include"HocSinh.h"

using namespace std;

class LopHoc
{
private:
    /* data */
    vector<HocSinh> list;
    int n;
public:
    void addStudent();
    void showList();
    void showStudent();
    void searchStudent();
    void removeStudent();
    LopHoc(/* args */);
    ~LopHoc();
};
#endif