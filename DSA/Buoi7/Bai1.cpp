#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    set<long long> a;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        a.insert(x);
    }
    cout << a.size() << endl;
    for (auto i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }
}