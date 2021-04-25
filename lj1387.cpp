#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 110;

int a[N][N], sum[N][N], n, m;

signed main()
{
	pui
	cin >> n >> m;
	rep(i,1,n)
		rep(j,1,m)
			cin >> a[i][j];
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j];
		}
	}

	int ans = 0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			for (int p=i,q=j; p<=n&&q<=m; p++,q++)
			{
				if (sum[p][q] + sum[i-1][j-1] - sum[p][j-1] - sum[i-1][q] == (p-i+1)*(q-j+1))
				{
					ans = max(ans, (p-i+1));
				}
			}
		}
	}
	cout << ans << '\n';
}
