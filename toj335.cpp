#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f, N = 1e5+10, M = 1e6+10;

struct edge {int a, b, w;} edges[M];
vector<pii> adj[N];
int disp[N], n, m, nod[N], w[N];
int ltop[N], id[N], p[N], d[N], sz[N], mson[N], cnt, q;
int st[N<<1];

inline void init()
{
    
    for (int i=0; i<N; i++) disp[i] = i;
}

// krukal
int find (int x)
{
    return (x==disp[x]? x : disp[x]=find(disp[x]));
}
inline void uni (int x, int y)
{
    disp[find(x)] = find(y);
}

inline void krus ()
{
    sort(edges,edges+m,[](const edge &a, const edge &b){return a.w > b.w;});
    for (int i=0; i<m; i++)
        if (find(edges[i].a) != find(edges[i].b))
        {
            uni(edges[i].a,edges[i].b);
            adj[edges[i].a].push_back({edges[i].b, edges[i].w});
            adj[edges[i].b].push_back({edges[i].a, edges[i].w});
        }
}

// segment tree
inline void st_build()
{
    for (int i=0; i<n; i++) st[i+n] = w[nod[i]];
    for (int i=n-1; i>=1; i--) st[i] = min( st[i<<1], st[i<<1|1]);
}
inline int st_query (int l, int r)
{
    int res = INF;
    for (l+=n, r+=n; l<=r; l>>=1,r>>=1)
    {
        if (l&1) res = min(res, st[l++]);
        if (!(r&1)) res = min(res, st[r--]);
    }
    return res;
}

// heavy light decomp
inline void dfs_maxson (int u)
{
    sz[u] = 1, mson[u] = -1;
    for (auto v: adj[u])
        if (v.fi != p[u])
        {
            p[v.fi] = u, d[v.fi] = d[u]+1;
            dfs_maxson(v.fi);
            sz[u] += sz[v.fi];
            if (mson[u]==-1 || sz[v.fi] > sz[mson[u]])
                mson[u] = v.fi;
            w[v.fi] = v.se;
        }
}
inline void set_top (int u, int t)
{
    id[u] = cnt++, nod[id[u]] = u, ltop[u] = t;
    if (mson[u]==-1) return;
    set_top(mson[u], t);
    for (auto v: adj[u])
        if (v.fi!=mson[u] && v.fi!=p[u])
            set_top(v.fi,v.fi);
}
inline int hld_query (int a, int b)
{
    int res = INF;
    while (ltop[a]!=ltop[b])
    {
        if (d[ltop[a]]>d[ltop[b]]) swap(a,b);
        res = min( res, st_query(id[ltop[b]],id[b]) );
        b = p[ltop[b]];
    }
    if (d[a]>d[b]) swap(a,b);
    res = min( res, st_query(id[mson[a]],id[b]));
    return res;
}
int main()
{
	cout << "ria\n" << '\n';
    init();
    cin >> n >> m;
    for (int i=0,a,b,w; i<m; i++)
        cin >> a >> b >> w, edges[i] = {a,b,w};
    krus();
    dfs_maxson(0), set_top(0,0), st_build();
    cin >> q;
    while (q--)
    {
		cout << "hi" << '\n';
        int a, b;
        cin >> a >> b;
        cout << "::" << hld_query(a,b) << '\n';
    }
}
/*
4 4
0 2 3
0 1 1
1 2 4
2 3 2
6
0 1
0 2
0 3
1 2
1 3
2 3
*/