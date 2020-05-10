#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 2010;

vector<int> adj[N]; 

int n, k;
int sz[N], dp[N][N], w[N][N];

void dfs (int u, int p)
{
    sz[u] = 1;
    for (auto v: adj[u])
        if (v!=p)
            dfs(v,u), sz[u] += sz[v];
}
inline int val (int u, int v, int x)
{
    int res = (x*(k-x) + (sz[v] - x)*(n-k-sz[v]+x))*w[u][v];
    return res;
}
int f (int u, int h, int p)
{
    if (dp[u][h] == -1)
    {
        dp[u][h] = 0;
        for (auto v: adj[u])
            if (v != p)
                for (int j=0; j<=h; j++)
                    dp[u][h] = max(dp[u][h], f(u,j,p) + f(v,h-j,u) + val(u,v,j));
        de(u), de(h), de(p), de(dp[u][h]), dend;
    }

    return dp[u][h];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    for (int i=0,u,v; i<n-1; i++)
    {
        cin >> u >> v >> w[u][v];
        adj[u].push_back(v);
        adj[v].push_back(u);
        w[v][u] = w[u][v];
    }
    dfs(1,0);
    cout << f(1,k,0) << '\n';
}
/*
dp[u][h]
the u-rooted tree, colored h black --> max contribution

dp[u][h]
    for (v :adj[u])
        rep (j,0,h)
            dp[u][h] = max(dp[u][h], dp[u][h-j] + dp[v][j] + val)
ub = k-h
uw = n-size[u]-k+h
db = j
dw = size[v]-dw
val = ub*db*w + uw*dw*w
*/