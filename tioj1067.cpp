#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1010, M = 10010;

int dp[2][M], a[N], n, m;

signed main()
{
	ShinraTensei
	while (cin >> n >> m, n||m)
	{
		mem(dp,-1);
		rep(i,1,n) cin >> a[i];
		int ans = 0;
		dp[0][0] = 0;
		rep(i,0,n)
		{
			for (int j=m-1; j>=0; j--)
			{
				if (dp[i&1][j] < 0) continue;
				dp[(i+1)&1][j] = max(dp[(i+1)&1][j], dp[i&1][j]);
				dp[(i+1)&1][(j*10+a[i+1])%m] = max(dp[(i+1)&1][(j*10+a[i+1])%m], dp[i&1][j]+1);
				if (__gcd(j,m) == 1)
				{
					ans = max(ans, dp[i&1][j]);
				}
			}
		}
		cout << ans << '\n';
	}
}
