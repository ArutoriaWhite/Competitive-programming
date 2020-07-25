#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5010, M = 80112002;

vector<int> adj[N];
int indeg[N], dp[N], n, m, res;

int f (int u)
{
    if (dp[u]==-1)
    {
        if (adj[u].size()==0) dp[u] = 1;
        else
        {
            dp[u] = 0;
            for (auto v: adj[u])
                dp[u] = (dp[u]+f(v))%M;
        }
    }
    return dp[u];
}

int main()
{
    Eriri
    cin >> n >> m;
    for (int i=0,u,v; i<m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    memset(dp,-1,sizeof(dp));
    for (int i=1; i<=n; i++)
        if (!indeg[i])
            res = (f(i)+res)%M;
    cout << res << '\n';
}