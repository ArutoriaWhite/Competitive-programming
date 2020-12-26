#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 110;

int a[N], dp[N][N];

signed main()
{
    XinAi
    int n;
    while (cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        rep(i, 1, n) cin >> dp[i][i];
        for (int k=1; k<n; k++)
        {
            for (int l=1; l+k<=n; l++)
            {
                int r = l+k;
                for (int m=l; m<r; m++)
                {
                    if ((r-l)&1) dp[l][r] = max(dp[l][r], dp[l][m] + dp[m+1][r]);
                    else dp[l][r] = max(dp[l][r], dp[l][m] * dp[m+1][r]);
                }
            }
        }   
        cout << dp[1][n] << '\n';
    }
}