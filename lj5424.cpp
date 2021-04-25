#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define endl '\n'
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 410;

int mx[N][N], sum[N][N], dp[N][N];
int a[N];
int n, k;

void build()
{
	for (int l=1; l<=n; l++)
	{
		for (int r=l; r<=n; r++)
		{
			for (int i=l; i<=r; i++)
			{
				mx[l][r] = max(mx[l][r], a[i]);
				sum[l][r] = sum[l][r] + a[i];	
			}	
		}
	}
}
int cost (int l, int r)
{
	return (r-l+1)*mx[l][r] - sum[l][r];
}

signed main()
{
	cin >> n >> k;
	rep(i,1,n) cin >> a[i];
	build();
	for (int i=n; i>0; i--)
	{
		for (int j=0; j<=k; j++)
		{
			dp[i][j] = 9e18;
			if (j > 0)
				for (int x=i; x<=n; x++)
					dp[i][j] = min(dp[i][j], dp[x+1][j-1]+cost(i,x));
			else 
				dp[i][j] = cost(i,n);
		}
	}
	cout << dp[1][k] << endl;
}
