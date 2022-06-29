#include <bits/stdc++.h>

using namespace std;

long long dp[6001][6001];
int t, a[6001][6001];

int main()
{
    cin >> t;
    while (t--)
    {
        long long m, n, k;
        cin >> m >> n >> k;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                char x;
                cin >> x;
                if (x == 'A')
                    a[i][j] = 1;
                else
                    a[i][j] = -1;
            }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
                cout << dp[i][j] << " ";
            }
        }
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
    }
}