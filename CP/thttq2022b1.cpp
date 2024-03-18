#include <bits/stdc++.h>

using namespace std;

long long n, q, a[1000006];

const long long mod = 1e9 + 7;

struct cap {
    long long cap = 1;
};

cap dp[100005];

long long mul (long long a, long long b) {
    
}
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 2; i <= n ;i++) {
        for (int  j = i - 1; j >= 1; j--) {
            if (a[i] % mod == a[j] % mod * q % mod  )
                {
                    // cout << a[j] << " " << a[i] << " " << dp[i].cap << "\n";
                    dp[i].cap = dp[j].cap + 1;
                    break;
                }                
        }
    }

    for (int i = 2; i <= n; i++)
        {
            long long d = 0;
            for (int j = 2; j <= n; j++)
                if (dp[j].cap >=  i) d++;
            cout << d <<" ";    
                 
        }

}