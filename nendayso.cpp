#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9;
long long n;

long long power(long long a, long long b){
	if (b == 0) return 1;
	long long s = power(a,b/2);
	s = s * s % mod;
	if (b % 2 == 0 )
		return s;
	return s * (a % mod) % mod; 
} 

int main(){
	cin >> n;
	
	cout << (n+1) % mod * power(2,n - 2)% mod ;
}
