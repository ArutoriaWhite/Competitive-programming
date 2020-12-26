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
const int N = 5010;

vector<pii> ans;
int colo[N], vis[N], t, n;


void dfs (int u)
{
    vis[u] = 1;
    rep(v,1,n)
        if (v!=u&&colo[v]!=colo[u]&&!vis[v])
                ans.pb({v,u}), dfs(v);
}

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        ans.clear();

        cin >> n;
        rep(i,1,n) cin >> colo[i];
        dfs(1);
        int con=1;
        rep(i,1,n) if (!vis[i]) con=0;
        if (con)
        {
            cout << "YES\n";
            for (auto e: ans)
                cout << e.ff << ' ' << e.ss << '\n';
        }
        else
            cout << "NO\n";
    }
}