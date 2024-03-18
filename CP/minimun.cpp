#include<bits/stdc++.h>

using namespace std;

int n,k,a[500005],pp[10000007];
set <int> b;

int main(){
	cin >> n >> k;
	for (int i = 1 ;i <= n ; i++)
		cin >> a[i];
	for (int i = 1; i <= n ; i++) {
			b.insert(a[i]);
			pp[a[i]]++;
			if (i>=k) {
				cout << *b.begin() << "\n";
				if (pp[a[i-k+1]]>= 2)
					pp[a[i-k+1]]--;
				else 
					b.erase(a[i-k+1]),pp[a[i-k+1]]--;
				}
		}
}
