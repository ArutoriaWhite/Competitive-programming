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

int n, m, a, b, t, dis[N];
struct E {int v, c, p;};
vector<E> G[N];

int dijks (int s, int e)
{
    memset(dis, 0x3f, sizeof(dis));
    queue<pii> pq;
    pq.push({0,s}), dis[s]=0;
    while (!pq.empty())
    {
        int d=pq.front().F, u=pq.front().S;
        pq.pop();
        if (d > dis[u]) continue;
        for (auto e: G[u])
        {
            int v=e.v, nd=d+e.c;
            if (nd < dis[v])
                dis[v]=nd, pq.push({nd,v});
        }
    }
    return dis[e];
}

signed main()
{
    XinAi
    cin >> n >> m >> a >> b >> t;
    for (int i=1; i<=m; i++)
    {
        int u, v, c1, p1, c2, p2;
        cin >> u >> v >> c1 >> p1 >> c2 >> p2;
        G[u].push_back({v, c1, p1});
        G[v].push_back({u, c2, p2});
    }
    int res = dijks(a,b)+dijks(b,a);
    rep(i,1,n) for(auto &e:G[i]) e.c+=e.p*(t-1);
    res = min(res, dijks(a,b)+dijks(b,a));
    cout << res << '\n';
}
