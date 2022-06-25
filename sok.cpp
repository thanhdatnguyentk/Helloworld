#include<bits/stdc++.h>

using namespace std;

long long n;

int main() {
	for (int i = 1; i <= 200 ; i++)
		if ( i % 3 == 0 || i % 5 == 0 || i % 7 == 0 )
			cout << i <<" ";
}
