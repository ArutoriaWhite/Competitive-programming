#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
dp[i][j]: end with i, diff is j, all posibilities
dp[i][j] = sum{ dp[k][j]+1 | a[k]-a[i] == j}

rep (i,1,n)
    rep(j,1,i-1)
        dp[i][a[j]-a[i]+sh] = dp[i][a[j]-a[i]+sh] + dp[j][a[j]-a[i]+sh] + 1
*/

const int N = 1e3+10, A = 8e4+10, sh = 4e4, M = 998244353;

int n, a[N], dp[N][A];

signed main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];

    for (int i=1; i<=n; i++)
        for (int j=1; j<i; j++)
            dp[i][a[i]-a[j]+sh] = (dp[i][a[i]-a[j]+sh] + dp[j][a[i]-a[j]+sh] + 1)%M;

    int ans = n;
    for (int i=1; i<=n; i++)
        for (int j=0; j<A; j++)
            ans = (ans+dp[i][j])%M;
    cout << ans << endl;
}