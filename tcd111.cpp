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
int h1[N], h2[N], ans, n;

void upd (int u, int h)
{
	if (h >= h1[u])
		h2[u] = h1[u], h1[u] = h;
	else if (h >= h2[u])
		h2[u] = h;
}
void dfs (int u, int p)
{
	for (auto v: G[u])
	{
		if (v == p) continue;
		dfs(v,u);
		upd(u,h1[v]+1);
	}
	ans = max(ans, h1[u]+h2[u]);
}

signed main()
{
	ShinraTensei
	cin >> n;
	rep(i,2,n)
	{
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(0,0);
	cout << ans << '\n';
}
