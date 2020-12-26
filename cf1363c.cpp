#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1010;

vector<int> G[N];
int sz[N], n, rt, t, ind[N];

void dfs (int u, int p)
{
    sz[u] = 1;
    for (auto v: G[u])
        if (v!=p)
            dfs(v,u), sz[u]+=sz[v];
}

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n >> rt;
        rep(i,1,n) G[i].clear();
        rep(i,1,n) ind[i] = 0;
        for (int i=0,u,v; i<n-1; i++)
        {
            cin >> u >> v;
            G[u].pb(v), G[v].pb(u);
        }
        if (G[rt].size()<2) cout << "Ayush\n";
        else
        {
            dfs(rt,rt);
            int sum = sz[rt]-3;
            if (sum&1) cout << "Ayush\n";
            else cout << "Ashish\n";
        }
    }
}
/*
1
6 4
3 2
1 6
4 6
6 5
1 3

1
4 1
1 3
2 1
4 1
*/