#include<bits/stdc++.h>

using namespace std;

long long mod =  1e9 + 7;
long long n,snt[10000005],a,dpp[10000005],res = 1;

void sang() {
	snt[1] = 1;
	for (int i = 2; i <= 10000000 ; i++ )
		{
			if (snt[i] > 0 ) continue;
			
			for (int j = i ; j <= 10000000; j += i)
				snt[j] = i;
		}
}

long long power(long long a, long long b){
	long long k = 1;
	while (b--){
		k = k * a %  mod;
	}	
	return k;
}


int main(){
	sang();
	cin >> n;
	for (int i = 1; i <= n ;i++)
		{
			cin >> a;
			int x = a;
			while (x > 1) {
				long long k = snt[x], dk = 0;
				while ( x % k == 0 )
					{
						dk++;
						x /= k;
					}
					
				dpp[k] = max(dpp[k], dk);
			}
		}
	
	for (int i = 2; i <= 10000000; i++) {
        if (dpp[i] % 2 == 1) {
            dpp[i]++;
        }
        for (int j = 1; j <= dpp[i]; j++) {
            res = res * i % mod;
        } 
    }
	
	cout << res;
	}
