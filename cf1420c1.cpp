#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 3e5+10;

/*
j = 0, 1 // last choose is even/odd
dp[i][j] end with i, max choose, ch
dp[i] = max(dp[i-1][j], dp[i-1][!j]+a[i])
*/
int dp[N][2], a[N];

signed main()
{
    haaachamachama
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        int n, q;
        cin >> n >> q;
        rep(i,1,n) cin >> a[i];
        rep(i,1,n)
            rep(j,0,1)
                dp[i][j] = max(dp[i-1][j], dp[i-1][!j]+(j&1? a[i]:-a[i]));
        cout << dp[n][1] << '\n';
    }
}