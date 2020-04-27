#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 2e5+10;

vector<int> adj[N];
int n, k, sz[N], dep[N], w[N], r, res;

void dfs (int u, int p)
{
    sz[u] = 1, dep[u] = dep[p]+1;
    for (auto v: adj[u])
        if (v!=p)
            dfs(v,u), sz[u] += sz[v];
    w[r++] = dep[u]-sz[u];
}


signed main()
{
    Eriri
    cin >> n >> k;
    for (int i=0,u,v; i<n-1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    sort(w,w+r,[](int a, int b){return a>b;});
    for (int i=0; i<k; i++)
        res += w[i];
    cout << res << '\n';
}
