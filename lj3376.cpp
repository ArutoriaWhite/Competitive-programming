#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 210;

int n, m, op, ed;
int vis[N], used;
vector<int> G[N];
vector<pii> E;

inline void add (int u, int v, int w)
{
    G[u].pb(E.size());
    E.pb({w,v});
    G[v].pb(E.size());
    E.pb({0,u});
}
int dfs (int u, int cf)
{
    if (u==ed) return cf;
    vis[u] = used;
    for (auto eid: G[u])
    {
        int v = E[eid].ss, w = E[eid].ff;
        if (vis[v]==used || w==0) continue;

        int nf = dfs(v,min(cf,w));
        if (nf > 0)
        {
            E[eid].ff -= nf;
            E[eid^1].ff += nf;
            return nf;
        }
    }
    return 0;
}
int ffa()
{
    int res = 0;
    while (1)
    {
        used++;
        int f = dfs(op,9e18);
        if (f<=0) break;
        res += f;
    }
    return res;
}

signed main()
{
    E.reserve(5e3+10);
    ShinraTensei
    cin >> n >> m >> op >> ed;
    rep(i,1,m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u,v,w);
    }
    cout << ffa() << '\n';
}