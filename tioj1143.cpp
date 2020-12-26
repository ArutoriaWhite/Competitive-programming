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

int dp[N][N], a[N][N];
int rx, ry, tx, ty;

int f (int x, int y)
{
	if (x<0 || y<0 || x>=100 || y>=100) return 0x3f3f3f3f;
	if (dp[x][y] == -1)
	{
		de(x), de(y), dd
		if (x==tx && y==ty) dp[x][y] = 0;
		else if (a[x][y]) dp[x][y] = 0x3f3f3f3f;
		else
		{
			dp[x][y] = f(x+3,y+1), dp[x][y] = min(dp[x][y], f(x+3,y-1));
			dp[x][y] = min(dp[x][y], f(x-3,y+1)), dp[x][y] = min(dp[x][y], f(x-3,y-1));
			dp[x][y] = min(dp[x][y], f(x+1,y+3)), dp[x][y] = min(dp[x][y], f(x+1,y-3));
			dp[x][y] = min(dp[x][y], f(x-1,y+3)), dp[x][y] = min(dp[x][y], f(x-1,y-3));
			dp[x][y] += 1;
		}
	}
	return dp[x][y];
}

signed main()
{
	memset(dp, -1, sizeof(dp));
	cout << "hellow\n";
	int n;
	cin >> n;
	for (int i=0,x,y; i<n; i++)
	{
		cin >> x >> y, de(i), de(x), de(y), dd
		a[x][y] = 1;

	}
	cin >> rx >> ry >> tx >> ty;
	cout << f(rx, ry) << '\n';
}