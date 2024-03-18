#include<bits/stdc++.h>

using namespace std;

multiset<int, greater<int> > s;
multiset<int, greater<int> >::iterator itr;

int n, m, c[1000001], kc[10000001];

bool check(long long mi) {
	int d = 0;
	for (int i = 1; i < n ; i++) {
		if (kc[i] > mi)
			d += (kc[i] -1) / (mi)  ;
			
	}
	if (d > m - n )
		return false;
	
	return true;
}

int main(){
	
	cin >> n >> m;
	
	for (int i = 1; i<= n ; i++)
		cin >> c[i];
		
	sort(c+1,c+1+n);
	
	for (int i = 1; i< n ; i++)
		kc[i] = c[i+1] - c[i];
	
	for (int i = 1; i< n ;i++)
		cout << kc[i] << " ";
	
	if (n > m) {
		int i = 1, mi = INT_MAX;
		while (i <= n) {
			s.insert(kc[i]);
			if (s.size() == m - 1){
				
					mi = min(*s.begin(), mi);
					s.erase(kc[i-m+1]);
				}
			i++;
		}
		cout << mi ;
	}
	else {
		long long l = 0, r= 1e9, mid;
		while (l < r) {
			mid = (l+r)/2;
			if (check(mid) == true)	{
				r = mid;
			}
			else
				l = mid + 1;
		}
		cout << r;
	}
	
}
