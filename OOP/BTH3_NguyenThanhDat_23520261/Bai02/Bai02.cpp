#include<bits/stdc++.h>
#include"LopHoc.cpp"
#include"Bai02.h"

using namespace std;

int main(){
    int n;
    LopHoc a;
    cin >>  n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        a.addStudent();
    }
    a.showList();
    a.showStudent();
    a.searchStudent();
    a.removeStudent();
    a.showList();
}