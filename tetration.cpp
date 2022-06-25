#include<bits/stdc++.h>

using namespace std;

long long a, n, m , mod;

long long power(long long a, long long b){
	if (b == 0) return 1;
	long long s = power(a,b/2);
	s = s * s % mod;
	if (b % 2 == 0 )
		return s;
	return s * (a % mod) % mod; 
} 

long long pt(long long a, long long b) {
	if (b == 1) return a;
	long long s = power(a, pt(a,b-1)) ;

	return s % m;
}


int main() {
	cin >> a >> n >> m;

	mod = m;
	cout << pt(a, n);
}

