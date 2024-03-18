#include<bits/stdc++.h>

using namespace std;

string a[1000006],x;
long long n,k[30],dd[1000006];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 0; i <= 25 ; i++) {
		char t = (char) ((int) ('a') + i);
		cout << "count " << t << endl;
		cin >> k[i];
	}
	
	for (int i = 1; i <= n; i++) {
		
		
		for(int z = 0 ; z <= 25; z++) {
			
			if (dd[i] == 1) continue;
			
			char t = (char) ((int) ('a') + z);
			long long check = 0;
			
			for (int j = 0 ; j < a[i].length() ; j++) {
					if ( a[i][j] == t)
						check++;
			}
//			cout << check <<" " << k[z];
			if (check == k[z])
				dd[i] = 0;
			else dd[i] = 1;
//			cout << dd[i] << endl;
		}
	}
	
	long long s = 0,i;
	char r;
	
	for(int i = 1;i <= n ;i++)
		if (dd[i] == 0) s++;
	i = 0;
	while (s>1){
		cout << "getpos " << i <<endl;
		cin >> r;
		if (r == '#')
			for (int j = 1; j <= n; j++)
				if (a[j].length() >= i && dd[j] ==0 )
					dd[j] = 1,s--;
		else
			for (int j = 1;j <= n; j++)
				if (a[j][i] != r && dd[j] == 0)
					dd[j] = 1, s--;
		i++;
	}
	for (int i = 1;i <= n; i++)
		if (dd[i] == 0)
			cout << "answer " << a[i] << endl;
}
