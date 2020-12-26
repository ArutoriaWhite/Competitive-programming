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

int vis[N], n, m, k;

void dfs (int i)
{
    if (vis[i]) return;
    vis[i] = 1;
    dfs((i+k)%n);
}

signed main()
{
    cin >> n >> m >> k;
    for (int i=0,p; i<m; i++)
    {
        cin >> p;
        dfs(p);
    }
    int res=0;
    for (int i=0; i<n; i++)
    {
        res += !vis[i];
    }
    cout << res << '\n';
}
