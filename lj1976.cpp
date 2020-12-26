#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 1e4+10, M = 5e4+10, LG = 30;

struct E {int u, v, w;} edg[M];
vector<pii> G[N];
int n, m, q;

struct DSU
{
    int p[N];
    void init()
    {
        rep(i,1,n)
            p[i] = i;
    }
    int find (int x)
    {
        return (p[x]==x? x:p[x]=find(p[x]));    
    }
} dsu;

struct LCA
{
    int d[N], p[N][LG], minw[N][LG];
    void dfs (int u)
    {
        rep(i,1,LG-1)
        {
            p[u][i] = p[p[u][i-1]][i-1];
            minw[u][i] = min(minw[u][i-1], minw[p[u][i-1]][i-1]);
        }
        for (auto v: G[u])
        {
            if (v.ss==p[u][0]) continue;
            d[v.ss] = d[u]+1;
            p[v.ss][0] = u;
            minw[v.ss][0] = v.ff;
            dfs(v.ss);
        }
    }
    inline int query (int u, int v)
    {
        if (d[v]<d[u]) swap(u,v);
        int res = 1e9;
        for (int dif=d[v]-d[u],j=0; dif; dif>>=1,j++)
        {
            if (dif&1)
            {
                res = min(res, minw[v][j]);
                v = p[v][j];
            }
        }
        if (u == v)
        {
            return res;
        }
        int s = LG-1;
        while (s>=0)
        {
            if (p[u][s] == p[v][s])
            {
                s--;
            }
            else
            {
                res = min(res, minw[u][s]);
                res = min(res, minw[v][s]);
                u = p[u][s];
                v = p[v][s];
            }
        }
        res = min(res, minw[u][0]);
        res = min(res, minw[v][0]);
        return res;
    }
    void init()
    {
        mem(minw, 0x3f);
        rep(i,1,n)
        {
            if (d[i]) continue;
            d[i] = 1;
            dfs(i);
        }
    }
} lca;

int cmp (E i, E j)
{
    return i.w > j.w;
}

void krus()
{
    sort(edg+1, edg+1+m, cmp);
    dsu.init();
    rep(i,1,m)
    {
        int u=edg[i].u, v=edg[i].v, w=edg[i].w;
        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.p[dsu.find(u)] = dsu.find(v);
        G[u].pb({w,v});
        G[v].pb({w,u});
    }
}

signed main()
{
    ShinraTensei
    cin >> n >> m;
    rep(i,1,m)
        cin >> edg[i].u >> edg[i].v >> edg[i].w;
    krus();
    lca.init();
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (dsu.find(x) != dsu.find(y))
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << lca.query(x,y) << '\n';
        }
    }
}