#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define p(x) (x>>1)
#define br(x) (x^1)
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10, M = 3e5+10;

struct Edge {int u, v, w;} edges[M];
vector<Pii> adj[N];
int n, m, res;
queue<int> q;

inline void upd (int &a, int &b, int &c, int &d)
{
    if (c > a) b = a, a = c;
    else if (c > b) b = c;
    if (d > a) b = a, a = d;
    else if (d > b) b = d; 
}
namespace Dsu
{
    int p[N];
    inline void init() { for (int i=1; i<=n; i++) p[i] = i; }
    inline int find (int x) { return (p[x]==x? x : find(p[x])); }
    inline void U (int a, int b) { p[find(a)] = find(b); }
}
namespace Krus
{
    int mnw, i;
    inline void krus ()
    {
        Dsu::init();
        sort(edges,edges+m,[](Edge &a, Edge &b){return a.w < b.w;});
        for (i=0,mnw=0; i<m; i++)
        {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if (Dsu::find(u)!=Dsu::find(v))
            {
                Dsu::U(u,v), mnw += w;
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }
            else q.push(i);
        }
    }
}
namespace St
{
    int st[N<<1], st2[N<<1];

    inline void build() { for (int i=n-1; i>0; i--) upd(st[i],st2[i],st[ls(i)],st2[ls(i)]), upd(st[i],st2[i],st[rs(i)],st2[rs(i)]);}
    inline Pii query (int l, int r) // [l,r)
    {
        int a = 0, b = 0;
        for (l+=n,r+=n; l<r; l>>=1,r>>=1)
        {
            if (l&1) upd(a,b,st[l],st2[l]), l++;
            if (r&1) r--, upd(a,b,st[r],st2[r]);
        }
        return Pii{a,b};
    }
}
namespace Hld
{
    int dep[N], p[N], mson[N], sz[N], w[N], top[N], id[N], t=0;
    void dfs1 (int u)
    {
        mson[u] = -1, sz[u] = 1;
        for (auto e: adj[u])
        {
            if (e.F == p[u]) continue;
            w[e.F] = e.S, p[e.F] = u, dep[e.F] = dep[u]+1;
            dfs1(e.F);
            sz[u] += sz[e.F];
            if (mson[u]==-1 || sz[e.F]>sz[mson[u]])
                mson[u] = e.F;
        }
    }
    void dfs2 (int u, int lt)
    {
        top[u] = lt, id[u] = t++, St::st[id[u]+n] = w[u];
        if (mson[u] == -1) return;
        dfs2(mson[u],lt);
        for (auto e: adj[u])
            if (e.F != mson[u] && e.F != p[u])
                dfs2(e.F,e.F);
    }
    Pii query (int u, int v)
    {
        Pii x;
        int a=0, b=0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u,v);
            x =  St::query(id[top[u]],id[u]+1);
            upd(a,b,x.F,x.S);
            u = p[top[u]];
        }
        if (dep[u] > dep[v]) swap(u,v);
        x = St::query(id[mson[u]],id[v]+1);
        upd(a,b,x.F,x.S);
        return Pii{a,b};
    }
}


int main()
{
    Eriri
    cin >> n >> m;
    for (int i=0,u,v,w; i<m; i++)
    {
        cin >> u >> v >> w;
        if (u!=v) edges[i] = {u,v,w};
    }

    Krus::krus();
    Hld::dfs1(1);
    Hld::dfs2(1,1);
    St::build();

    res = INT_MAX;
    while (!q.empty())
    {
        int i = q.front(); q.pop();
        Pii mw = Hld::query(edges[i].u,edges[i].v);
        res = min(res, Krus::mnw - (mw.F<edges[i].w? mw.F : mw.S) + edges[i].w);
    }
    cout << res << '\n';
}
/*
6
1 5 13
1 2 10
2 6 14
2 3 11
3 4 12
*/