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
const int N = 1e5+10;

vector<int> G[N];
int dp[N][2], n;

void dfs (int u)
{
	for (auto v: G[u])
	{
		dfs(v);
		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][0], dp[v][1]);
	}
	dp[u][1]++;
}

signed main()
{
	ShinraTensei
	cin >> n;
	rep(i,1,n-1)
	{
		int p; cin >> p;
		G[p].pb(i);
	}
	dfs(0);
	cout << min(dp[0][0], dp[0][1]) << '\n';
}
