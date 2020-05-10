#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10;

vector<int> adj[N];
int n, d, h1[N], h2[N], mson[N], fir=1;

inline void upd (int u, int v, int h)
{
    if (h >= h1[u]) h2[u] = h1[u], h1[u] = h, mson[u] = v;
    else if (h > h2[u]) h2[u] = h;
}
inline void dfs1 (int u, int p)
{
    h1[u] = 1;
    for (auto v: adj[u])
        if (v != p)
            dfs1(v,u), upd(u,v,h1[v]+1);
}
inline void dfs2 (int u, int p)
{
    if (u != mson[p]) upd(u,p,h1[p]+1);
    else upd(u,p,h2[p]+1);
    for (auto v: adj[u])
        if (v!=p) dfs2(v,u);
}
inline void dfs3 (int u, int p)
{
    if (fir) fir = 0;
    else cout << ' ';
    cout << u;
    for (auto v: adj[u])
        if (v != p)
            dfs3(v,u);  
}
inline void print()
{
    for (int i=1; i<=n; i++)
    {
        if (h1[i]<d && h2[i]<d)
        {
            dfs3(i,0);
            cout << '\n';
            return;
        }        
    }
    cout << -1 << '\n';
}
inline void print_h()
{
    for (int i=1; i<=n; i++)
        de(i), de(h1[i]), de(h2[i]), de(mson[i]), dend;
}

int main()
{
    Eriri
    cin >> n >> d;
    for (int i=0,a,b; i<n-1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; i++)
        sort(adj[i].begin(), adj[i].end());
    dfs1(1,0);
    dfs2(1,0);
    print();
}
/*
7 5
1 2
1 7
1 6
3 2
3 4
5 4
*/