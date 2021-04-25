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
const int N = 1e5+10;

vector<int> G[N];
int W[N], n;
int dp[N], sz[N];

void dfs (int u)
{
    sz[u] = 1;
    for (auto v: G[u])
    {
        int w = W[v];
        dfs(v);
        dp[u] += dp[v] + (sz[v]*(n-sz[v]));
        sz[u] += sz[v];
    }
}

signed main()
{
    cin >> n;
    rep(i,2,n)
    {
        int p;
        cin >> p;
        G[p].pb(i);
    }
    rep(i,2,n) cin >> W[i];
    dfs(1);
    cout << dp[1]*2 << '\n';
}
