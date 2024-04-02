#include"SoPhuc.h"

int main(){
    SoPhuc a,b;
    cin >> a;
    cin >> b;
    cout << a << endl;
    cout << b << endl;

    SoPhuc c = a + b;
    cout << c << endl;

    c = a - b;
    cout << c << endl;
    c = a * b;
    cout << c << endl;
    c = a / b;
    cout << c << endl;   
}