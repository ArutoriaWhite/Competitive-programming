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

const int N = 2e5+10;

vector<int> G[N];
int dp[N], sz[N], szs[N], n, ans;

void dfs (int u=1, int p=1)
{
	sz[u] = 1;
	for (auto v: G[u])
	{
		if (v == p) continue;
		dfs(v,u);
		sz[u] += sz[v];
		szs[u] += szs[v];
	}
	szs[u] += sz[u];

	dp[u] = n;
	for (auto v: G[u])
	{
		if (v == p) continue;
		dp[u] = max(dp[u], dp[v]+n-sz[v]+szs[u]-szs[v]-sz[u]);
	}
}

signed main()
{
	pui
	cin >> n;
	rep(i,2,n)
	{
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}	
	dfs();
	cout << dp[1] << endl;
}
