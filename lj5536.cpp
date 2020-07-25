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
int rt, p[N], d[N], maxd[N], dis[N], n, k;

void dfs (int u)
{
    if (rt==0 || d[rt]<d[u])
        rt = u;
    for (auto v: adj[u])
        if (v != p[u])
            p[v] = u, d[v] = d[u]+1, dfs(v);
}
void balance()
{
    dfs(1);
    d[rt] = p[rt] = 0;
    dfs(rt);
    for (int i=d[rt]/2; i>0; i--)
        rt = p[rt];
}
void dfs2 (int u, int f)
{
    maxd[u] = d[u];
    for (auto v: adj[u])
    {
        if (v != f)
        {
            d[v] = d[u]+1;
            dfs2(v,u);
            maxd[u] = max( maxd[u], maxd[v] );
        }
    }
}

int main()
{
    Eriri
    cin >> n >> k;
    for (int i=0,u,v; i<n-1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    balance();
    d[rt] = p[rt] = 0;
    dfs2(rt,0);
    for (int i=1; i<=n; i++)
        dis[i-1] = maxd[i]-d[i];
    sort(dis,dis+n,[](int a, int b){return a>b;});
    cout << dis[k]+1 << '\n';
}