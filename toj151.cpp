#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 5e4+10;
/*
scc find scc sz and min node in scc

find ind = 0 scc && not capital scc
*/

int n, m;
vector<int> G[N], Gt[N], st;
int sccid[N], scc, nod[N], sz[N], vis[N];
unordered_set<int> in[N];

void dfs (int u, vector<int> *adj, int k=0)
{
    vis[u] = 1;
    sccid[u] = k;
    nod[k] = min(nod[k], u);
    sz[k]++;
    for (auto v: adj[u])
    {
        if (adj==Gt && vis[v] && sccid[v]!=k) in[k].insert(sccid[v]);
        if (!vis[v]) dfs(v,adj,k);
    }
    if (adj == G) st.push_back(u);
}

void kosaraju ()
{
    rep(i,1,n) if(!vis[i]) dfs(i,G);
    memset(vis,0,sizeof(vis));
    memset(nod,0x3f,sizeof(nod));
    for (;!st.empty();st.pop_back())
        if (!vis[st.back()]) dfs(st.back(),Gt,++scc);
}

signed main()
{
    XinAi
    cin >> n >> m;
    for (int i=0,u,v; i<m; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        Gt[v].push_back(u);
    }
    kosaraju();
    int mxval=0, mnode=0;
    rep(i,1,scc)
    {
        if (sz[i] > mxval)
            mxval=sz[i], mnode = nod[i];
        else if (sz[i]==mxval && nod[i]<mnode)
            mnode = nod[i];
    }
    int res=0;
    rep(i,1,scc)
        if (i!=sccid[mnode] && !in[i].size())
            res++;
    cout << mnode << ' ' << res << '\n';
}
/*
5 5
1 2
2 3
3 4
4 2
3 5
*/
