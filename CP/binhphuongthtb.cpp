#include <bits/stdc++.h>
#define ll long long

using namespace std;

long long k, d;
ll res;

ll so(ll u)
{
	ll d = 0;
	for (int i = 1; i <= (ll)sqrt(u); i++)
		d += (ll)(sqrt(u - i * i));
	return d;
}

int main()
{
	cin >> k;

	ll l = 2, r = 1e12, mid;

	while (l <= r)
	{
		mid = (r + l) / 2;
		ll d = so(mid);
		if (d >= k)
			r = mid - 1, res = mid;
		else
			l = mid + 1;
	}
	cout << res;
}
