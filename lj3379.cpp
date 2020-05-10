#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e5+10, LOG = 30;

vector<int> adj[N];

namespace Lca
{
    int an[N][LOG];
    void dfs (int u, int p)
    {

    }
    inline int query (int u, int v)
    {
        \   
    }
}

int main()
{
    cin >> n >> m >> s;
    for (int i=0,u,v; i<n-1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Lca::dfs(1,0);
    for (int i=0,u,v; i<m; i++)
        cout << query(u,v) << '\n';
}