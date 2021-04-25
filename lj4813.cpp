#include <iostream>
#define pui ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int N = 2010;

int n, m;
int dp[N][N], a[N][N];

signed main()
{
	pui
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			char c; cin >> c;
			a[i][j] = c=='#';
		}
	}
	// dp[i][j] = min(dp[i][j+2], dp[i-1][j+1]) 
	for (int i=1; i<=n; i++)
	{
		for (int j=n; j>0; j--)
		{
			if (j >= n-1)
				dp[i][j] = a[i][j];
			else
			{
				if (!a[i][j]) dp[i][j] = 0;
				else if (!a[i][j+1]) dp[i][j] = 1;
				else dp[i][j] = min(dp[i][j+2], dp[i-1][j+1])+1;
			}
		}
	}
	int ans = 0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			ans += dp[i][j];
	cout << ans << '\n';
}