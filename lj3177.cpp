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
const int N = 2010;

//dp[i][j]: i 點包含 j 個黑點可以貢獻的最大價值
//dp[i][j] = max(dp[i][j], dp[i][j-t] + dp[v0][t] + val(i,j))

vector<pii> G[N];
int n, m;
int dp[N][N], sz[N];

int val (int i, int j, int w)
{
    return w*(j*(m-j) + (sz[i]-j)*(n-m-sz[i]+j));
}

void dfs (int i, int p)
{
    sz[i] = 1;
    for (auto e: G[i])
    {
        int v=e.ss, ww=e.ff;
        if (v==p) continue;

        dfs(v,i);

        for (int a=min(m,sz[i]); a>=0; a--)
        {
            for (int b=min(m,sz[v]); b>=0; b--)
            {
                dp[i][a+b] = max(dp[i][a+b], dp[i][a]+dp[v][b]+val(v,b,ww));
            }
        }
        sz[i] += sz[v];
    }
}

signed main()
{
    ShinraTensei
    cin >> n >> m;
    for (int i=1; i<n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb({w,v});
        G[v].pb({w,u});
    }
    dfs(1,0);
    cout << max(dp[1][m],dp[1][n-m]) << '\n';
}