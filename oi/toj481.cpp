#include <bits/stdc++.h>
#define int long long
#define EXI(x,s) (s.find(x)!=s.end())
using namespace std;
const int N = 1e5+10;

int n, q;
set<int> adj[N];
int p[N], dp[N], ask[N];

inline void link (int x)
{
	for (int u=x; u!=0; u=p[u])
	{
		if (EXI(u,adj[p[u]])) break;
		adj[p[u]].insert(u);
	}
}
void dfs(int u)
{
	if (ask[u]) return;
	int k=0, f=0;
	for (auto v: adj[u])
		dfs(v), k+= dp[v], f=1;
	if(f) dp[u] = min( dp[u], k);
}
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int i=1; i<n; i++)
		cin >> p[i];
	for (int i=0; i<n; i++)
		cin >> dp[i];
	for (int i=0,x; i<q; i++)
		cin >> x, link(x), ask[x]=1;
	dfs(0);
	cout << dp[0] << '\n';
}
