#include<bits/stdc++.h>

using namespace std;

string a;

long long d,check,ltr;

int main() {
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '(')
			d++,check++;
		else if (d > 0) {
			d--,check--;
		}
		else {
			ltr = i,check--;
		}
	}
	if (check!=0 ) {
		cout <<"-1";
	}
	else
	cout <<ltr + 1 ;
}
