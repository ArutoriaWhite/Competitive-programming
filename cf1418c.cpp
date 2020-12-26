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
const int N = 2e5+10;

int a[N], dp[N][2], n, t;

signed main()
{
	SakuraMyWife
	cin >> t;
	while (t--)
	{
		cin >> n;
		rep(i,1,n) cin >> a[i];
		dp[1][1] = a[1];
		dp[1][0] = 2e18;
		dp[2][1] = a[1]+a[2];
		dp[2][0] = a[1];
		rep(i,3,n)
		{
			dp[i][0] = dp[i][1] = 2e18;
			dp[i][0] = min(dp[i-1][1], dp[i-2][1]);
			dp[i][1] = min(dp[i-1][0]+a[i], dp[i-2][0]+a[i]+a[i-1]);
		}
		cout << min(dp[n][1], dp[n][0]) << '\n';
	}
}