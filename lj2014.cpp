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
const int N = 310;

// dp[i][j] 在子樹 i 包含 i 中，選 j 門課的最大價值
// dp[i][s][j] = dp[i][s-1][j - k] + dp[v][s_all][k], enum 
// j-k = a, k = b
// dp[i][a+b] = dp[i][a] + dp[v][b]

vector<int> G[N];
int n, m;
int dp[N][N<<1], a[N], sz[N];

void dfs (int u)
{
    sz[u] = 1;
    for (auto v: G[u])
    {
        dfs(v);
        sz[u] += sz[v];
        for (int a=sz[u]; a>=0; a--)
        {
            for (int b=sz[v]; b>=0; b--)
            {
                dp[u][a+b] = max(dp[u][a+b], dp[u][a]+dp[v][b]);
            }
        }
    }
    for (int j=sz[u]-1; j>=0; j--)
    {
        dp[u][j+1] = dp[u][j]+a[u];
    }
}

signed main()
{
    cin >> n >> m;

    int p;
    rep(i,1,n)
    {
        cin >> p >> a[i];
        G[p].pb(i);
    }
    dfs(0);
    cout << dp[0][m+1] << '\n';
}