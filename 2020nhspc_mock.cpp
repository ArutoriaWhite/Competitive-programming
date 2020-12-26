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
const int N = 2010, M = N*N;

int n, m, w1[N], w2[N], adj1[N][N], adj2[N][N];
vector<pii> E[N][N], G[N][N];
int h1[N][N], h2[N][N], vis[N][N], R;

int build_G()
{
    rep(i,1,m)
        rep(j,1,m)
            if (adj2[i][j])
                E[w2[i]][w2[j]].pb({i,j});
    int cnt=0;
    rep(i,1,n)
    {
        rep(j,i+1,n)
        {
            if (adj1[i][j])
            {
                for (auto e: E[w1[i]][w1[j]])
                {
                    G[i][e.ff].pb({j,e.ss});
                    G[j][e.ss].pb({i,e.ff});
                    cnt++;
                }
                if (cnt>=n*m*2) return 1;
            }
        }
    }
    return 0;
}
void dfs (int s, int t)
{
    vis[s][t] = 1;
    for (auto to: G[s][t])
    {
        if (vis[to.ff][to.ss]) continue;
        dfs(to.ff, to.ss);
        if (h1[s][t] <= h1[to.ff][to.ss])
        {
            h2[s][t] = h1[s][t];
            h1[s][t] = h1[to.ff][to.ss]+1;
        }
        else if (h2[s][t] <= h1[to.ff][to.ss])
            h2[s][t] = h1[to.ff][to.ss]+1;
        R = max(R, h1[s][t]+h2[s][t]);
    }
}
int rad()
{
    mem(vis,0);
    rep(i,1,n)
        rep(j,1,m)
            if (w1[i]==w2[j])
                if (!vis[i][j])
                    dfs(i,j);
    return R;
}
void dfs2 (int s, int t, int &vc, int &ec)
{
    vis[s][t] = 1;
    vc++;
    for (auto to: G[s][t])
    {
        if (vis[to.ff][to.ss]) continue;
        dfs2(to.ff, to.ss, vc, ec);
        ec++;
    }    
}
int have_cycle()
{
    mem(vis,0);
    rep(i,1,n)
        rep(j,1,m)
            if (w1[i]==w2[j])
                if (!vis[i][j])
                {
                    int vcnt=0, ecnt=0;
                    dfs2(i,j,vcnt,ecnt);
                    if (vcnt <= ecnt) return 1;
                }
    return 0;
}

signed main()
{
    ShinraTensei
    cin >> n;
    rep(i,1,n) cin >> w1[i];
    char c;
    rep(i,1,n)
        rep(j,1,n)
            cin >> c, adj1[i][j] = c-'0';
    cin >> m;
    rep(i,1,m) cin >> w2[i];
    rep(i,1,m)
        rep(j,1,m)
            cin >> c, adj2[i][j] = c-'0';
    int cycle = build_G() || have_cycle();
    if (cycle) cout << "INF\n";
    else cout << rad()+1 << '\n';
}