#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
const int N = 5010, M = 1e9+7;

int dp[N][N], c[N][N], fac[N];

signed main()
{
    XinAi
    char ch;
    int n, k, res = 0;
    cin >> ch >> n >> k;
    if (ch == 'U')
    {
        for (int i=0,x; i<k; i++) cin >> x, n -= x;
        rep(i,0,n) dp[i][i] = 1;
        rep(i,1,n) rep(j,i+1,n) dp[i][j] = ((dp[i][j] + dp[i-1][j-1])%M + dp[i][j-i])%M;
        rep(i,1,n) res = (res + dp[i][n])%M;
    }
    else
    {
        rep(i,k,n) dp[i][i] = 1;
        rep(i,1,n) rep(j,i+1,n) dp[i][j] = (dp[i][j-1]*1LL*i%M + dp[i-1][j-1])%M;
        rep(i,1,n) res = (res + dp[i][n])%M;
    } 
    cout << res << '\n';
}
 