#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 5e3+10;

struct Edge {int f, w, to;}; // f
vector<Edge> E;
vector<int> G[N];
int n, m, op, ed;

void add (int u, int v, int c, int w)
{
    G[u].pb(E.size());
    E.pb({c,w,v});
}

struct MCMF
{
    int dis[N];
    int spfa ()
    {
        queue<int> q;
        memset(dis,0x3f,sizeof(dis));
        q.push(op), dis[op] = 0;

        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (auto eid: G[u])
            {
                int f = E[eid].f;
                int w = E[eid].w;
                int v = E[eid].to;
                
                if (f <= 0) continue;
                if (w+dis[u] < dis[v])
                {
                    dis[v] = w+dis[u];
                    q.push(v);
                }
            }
        }
        rep(i,1,n) de(i), de(dis[i]), dd;
        return dis[ed] < 1e18;
    }
    int dfs (int u=op, int fn=9e18)
    {
        if (u == ed) return fn;

        for (auto eid: G[u])
        {
            int f = E[eid].f;
            int w = E[eid].w;
            int v = E[eid].to;

            if (f<=0)
                continue;
            if (dis[u]+w != dis[v])
                continue;

            de(u), de(dis[u]), de(w), de(v), de(dis[v]), dd;
            int tf = dfs(v,min(f,fn));
            if (tf)
            {
                E[eid].f -= tf;
                E[eid^1].f += tf;
                return tf;
            }
        }
        return 0;
    }
    pii flow ()
    {
        int flw = 0, cost = 0, tf;
        while (spfa()) // op can walk to ed on rest graph 
            while (tf = dfs())
                flw += tf, cost += tf*dis[ed];
        return {flw, cost};
    }
} mcmf;

signed main()
{
    cin >> n >> m >> op >> ed;
    while (m--)
    {
        int u, v, c, w; // from, to, capicity, cost
        cin >> u >> v >> c >> w;
        add(u,v,c,w);
        add(v,u,0,-w);
    }
    pii ans = mcmf.flow();
    cout << ans.ff << ' ' << ans.ss << '\n';
}