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

vector<int> G[N], C[N], chain;
int w[N], ind[N], dp[N], from[N], n, m, ans, vis[N];

void dfs (int u)
{
	if (dp[u]) return;

	for (auto v: G[u])
		dfs(v);
	for (auto v: G[u])
		dp[u] = max(dp[u], dp[v]);
	for (auto v: G[u])
		if (dp[v] == dp[u])
			C[u].pb(v);

	dp[u] += w[u];
	if (dp[u] > dp[ans]) ans = u;
}

void dfs2 (int u)
{
	if (vis[u]) return;
	vis[u] = 1;
	chain.pb(u);
	for (auto v: C[u])
		dfs2(v);
}

signed main()
{
	ShinraTensei
	cin >> n >> m;
	rep(i,1,n) cin >> w[i];
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		G[v].pb(u);
		ind[u]++;
	}
	
	rep(i,1,n)
		if (ind[i] == 0)
			dfs(i);

	cout << dp[ans] << '\n';

	rep(i,1,n)
		if (dp[ans] == dp[i])
			dfs2(i);

	sort(chain.begin(), chain.end());
	for (auto x: chain)
		cout << x << ' ';
	cout << '\n';
}

