#include<bits/stdc++.h>

using namespace std;

long long a, b, n, d;

int  x, y;
void exE(int A, int B) {
    if (B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        exE(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int main(){
	cin >> a >> b >> n;
	exE(a,b);	
	long long t = d;
	if (n % t != 0)
		cout <<"-1";
	else {
			
		}
}
//
//Ax + By = n, n = gcd * t  => a = a1 * t, b = b1 *t
//				
//A1x + B1y = GCD 

