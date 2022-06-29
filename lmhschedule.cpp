#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct xe
{
    ll ns, tp;
};

bool sosanh(xe a, xe b)
{
    if (a.ns == b.ns)
        return a.tp > b.tp;
    return a.ns < b.ns;
}
xe a[100005];

int main()
{
    ll n,s=0,res= 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].tp,s+=a[i].tp;
    for (int i = 1; i <= n; i++)
        cin >> a[i].ns;

    sort(a + 1, a + 1 + n, sosanh);
    for (int i = 1; i <= n; i++) {
        res += s * a[i].ns;
        s -= a[i].tp;
    }
    cout << res;
}