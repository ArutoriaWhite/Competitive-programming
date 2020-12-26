#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int n, m, t;
vector<int> G[N], Gt[N];

vector<int> ord;
int vis[N], sccid[N], scc, in[N];
void dfs (vector<int> *adj, int u, int k=0)
{
    sccid[u] = k;
    vis[u] = 1;
    if (adj==G) ord.push_back(u);
    for (auto v: adj[u])
    {
        if (!vis[v]) dfs(adj,v,k);
        else if (sccid[v]!=k) in[k]++;
    }
}
inline void kosa()
{
    memset(vis,0,sizeof(vis));
    memset(sccid,0,sizeof(sccid));
    memset(in,0,sizeof(in));
    scc=0;
    ord.clear();
    rep(i,1,n) if(!vis[i]) dfs(G,i);
    memset(vis,0,sizeof(vis));
    for (auto x: ord)
        if(!vis[x]) dfs(Gt,x,++scc);
}

signed main()
{
    haaachamachama
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        rep(i,0,n) G[i].clear(), Gt[i].clear();
        for (int i=0,u,v; i<m; i++)
        {
            cin >> u >> v;
            G[u].push_back(v);
            Gt[v].push_back(u);
        }
        kosa();
        int res=0;
        rep(i,1,scc) res += !in[i];
        cout << res << '\n';
    }
}