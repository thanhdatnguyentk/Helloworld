#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll res, n, snt[2000000];

void sang() {
    snt[1] = 0;
    for (int i = 2; i <= 1000000; i++){
        if (snt[i] != 0)  continue;
        for (int j = i ; j<= 1000000; j+= i) snt[j]=i;
    }
}

int main()
{
    sang();
    while(cin >> n) {
        ll res = 1;
        while (n>1) {

        ll p = snt[n], k = 0;
        while(n % p == 0) {
            k++;
            n /= p;
        }
        res *= k+1;
        }
        cout << res  << endl;
    }
} 
