#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll m, n, k, a[1004][1004], res;

int main()
{
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = 1;
    for (int i = 1; i <= k; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[x][y] = 0;
    }
    if (k == 0)
    {
        for (int r = 1; r <= min(m, n) - 1; r++)
            res += r * (m - r) * (n - r);
        cout << res;
        return 0;
    }
    // cout << endl;
    ll r, x, y, h;
    for (r = 1; r
     <= min(m, n) - 1; r++)
    {
        for (x = 1; x <= m - r; x++)
        {
            for (y = 1; y <= n - r; y++)
            {
                for (h = 0; h <= r - 1; h++)
                {
                    ll ax = x + h, ay = y;
                    ll bx = x + r, by = y + h;
                    ll cx = x + r - h, cy = y + r;
                    ll dx = x, dy = y  + r - h;

                    if (a[ax][ay] == 1 && a[bx][by] == 1 && a[cx][cy] == 1 && a[dx][dy] == 1)
                    {
                        res++;
                        // cout << ax << " " << ay << endl;
                        // cout << bx << " " << by << endl;
                        // cout << cx << " " << cy << endl;
                        // cout << dx << " " << dy << endl;

                        // cout << endl;
                    }
                }
            }
        }
    }
    cout << res;
}