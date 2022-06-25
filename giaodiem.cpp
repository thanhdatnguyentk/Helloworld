#include<bits/stdc++.h>

#define N 2123456

using namespace std;

long long n;

int main() {
	cin >> n;
	
	long long a = n ;
	long long b = n - 1;
	long long c = n - 2;
	long long d = n - 3;
	
	a %= 2014 * 24;
	b %= 2014 * 24;
	c %= 2014 * 24;
	d %= 2014 * 24;

	long long res = a * b % (24 * 2014) * c % (24*2014) *d % (24 * 2014);
	cout << res /24; 
}
