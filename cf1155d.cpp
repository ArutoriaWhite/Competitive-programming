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
using namespace std;
typedef pair<int,int> pii;
const int N = 3e5+10;

int a[N], dp[N][3], n, x;

signed main()
{
    cin >> n >> x;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n)
    {
        dp[i][0] = max(dp[i-1][0]+a[i], a[i]);
        dp[i][1] = max(max(dp[i-1][0],dp[i-1][1])+a[i]*x, a[i]*x);
        dp[i][2] = max(max(dp[i-1][1],dp[i-1][2])+a[i], a[i]);
    }
    int ans=0;
    rep(i,1,n)
        ans=max(ans,max(dp[i][0], max(dp[i][1], dp[i][2])));
    cout << ans << '\n';
}