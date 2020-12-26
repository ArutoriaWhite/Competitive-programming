#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 1e6+10;

vector<int> G[N];
int sum[N], sz[N], res[N];
int n;
void dfs (int u, int fa)
{
    sz[u] = 1;
    for (auto v: G[u])
    {
        if (v!=fa)
        {
            dfs(v, u);
            sz[u] += sz[v];
            sum[u] += sum[v]+sz[v];
        }
    }
}
void dfs2 (int u, int fa)
{
    for (auto v: G[u])
    {
        if (v==fa) continue;
        res[v] = res[u] + n - 2*sz[v];
        dfs2(v, u);
    }
}

signed main()
{
    SakuraMyWife
    cin >> n;
    for (int i=1,u,v; i<n; i++)
    {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1,0);
    res[1] = sum[1];
    dfs2(1,0);
    int mx=0;
    int mid=0;
    rep(i,1,n)
    {
        if (res[i] > mx)
        {
            mid = i;
            mx = res[i];
        }
    }
    cout << mid << '\n';
}