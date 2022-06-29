#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int CmpInt(ll a, ll b)
{
  if (a == b)
    return 0;
  else if (a > b)
    return 1;
  else
    return -1;
}

int Compare(ll a, ll b, ll c, ll d)
{
  if (a / b != c / d)
    return CmpInt(a / b, c / d);
  a %= b;
  c %= d;
  if (a == 0 || c == 0)
    return CmpInt(a, c);
  else
    return -Compare(b, a, d, c);
}

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << Compare(a, b, c, d) << endl;
  }
}