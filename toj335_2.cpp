#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10, M = 1e6+10;

int n, m, q;
struct Edge {int u, v, w;} edges[M];
vector<Pii> adj[N];
namespace Krus
{
    int p[N], res=0;
    int find (int x)  { return (p[x]==-1? x : p[x]=find(p[x])); }
    void U (int a, int b) { p[find(a)] = find(b); }

    void krus()
    {
        sort(edges,edges+m,[](Edge &a, Edge &b){ return a.w > b.w; });
        memset(p,-1,sizeof(p));
        for (int i=0; i<m; i++)
        {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if (find(u) != find(v))
            {
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
                U(u,v);
                res += w;
            }
        }
    }
}
namespace Lca
{
    int f[N][30], st[N][30], d[N];
    void init() { memset(st,0x3f,sizeof(st)); }
    void dfs (int u, int p)
    {
        for (int j=1; j<30; j++)
        {
            f[u][j] = f[ f[u][j-1] ][j-1];
            st[u][j] = min(st[u][j-1], st[f[u][j-1]][j-1]);
        }
        for (auto e: adj[u])
            if (e.F != p)
                f[e.F][0]=u, st[e.F][0]=e.S, d[e.F]=d[u]+1, dfs(e.F,u);
    }
    int lca (int u, int v)
    {
        int res = INT_MAX;
        if (d[u] > d[v]) swap(u,v);
        for (int h=d[v]-d[u],j=0; h; h>>=1,j++)
            if (h&1)
                res = min(res,st[v][j]), v = f[v][j];
        if (u == v) return res;
        for (int s=30; s>=0; s--)
        {
            if (f[u][s] != f[v][s])
            {
                res = min(st[v][s], min(res, st[u][s]));
                u = f[u][s], v = f[v][s];
            }
        }
        res = min( st[v][0], min(res,st[u][0]));
        return res;
    }
}

int main()
{
    Eriri
    cin >> n >> m;
    for (int i=0; i<m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    Krus::krus();
    Lca::init();
    Lca::dfs(0,-1);
    cin >> q;
    for (int i=0,u,v; i<q; i++)
    {
        cin >> u >> v;
        cout << Lca::lca(u,v) << '\n';
    }
}
/*
4
4
0
2
3
0
1
1
1
2
4
2
3
2
6
0
1
0
2
0
3
1
2
1
3
2
3
*/