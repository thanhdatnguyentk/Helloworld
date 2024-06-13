#include<bits/stdc++.h>

using namespace std;

void dfs(long long u, vector<long long> g[], bool visited[]){
    visited[u] = true;
    for (long long i = 0; i < g[u].size(); i++)
    {
        if (!visited[g[u][i]])
        {
            dfs(g[u][i], g, visited);
        }
    }
}

bool visited[2000];
vector<long long> g[4000];
int main(){
    long long m, n;
    cin >> m >> n;
    for (long long i = 0; i < n; i++)
    {
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, g, visited);
    for (long long i = 1; i < m; i++)
    {
        if (visited[i])
        {
            cout << "CO" << endl;
        }
        else{
            cout << "KHONG" << endl;
        }
    }
}