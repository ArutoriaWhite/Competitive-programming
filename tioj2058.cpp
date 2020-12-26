#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int t, n, m, rt, ed, d1[N], d2[N];
vector<pii> adj[N];

inline int update (int u, int d)
{
    if (d < d1[u])
    {
        d2[u] = d1[u], d1[u] = d;
        return 1;
    }
    else if (d != d1[u] && d<d2[u])
    {
        d2[u] = d;
        return 1;
    }
    return 0;
}
void dijks()
{
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0, rt});
    while (!pq.empty())
    {
        int u=pq.top().S, d=pq.top().F; pq.pop();
        if (d > d2[u]) continue;
        for (auto e: adj[u])
            if (update(e.S, d+e.F))
                pq.push({d+e.F, e.S});
    }
}

signed main()
{
    XinAi
    cin >> t;
    while (t--)
    {
        memset(d1, 0x3f, sizeof(d1));
        memset(d2, 0x3f, sizeof(d2));
        cin >> n >> m >> rt >> ed;
        rep(i,0,n) adj[i].clear();
        for (int i=0,u,v,w; i<m; i++)
        {
            cin >> u >> v >> w;
            adj[u].push_back({w, v});
        }
        dijks();
        cout << d2[ed]-d1[ed] << '\n';
    }
}