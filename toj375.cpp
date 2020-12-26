#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e3+10, K = 5e3+10, INF=1e18;

/*
dp[i][j]: min cost i people, j~n sticks
dp[i][j] = min(dp[i][j+1], dp[i-1][j+2] + cost(i,i+1))
dp[0][j] = 0;
if (k-j+1 < i*3) dp[i][j]=INF;
*/
int n, k, a[K], dp[N][K];

signed main()
{
	XinAi
	while (cin >> n >> k)
	{
		n++;
		rep(i,1,k) cin >> a[i];
		rep(i,0,n+5)
			rep(j,0,k+5)
				dp[i][j]=INF;
		rep(i,0,k+5) dp[0][i]=0;
		for (int i=1; i<=n; i++)
		{
			for (int j=k-1; j>0; j--)
			{
				if (k-j+1 < i*3) continue;
				dp[i][j] = min(dp[i][j+1], dp[i-1][j+2] + (a[j]-a[j+1])*(a[j]-a[j+1]));
			}
		}
		cout << dp[n][1] << '\n';
	}
}
/*
2 10
1 2 3 4 4 5 6 7 8 9
1 6
2 3 6 8 10
*/

