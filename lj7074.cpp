#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
const int N = 1e3+10;

int n, m;
int dp[N][N][5], vis[N][N][5], a[N][N]; // 0:up, 1:down, 2:right

int f (int i, int j, int k)
{
    if (i<1 || i>n || j<1 || j>m) return -1e18;
    if (i==n && j==m) return a[i][j];
    if (!vis[i][j][k])
    {
        vis[i][j][k] = 1;
        dp[i][j][k] = max(f(i,j+1,0),f(i,j+1,1));
        if (k==0)
            dp[i][j][k] = max(dp[i][j][k],f(i-1,j,0));
        if (k==1)
            dp[i][j][k] = max(dp[i][j][k],f(i+1,j,1));
        dp[i][j][k] += a[i][j];
    }
    return dp[i][j][k];
}

signed main()
{
    SakuraMyWife
    cin >> n >> m; 
    rep(i,1,n)
        rep(j,1,m)
            cin >> a[i][j];
    cout << max(f(1,1,0),f(1,1,1)) << '\n';
}


