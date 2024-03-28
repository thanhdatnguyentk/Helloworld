#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int binary_search(vector<int> &a, int n, int x) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if  (a[m] == x) return m;
        else if (a[m] < x) 
        l = m + 1;
        else 
        r = m - 1;
    }
    return r + 1;
}

int main () {
    
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    int x; cin>>x;
    cout<<binary_search(a, n, x)<<endl;

    return 0;
}