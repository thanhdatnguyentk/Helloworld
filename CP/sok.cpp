#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	cin >> n;
	long long l = 1, r = 20000000000000000, mid;
	while (l < r)
	{
		mid = (r + l) / 2;

		long long stt = mid / 3 + mid / 5 + mid / 7 - mid / 15 - mid / 35 - mid / 21 + mid / (3 * 5 * 7);
		// cout << stt << "  " << l << " " << r << endl;
		if (stt >= n)
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout << mid <<" " << mid % 3 << " " << mid % 5 << " " << mid % 7 << endl;
	cout << mid + min(mid % 3, min(mid % 5, mid % 7));
}
