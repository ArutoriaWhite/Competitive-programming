#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10;

vector<Pii> adj[N];
int a[N], sz[N], sum[N], res, n;

void dfs1 (int u, int p)
{
    sz[u] = 1;
    for (auto e: adj[u])
    {
        if (e.F != p)
        {
            sum[e.F] = max(e.S, sum[u]+e.S);
            dfs1(e.F,u);
            sz[u] += sz[e.F];
        }
    }
}
void dfs2 (int u, int p)
{
    if (sum[u] > a[u])
    {
        res += sz[u];
        return;
    }
    for (auto e: adj[u])
        if (e.F != p)
            dfs2(e.F,u);
}

signed main()
{
    Eriri
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1,u,w; i<n; i++)
    {
        cin >> u >> w;
        adj[u].push_back({i+1,w});
        adj[i+1].push_back({u,w});
    }
    dfs1(1,0);
    dfs2(1,0);
    cout << res << '\n';
}
/*
give a tree
the node i has ai, the farest in it's subtree doesn't exceed ai
ans the min modify to remove all leaves

pre[u], lim[u]
pre[v] = pre[u]+w, s[v] += pre[v]
lim[v] = min(lim[u],s[u])
*/2