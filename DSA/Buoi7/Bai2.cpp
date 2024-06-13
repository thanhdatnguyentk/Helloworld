
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

vector<int> get_ans(const vector<int> &A, int K)
{
    map<int, int> Hash;
    vector<int> ans;

    for (const int &x : A)
    {
        Hash[x]++;
    }

    for (auto &x : Hash)
    {
        if (x.second >= 0)
            ans.push_back(x.first), x.second--, K--;
    }

    for (auto &x : Hash)
    {
        while (x.second > 0 && K > 0)
            ans.push_back(x.first), x.second--, K--;
        if (K == 0)
            break;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans = get_ans(a, k);

    for (const int &x : ans)
        cout << x << ' ';
    return 0;
}
