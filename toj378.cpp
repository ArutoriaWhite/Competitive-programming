#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;
const int N = 1e5+10;

vector<Pii> adj[N];
int h1[N], h2[N], n, m, res;

inline void upd (int u, int h)
{
    if (h>=h1[u]) h2[u] = h1[u], h1[u] = h;
    else if (h>h2[u]) h2[u] = h;
}
inline void dfs (int u, int p)
{
    for (auto e: adj[u])
        if (e.F!=p)
            dfs(e.F,u), upd(u,h1[e.F]+e.S);
    res = max(res, h1[u]+h2[u]);
}

int main()
{
    cin >> n >> m;
    for (int i=0,u,v,w; i<m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(0,-1);
    cout << res << '\n';
}
/*
10 9
9 6 990
9 3 879
8 2 775
3 7 502
4 2 264
2 3 878
5 8 218
7 1 868
7 0 302
*/