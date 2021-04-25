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
const int N = 30;

int dp[N][N][N][N], a[N][N], m, n;

int del_row (int row, int l, int r)
{
    int ans = 0;
    rep(i,l,r)
        ans += a[row][i];
    return min(ans, r-l+1-ans);
}
int del_col (int col, int u, int d)
{
    int ans=0;
    rep(i,u,d)
        ans += a[i][col];
    return min(ans, d-u+1-ans);
}

signed main()
{
    ShinraTensei
    cin >> n >> m; // n, m meaning different from problem
    rep(i,1,n) 
        rep(j,1,m)
            cin >> a[i][j];
    
    for (int rl=2; rl<=n; rl++)
    {
        for (int cl=2; cl<=m; cl++)
        {
            for (int u=1,d=rl; d<=n; u++,d++)
            {
                for (int l=1,r=cl; r<=m; l++,r++)
                {
                    dp[u][d][l][r] = min( del_row(u,l,r) + dp[u+1][d][l][r],
                                     min( del_row(d,l,r) + dp[u][d-1][l][r],
                                     min( del_col(l,u,d) + dp[u][d][l+1][r],
                                          del_col(r,u,d) + dp[u][d][l][r-1])));
                }
            }
        }
    }
    cout << dp[1][n][1][m] << '\n';
}