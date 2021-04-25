#include <bits/stdc++.h>
#define int long long 
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define endl '\n'
#define ff first
#define ss second
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 2010;

long double dp[N][N], p;
int n, t;

signed main()
{
	cin >> n >> p >> t;

	dp[0][0] = 1;
	
	rep(i,1,t)
		rep(j,0,n)
		{
			if (j==0)
				dp[i][j] = dp[i-1][j]*(1-p);
			else if (j==n && i>n)
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1]*p;
			else
				dp[i][j] = dp[i-1][j-1]*p + dp[i-1][j]*(1-p);
			//de(i), de(j), de(dp[i][j]), dd;
		}

	long double res = 0;
	rep(i,1,n)
		res += dp[t][i]*i;
	
	cout << fixed << setprecision(6) << res << '\n';
}
