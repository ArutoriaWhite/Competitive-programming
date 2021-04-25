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
	dp[u][1] = 1;
	for (auto v: G[u])
	{
		dfs(v);
		dp[u][0] += max(dp[v][1],dp[v][0]);
		dp[u][1] += dp[v][0];
	}
}

signed main()
{
	cin >> n;
	for (int i=1,p; i<n; i++)
	{
		cin >> p;
		G[p].pb(i);
	}
	dfs(0);
	cout << max(dp[0][0], dp[0][1]) << '\n';
}
