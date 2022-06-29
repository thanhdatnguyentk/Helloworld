#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long a, n, m , mod;

long long power(long long a, long long b){
	if (b == 0) return 1%mod;
	long long s = power(a,b/2);
	ll t = s * s % mod;
	if (b % 2 == 0 )
		return t;
	return t * (a % mod) % mod; 
} 

long long pt(long long a, long long b) {
	if (b == 1) return a;
	long long s = power(a, pt(a,b-1)) ;

	return s % m;
}


int main() {
	cin >> a >> n >> m;
	 
	mod = m;

	if ( n==1 ){
		cout << a%mod ;
		return 0;
	}

	long long s = power(a,a); 

	for ( ll i=1;i<=n-2;i++ ){
		power ( a,s );
		cout << s << "\n";
	}
	cout << s;
}

