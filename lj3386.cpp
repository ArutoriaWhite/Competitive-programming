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
using namespace std;
typedef pair<int,int> pii;
const int N = 510;

vector<int> G[N]; // to ri
int le[N], ri[N], vis[N], n, m, e;

int fright (int u)
{
    for (auto v: G[u])
    {
        if (vis[v]) continue;
        vis[v] = 1;
        if (le[v] == 0 || fright(le[v]))
        {
            le[v] = u;
            ri[u] = v;
            return 1;
        }
    }
    return 0;
}

int xyl()
{
    int res=0;
    rep(i,1,n)
    {
        memset(vis, 0, sizeof(vis));
        if (fright(i))
            res++;
    }
    return res;
}

signed main()
{
    SakuraMyWife
    cin >> n >> m >> e;
    for (int i=0,u,v; i<e; i++)
    {
        cin >> u >> v;
        G[u].pb(v);
    }
    cout << xyl() << '\n';
}