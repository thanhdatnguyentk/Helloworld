#include<bits/stdc++.h>

using namespace std;

long long n = sqrt(1e3+1);
long long k, a[10000007] , d;

int main() {
	cin >> k;
	for (int i = 1; i <= n ; i++ )
		for (int j = 1; j <= n; j++) {
			d++;
			a[d] = i * i + j * j;
		}
	
	sort (a+1,a+1+1000000);
	cout << a[k];
}
