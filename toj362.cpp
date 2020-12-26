#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define shaaark ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int N = 13;

int a[20][20], dp[20][20][20][20]; // [pile][card]
signed main()
{
    shaaark
    while (cin >> a[1][1])
    {
        rep(i,2,N) cin >> a[1][i];
        rep(i,2,4) rep(j,1,N) cin >> a[i][j];
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0] = 1;
        rep(i,0,N)
        {
            rep(j,0,N)
            {
                rep(k,0,N)
                {
                    rep(l,0,N)
                    {
                        if (i==0&&j==0&&k==0&&l==0) continue;
                        if (i>0&&j>0 && a[1][i] == a[2][j]) dp[i][j][k][l] |= dp[i-1][j-1][k][l];
                        if (i>0&&k>0 && a[1][i] == a[3][k]) dp[i][j][k][l] |= dp[i-1][j][k-1][l];
                        if (i>0&&l>0 && a[1][i] == a[4][l]) dp[i][j][k][l] |= dp[i-1][j][k][l-1];
                        if (j>0&&k>0 && a[2][j] == a[3][k]) dp[i][j][k][l] |= dp[i][j-1][k-1][l];
                        if (j>0&&l>0 && a[2][j] == a[4][l]) dp[i][j][k][l] |= dp[i][j-1][k][l-1];
                        if (k>0&&l>0 && a[3][k] == a[4][l]) dp[i][j][k][l] |= dp[i][j][k-1][l-1];
                    }
                }
            }
        }
        cout << (dp[N][N][N][N]? "YES":"NO") << '\n';
    }
}