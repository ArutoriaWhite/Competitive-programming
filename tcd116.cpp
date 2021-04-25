#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1010, M = 90;

vector<int> G[N];
int c[N][M], dp[N][10], rt, num[200];
int n, m;

int dfs (int u, int x, int kth) // node u, color x, kth color
{
	if (dp[u][x] < 0)
	{
		int ans=0;
		if (c[u][kth]>0 && c[u][kth]!=x) ans = 1e9;
		for (auto v: G[u])
		{
			int res=1e9;
			rep(nc,1,4)
			{
				res = min(res, dfs(v,nc,kth) + (nc!=x));
			}
			ans += res;
		}
		dp[u][x] = ans;
	}
	return dp[u][x];
}

signed main()
{
	ShinraTensei
	num['@'] = 0;
	num['A'] = 1;
	num['U'] = 2;
	num['G'] = 3;
	num['C'] = 4;
	cin >> n >> m;
	rep(i,1,n)
	{
		int u, v;
		cin >> u >> v;
		if (u==v) rt = u;
		else G[v].pb(u);
		char ch;
		rep(j,1,m)
		{
			cin >> ch;
			c[u][j] = num[ch];
		}
	}

	int ans=0;
	rep(i,1,m)
	{
		int res = 1e9;
		mem(dp,-1);
		rep(j,1,4)
			res = min(res, dfs(rt,j,i));
		ans += res;
	}
	cout << ans << '\n';
}
