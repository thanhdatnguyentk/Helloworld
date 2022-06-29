#include<bits/stdc++.h>
#define ll long long
#define lb long double
using namespace std;

lb d,t,b;
int main (){
    cin >> d >> t >> b;
    if (d == t) {
        cout <<"Possible";
        return 0;
    }
    if (b == 1){
        cout << "Impossible";
        return 0;
    }
    lb y = (d-t)/(b-1);
    lb x = t - y;
    if ((trunc(y) == y ) && (y > 0) && (x > 0))
        {
            cout <<"Possible";
        } 
    else cout <<"Impossible";
}