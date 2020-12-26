#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define shaaark ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;
/*
sz[u]: weight sum of dfs sub tree
*/
vector<int> G[N];
int n, m, w[N];
int sz[N], ssz[N], d[N], l[N], isap[N], tt;

void dfs (int u, int p)
{
    ssz[u] = w[u];
    sz[u] = w[u];
    d[u] = l[u] = ++tt;
    for (auto v: G[u])
    {
        if (v==p) continue;
        if (!d[v])
        {
            dfs(v,u);
            sz[u] += sz[v];
            l[u] = min(l[u], l[v]);
            if (l[v]>=d[u]) ssz[u] += sz[v];
        }
        else
            l[u] = min(l[u], d[v]);
    }
}
signed main()
{
    shaaark
    cin >> n >> m;
    rep(i,1,n) cin >> w[i];
    for (int i=0,u,v; i<m; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0,0);
    int mnode, mval=-1e9;
    //rep(i,1,n) de(i), de(l[i]), de(d[i]), de(sz[i]), de(ssz[i]), dd
    rep(i,1,n)
        if (ssz[i]>mval) mval=ssz[i], mnode=i;
    cout << mnode << '\n';
}
/*
3 3
3 2 2
0 2
2 3
0 1

3 4
1 1 1 
0 1
0 3
1 2
2 3
*/
