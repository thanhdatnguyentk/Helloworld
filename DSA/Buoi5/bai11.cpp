#include<bits/stdc++.h>

using namespace std;

void decToBinary(int n) {
    if (n == 0) return;
    decToBinary(n / 2);
    cout << n % 2;
}

int main(){
    int n;
    cin >> n;
    decToBinary(n);
}
