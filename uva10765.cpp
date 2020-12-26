#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define val(u) (isap[u]? bridge[u] : 1)
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e4+10;

vector<int> adj[N];
int l[N], d[N], t;
int n, m, isap[N], bridge[N], vis[N], id[N];

inline void init()
{

}
void dfs (int u, int p)
{
    l[u] = d[u] = ++t;
    vis[u] = 1;
    for (auto v: adj[u])
    {
        if (v == p) continue;
        if (!vis[v])
        {
            dfs(v,u);
            l[u] = min(l[u], l[v]);
            if (l[v] >= d[u])
                isap[u] = 1;
            if (l[v] > d[u])
                bridge[u]++, bridge[v]++;
        }
        else l[u] = min(l[u], d[v]);
    }
}
inline bool cmp (int u, int v)
{
    if (val(u) == val(v)) return u < v;
    return val(u) > val(v);
}
int main()
{
    Eriri;
    while (cin >> n >> m, n&&m)
    {
        init();
        int u, v;
        while (cin >> u >> v, u!=-1&&v!=-1)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,0);
        for (int i=0; i<n; i++)
            id[i] = i;
        sort(id,id+n,cmp);
        for (int i=0; i<m; i++)
            cout << id[i] << ' ' << val(i) << '\n';
        cout << '\n';
    }
}