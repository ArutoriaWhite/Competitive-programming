#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

vector<pii> G[N];
int n, m, dis[N], a[N];

void dijks()
{
    priority_queue<pii,vector<pii>,greater<pii>> q; // dis, node
    rep(i,1,n)
        dis[i] = a[i], q.push({dis[i],i});
    while (!q.empty())
    {
        int u = q.top().S, d = q.top().F;
        q.pop();
        if (d > dis[u]) continue;
        for (auto v: G[u])
        {
            if (d+v.F < dis[v.S])
            {
                dis[v.S] = d+v.F;
                q.push({dis[v.S], v.S});
            }
        }
    }
}

signed main()
{
    haaachamachama
    cin >> n >> m;
    for (int i=0,u,v,w; i<m; i++)
    {
        cin >> u >> v >> w;
        G[u].push_back({w*2,v});
        G[v].push_back({w*2,u});
    }
    rep(i,1,n) cin >> a[i];
    dijks();
    rep(i,1,n) cout << dis[i] << ' ';
    cout << '\n';
}