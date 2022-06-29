#include<bits/stdc++.h>
#define ll long long

using namespace std;

string x;
bool ktr;
ll dd[10001],res;
int main(){
    cin >> x;
    ll n = 1;
    ll d = 1;
    for (int i = 1 ; i < x.length() ; i++)
        if (x[i] == x[0]){
            dd[d] = i;
            d++;
        }
    for (int i = 1; i < d; i++)
        {
            ktr = true;
           // cout << dd[i] << " ";
            for (int j = 0; j < dd[i] ; j++ ){
             //   cout << x[j] << " " << x[j+dd[i]] << endl;
                if (x[j] != x[j+dd[i]])
                    {
                        ktr = false;
                        break;
                    }
            }
            if (ktr == true)
                res = dd[i]*2;
        }
    cout << res;
}