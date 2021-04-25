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
const int N = 5e4+10;

int n, h1[N], h2[N], sum, mson[N], ans=1e9;
vector<int> G[N], To, W;

void upd (int u, int h, int v)
{
	if (h >= h1[u])
		h2[u] = h1[u], h1[u] = h, mson[u] = v;
	else if (h > h2[u])
		h2[u] = h;
}

void dfs (int u, int p)
{
	for (auto eid: G[u])
	{
		int v = To[eid];
		int w = W[eid];
		if (v == p) continue;
		dfs(v,u);
		upd(u,h1[v]+w,v);
	}
}
void dfs2 (int u, int p, int wp)
{
	if (u == mson[p])
		upd(u,h2[p]+wp,p);
	else
		upd(u,h1[p]+wp,p);
	for (auto eid: G[u])
	{
		if (To[eid] == p) continue;
		dfs2(To[eid], u, W[eid]);
	}
	ans = min(ans, sum*2-h1[u]-h2[u]);
}

signed main()
{
	ShinraTensei
	cin >> n;
	rep(i,2,n)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].pb(To.size()); To.pb(v), W.pb(w);
		G[v].pb(To.size()); To.pb(u), W.pb(w);
		sum += w;
	}

	dfs(0,-1);
	dfs2(0,-1,0);
	cout << ans << '\n';
}

