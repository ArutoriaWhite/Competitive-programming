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
const int N = 1e4+10;

int n, m, scc;
int sum[N], sccid[N], vis[N], szscc[N], out[N];
vector<int> G[N], Gt[N], st;

void dfs (vector<int> *adj, int u, int k=0)
{
    sccid[u] = k;
    szscc[k]++;
    vis[u] = 1;
    for (auto v: adj[u])
    {
        if (vis[v] && sccid[v]!=k)
            out[sccid[v]]++;
        if (vis[v]) continue;
        dfs(adj,v,k);
    }
    if (adj==G)
        st.pb(u);
}

void kosa()
{
    mem(vis,0);
    rep(i,1,n)
        if (!vis[i])
            dfs(G,i);
    mem(vis,0);
    while (!st.empty())
    {
        int x = st.back(); st.pop_back();
        if (!vis[x]) dfs(Gt,x,++scc);
    }
}

signed main()
{
    cin >> n >> m;
    rep(i,1,m)
    {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        Gt[v].pb(u);
    }
    kosa();
    int cnt=0, sz=0;
    rep(i,1,scc)
    {
        if (out[i]==0)
        {
            cnt++;
            sz = szscc[i];
        }
    }
    if (cnt==1) cout << sz << '\n';
    else cout << 0 << '\n';
}