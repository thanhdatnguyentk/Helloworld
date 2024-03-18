#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll x[201], y[201], z[201], a[4][101], b[4][101], dd[202][202][202];
int main()
{
    cin >> n;
    ll dem = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[1][i] >> a[2][i] >> a[3][i] >> b[1][i] >> b[2][i] >> b[3][i];
        x[dem] = a[1][i];
        y[dem] = a[2][i];
        z[dem] = a[3][i];
        dem++;
        x[dem] = b[1][i];
        y[dem] = b[2][i];
        z[dem] = b[3][i];
        dem++;
    }
    ll res = 0;
    sort(x + 1, x + dem + 1);
    sort(y + 1, y + dem + 1);
    sort(z + 1, z + dem + 1);

    for (int i = 1; i <= n; i++)
    {
        ll vtxa, vtya, vtza, vtxb, vtyb, vtzb;
        for (int j = 1; j <= dem; j++)
        {
            if (a[1][i] == x[j])
            {
                vtxa = j;
                break;
            }
        }
        for (int j = 1; j <= dem; j++)
        {
            if (a[2][i] == y[j])
            {
                vtya = j;
                break;
            }
        }
        for (int j = 1; j <= dem; j++)
        {
            if (a[3][i] == z[j])
            {
                vtza = j;
                break;
            }
        }
        for (int j = 1; j <= dem; j++)
        {
            if (b[1][i] == x[j])
            {
                vtxb = j;
                break;
            }
        }
        for (int j = 1; j <= dem; j++)
        {
            if (b[2][i] == y[j])
            {
                vtyb = j;
                break;
            }
        }
        for (int j = 1; j <= dem; j++)
        {
            if (b[3][i] == z[j])
            {
                vtzb = j;
                break;
            }
        }
        for (int y = vtxa; y <= vtxb; y++)
            for (int z = vtya; z <= vtyb; z++)
                for (int t = vtza; y <= vtzb; t++)
                {
                    dd[y][z][t] = 1;
                }
    }
    for (int i = 1; i <= dem; i++)
    {
        for (int j = 1; j <= dem; j++)
        {
            for (int z = 1; z <= dem; z++)
                cout << dd[i][j][z] << " ";
            cout << endl;
        }
        cout << endl;
    }
    cout << res;
}