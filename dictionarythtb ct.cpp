#include<bits/stdc++.h>

using namespace std;

string a[1000006],x;
long long n,k[30],dd[1000006];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	char r ='a' ;
	long long i = 0;
	while (r == '#')
	{
		cout << "getpos " << i << endl;
		cin >> r;
		if (r == '#') break;
		x += r;
	}
	cout << x;
}
