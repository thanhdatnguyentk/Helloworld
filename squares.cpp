#include<bits/stdc++.h>

using namespace std;

long long n,k,res;


int main(){
	cin >> n;
	long long a = n % 12078;
	long long b = (n + 1) % 12078;
	long long c = (2 * n + 1) % 12078;
	long long int ans = a * b % (12078) * c % 12078;
	cout << ans / 6;
	return 0;
}
/*
a ^ b % c
a / b % c
= a * b ^ (c - 2) % c
