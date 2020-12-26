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
const int N = 110;

int n, u, op, ed, m, vis[N], cnt;
vector<pii> e;
vector<int> G[N];

void add_edge (int u, int v, int w)
{
    G[u].pb(e.size());
    e.pb({v,w});
    G[v].pb(e.size());
    e.pb({u,w});
}
int dfs (int u, int f)
{
    if (u==ed) return f;
    for (auto eid: G[u])
    {
        int v = e[eid].ff;
        int w = e[eid].ss;
        if (w <= 0) continue;
        if (vis[v]==cnt) continue;
        vis[v] = cnt;
        int nf = dfs(v,min(f,w));
        if (nf > 0)
        {
            e[eid].ss -= nf;
            e[eid^1].ss += nf;
            return nf;
        }
    }
    return 0;
}
int ffa () // return max flow
{
    int ans=0;
    while (1)
    {
        cnt++;
        int f = dfs(op,1e9);
        if (f<=0) break;
        ans += f;
    }
    return ans;
}

signed main()
{
    ShinraTensei
    while (cin >> n && n)
    {
        e.clear();
        rep(i,0,N-1) G[i].clear();
        cin >> op >> ed >> m;
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            add_edge(u,v,w);
        }
        cout << "Network " << ++u << "\n";
        cout << "The bandwidth is " << ffa() << ".\n\n";
    }
}