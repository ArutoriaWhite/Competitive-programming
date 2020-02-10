#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

struct edge { int to, w, i; };
vector<edge> adj[N];
int T, n, w[N], id[N];
int p[N], max_son[N], sz[N], top[N], tin[N], dep[N], t;
int st[N<<2];

inline void init()
{
    for (auto &v: adj) v.clear();
    for (int i=0; i<N; i++) sz[i]=1;
    memset(max_son,-1,sizeof(max_son));
    t=0;
}

// heavy light dcomp
void dfs_max (int u)
{
    for (auto v: adj[u])
    {
        if (v.to == p[u]) continue;
        w[v.to] = v.w, id[v.i] = v.to;
        p[v.to]=u, dep[v.to] = dep[u]+1;
        dfs_max(v.to);
        sz[u]+=sz[v.to];
        if (max_son[u]==-1 || sz[v.to]>sz[max_son[u]]) max_son[u] = v.to;
    }
}
void dfs_link (int u, int tp)
{
    if (u==-1) return;
    top[u] = tp, tin[u] = t++, st[tin[u]+n] = w[u];
    dfs_link(max_son[u],tp);
    for (auto v: adj[u])
        if (v.to!=max_son[u]&&v.to!=p[u])
            dfs_link(v.to,v.to);
}

// seg
inline void build ()
{
    for (int i=n-1; i>0; i--)
        st[i] = max( st[i<<1], st[i<<1|1] );
}
inline void modify_st (int p, int x)
{
    for (st[p+=n] = x; p>1; p>>=1)
        st[p>>1] = max(st[p],st[p^1]);
}
inline int query_st (int l, int r)
{
    int res = -1e9;
    for (l+=n,r+=n; l<=r; l>>=1,r>>=1)
    {
        if (l&1) res = max(res,st[l++]);
        if (!(r&1)) res = max(res,st[r--]); 
    }
    return res;
}

// ask
inline void change_tr (int v, int x)
{
    modify_st(tin[id[v]],x);
}
inline int ask_tr (int a, int b)
{
    int res = -1e9, ta=top[a], tb=top[b];
    while (ta!=tb)
    {
        if (dep[ta]>dep[tb]) swap(a,b), swap(ta,tb);
        res = max(res, query_st(tin[tb],tin[b]));
        tb = top[b=p[tb]];
    }
    if (dep[a]<dep[b]) swap(a,b);
    res = max(res, query_st(tin[max_son[b]], tin[a]));
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        init();
        cin >> n;
        for (int i=1,u,v,w; i<=n-1; i++)
        {
            cin >> u >> v >> w;
            adj[u].push_back( {v,w,i} );
            adj[v].push_back( {u,w,i} );
        }
        dfs_max(1), dfs_link(1,1), build();
        string s;
        int x,y;
        while (cin >> s)
        {
            if (s[0] == 'Q')
                cin >> x >> y, cout << ask_tr(x,y) << '\n';
            else if (s[0] == 'C')
                cin >> x >> y, change_tr(x,y);
            else break;
        }
    }
}
