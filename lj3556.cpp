#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 5010, K = 1e6+10;

struct Q { int s, t, d, id; } qry[K];
int n, m, k;
vector<int> G[N];
int dis[N][2], ans[K];

void dijks (int rt)
{
    queue<pii> q; //dis, u
    dis[rt][0] = 0;
    q.push({0,rt});
    while (!q.empty())
    {
        int u = q.front().ss;
        int d = q.front().ff;
        q.pop();
        if (dis[u][d&1] < d) continue;
        for (auto v: G[u])
        {
            int nd = d+1;
            if (dis[v][nd&1] > nd)
            {
                dis[v][nd&1] = nd;
                q.push({nd,v});
            }
        }
    }
}

signed main()
{
    ShinraTensei
    cin >> n >> m >> k;
    rep(i,1,m)
    {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    rep(i,1,k)
    {
        cin >> qry[i].s >> qry[i].t >> qry[i].d;
        qry[i].id = i;
    }
    sort(qry+1, qry+1+k, [](Q i, Q j){return i.s < j.s;});
    rep(i,1,k)
    {
        if (i==1 || qry[i].s!=qry[i-1].s)
        {
            mem(dis,0x3f);
            dijks(qry[i].s);
        }
        int s = qry[i].s, t = qry[i].t, d = qry[i].d;
        if (s==t && d==0) ans[qry[i].id] = 1;
        else if (s==t && !G[s].size()) ans[qry[i].id] = 0;
        else ans[qry[i].id] = dis[t][d%2]<=d;
    }
    rep(i,1,k)
        cout << (ans[i]? "TAK":"NIE") << '\n';
}
/*
s == t
*/