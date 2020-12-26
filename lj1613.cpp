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
const int N = 60;

int dp[N][N][N], dis[N][N];
int n, m;

signed main()
{
    SakuraMyWife
    cin >> n >> m;
    for (int i=0,u,v; i<m; i++)
    {
        cin >> u >> v;
        dp[u][v][0] = 1;
    }
    rep(k,1,20)
        rep(i,1,n)
            rep(j,1,n)
                rep(s,1,n)
                    dp[i][j][k] |= dp[i][s][k-1]&&dp[s][j][k-1];
    memset(dis, 0x3f, sizeof(dis));
    rep(i,1,n)
    {
        rep(j,1,n)
        {
            int f=0;
            rep(k,0,20) f |= dp[i][j][k];
            if(f) dis[i][j] = 1;
        }
    }
    rep(i,1,n)
        rep(j,1,n)
            rep(k,1,n)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    cout << dis[1][n] << '\n';
}