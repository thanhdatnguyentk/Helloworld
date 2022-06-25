#include<bits/stdc++.h>
using namespace std;

vector<int> v,m;
int n;

int t,k,a[10000007];
int dd[100005];
int res[100005];
bool ktr;

int main() {
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		
		for (int i = 1 ; i <= k; i++){
			
			int last = 1;
			int u = 1;
			
			for (int j = last; j <= n ;j++)
				{
					if (a[j] == i)
						{
							for (int x = 1; x <= k ; x++)
								dd[x] = 0;
							
							for (int x = 1; x <= u ; x++)
								dd[res[x]] = 1 ;
							for (int x = j + 1; x <= n ; x++)
								dd[a[x]] = 1;
							for (int x = 1; x <= n; x++)
								if (dd[x] == 0)
									ktr = false;
							if (ktr == true){
								res[u] = a[j];
								u++;
								last = j;
							}
						}
				}
		}
		for (int i  = 1; i<= k ; i++)
			cout << res[i] << " ";
		cout << endl;
	}
    return 0;
}
