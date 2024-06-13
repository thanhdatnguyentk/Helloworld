
#include <bits/stdc++.h>
using namespace std;


int N;

int count_distinct(vector<int>& ids){

	map<int,int> Hash; 
	
    for (int& x: ids) {
        Hash[x]++;
    }
    long long ans = 0;
    for (auto& x: Hash) {
        if (x.second > 0) ans += min(x.second, abs(x.second - x.first));
    }
    return ans;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> N;
	vector<int> ids(N);
	
	for (int i = 0; i < N; i++) cin >> ids[i];
		
	cout << count_distinct(ids);

	return 0;
}

