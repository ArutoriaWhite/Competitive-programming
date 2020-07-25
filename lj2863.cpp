#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e4+10;

vector<int> G[N], rG[N];
int res, n, m;

struct Scc
{
    int vis[N], vis2[N], amt[N], cnt;
    vector<int> sta;

    void dfs1 (int u)
    {
        if (vis[u]) return;
        vis[u] = 1;
        for (auto v: G[u])
            dfs1(v);
        sta.push_back(u);
    }
    void dfs2 (int u, int id)
    {
        if (vis2[u]) return;
        vis2[u] = 1;
        amt[id]++;
        for (auto v: rG[u])
                dfs2(v,id);
    }
    void kosa()
    {
        for (int i=1; i<=n; i++)
            dfs1(i);
        while (!sta.empty())
        {
            if (!vis2[sta.back()])
                dfs2(sta.back(),++cnt);
            sta.pop_back();
        }
    }
} scc;

int main()
{
    Eriri
    cin >> n >> m;
    for (int i=0,u,v; i<m; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    scc.kosa();
    for (int i=1; i<=scc.cnt; i++)
        if (scc.amt[i] > 1) res++;
    cout << res << '\n';
}