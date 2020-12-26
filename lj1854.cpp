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
const int N = 110;

int a[N][N], dp[N][N], ans[N], ori[N][N];
int n, m;

signed main()
{
    cin >> n >> m;
    rep(i,1,n)
    {
        rep(j,1,m)
        {
            cin >> a[i][j];
        }
    }
    mem(dp,0xc0);
    rep(i,0,m) dp[0][i] = 0;
    rep(i,1,n)
    {
        rep(j,i,m)
        {
            rep(k,i,j)
            {
                if (dp[i-1][k-1]+a[i][k]>dp[i][j])
                {
                    ori[i][j] = k-1;
                    dp[i][j] = dp[i-1][k-1]+a[i][k];
                }
            }
        }
    }
    cout << dp[n][m] << '\n';
    for (int i=n,j=m; i>0; i--)
    {
        j = ori[i][j];
        ans[i] = j+1;
    }
    rep(i,1,n) cout << ans[i] << ' ';
    cout << '\n';
}