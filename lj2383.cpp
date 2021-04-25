#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 22, A = 2e4+10;

int t, n, a[N], calced[1<<N], dp[1<<N], tot = 0;

int dfs (int vis=0, int sum=0)
{
	if (!calced[vis])
	{
		calced[vis] = 1;
		rep(i,1,n)
		{
			if (vis&(1<<i)) continue;
			if (sum + a[i] < tot)
				dp[vis] |= dfs(vis|(1<<i),sum+a[i]);
			if (sum + a[i] ==tot)
				dp[vis] |= dfs(vis|(1<<i),0);
		}
	}
	return dp[vis];
}

signed main()
{
	cin >> t;
	while (t--)
	{
		tot = 0;
		cin >> n;
		rep(i,1,n) cin >> a[i], tot+=a[i];
		if (tot%4)
		{
			cout << "no\n";
			continue;
		}
		tot /= 4;
		memset(calced,0,sizeof(calced));
		memset(dp,0,sizeof(dp));
		calced[((1<<n)-1)<<1] = dp[((1<<n)-1)<<1] = 1;
		cout << (dfs()? "yes":"no") << '\n';
	}
}
