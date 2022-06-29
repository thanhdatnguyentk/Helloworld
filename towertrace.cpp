#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

struct khoi
{
    ll x;
    ll y;
    ll z;
    ll ktcs;
};

bool sosanh(khoi a, khoi b)
{
    return a.ktcs < b.ktcs;
}
khoi a[10004];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        a[i].x = x;
        a[i].y = y;
        a[i].z = z;
        ll t;
        if (x < y)
        {
            t = x;
            x = y;
            y = t;
        }
        if (x < z)
        {
            t = x;
            x = z;
            z = t;
        }
        if (y < z)
        {
            t = y;
            y = z;
            z = t;
        }
        a[i].ktcs = x + y;
    }
    sort(a+1,a+1+n,sosanh);
    ll xo,yo,zo;
    for (int i = 1; i <= n ;i++)
        {
            if 
        }
}