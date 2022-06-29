#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t;

int main() {
    cin >>t;
    while (t--) {
        ll m,n,k,a,b;
        cin >> m >> n >>k>> a >> b;
        ll l = 0 , r = min (m/a ,n / b), mid, res;
        while (l<= r) {
            mid = (r+l) / 2;
            if (m-(a*mid) + n - (b*mid) >= k) {
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }                    
        cout << res << endl;                                                                                            
    }
}

