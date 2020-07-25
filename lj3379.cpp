#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e5+10;

struct Edge{
    int next, v;
} e[N<<1];
int n, m, s, cnt, h[N], d[N], p[N][25];

inline void add (int u, int v)
{
    cnt++;
    e[cnt] = {h[u],v};
    h[u] = cnt;
}
void dfs (int u, int pa)
{
    d[u] =  d[pa]+1, p[u][0] = pa;
    for (int j=1; (1<<j)<=d[u]; j++)
        p[u][j] = p[p[u][j-1]][j-1];
    for (int i=h[u]; i!=0; i=e[i].next)
        if (e[i].v != pa) dfs(e[i].v,u);
}
inline int query (int u, int v)
{
    if (d[v] < d[u]) swap(u,v);
    for (int tmp=d[v]-d[u],j=0; tmp; tmp>>=1,j++)
        if (tmp&1) v = p[v][j];
    if (u==v) return u;
    for (int s=20; s>=0; s--)
        if (p[u][s]!=p[v][s])
            u = p[u][s], v = p[v][s];
    return p[u][0];
}

int main()
{
    Eriri
    cin >> n >> m >> s;
    for (int i=0,u,v; i<n-1; i++)
    {
        cin >> u >> v;
        add(u,v), add(v,u);
    }
    dfs(s,0);
    for (int i=0,u,v; i<m; i++)
    {
        cin >> u >> v;
        cout << query(u,v) << '\n';
    }
}