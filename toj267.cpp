#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 5e4+10;

int h1[N], h2[N], mson[N], n;
vector<pii> G[N];

inline void upd (int u, int v, int h)
{
	if (h>=h1[u])
		mson[u] = v, h2[u]=h1[u], h1[u] = h;
	else if (h>h2[u])
		h2[u] = h;
}
void dfs1 (int u, int p)
{
	for (auto v: G[u])
	{
		if (v.S == p) continue;
		dfs1(v.S,u);
		upd(u,v.S,h1[v.S]+v.F);
	}
}
void dfs2 (int u, int p, int w)
{
	if (mson[p] == u) upd(u,p,h2[p]+w);
	else upd(u,p,h1[p]+w);
	for (auto v: G[u])
	{
		if (v.S == p) continue;
		dfs2(v.S,u,v.F);
	}
}

signed main()
{
	XinAi
	cin >> n;
	rep(i,2,n)
	{
		int v, w;
		cin >> v >> w;
		G[v].push_back({w,i});
		G[i].push_back({w,v});
	}
	
	dfs1(1,0);
	dfs2(1,0,0);
	
	int ans=0;
	rep(i,1,n) ans ^= h1[i];
	cout << ans << '\n';
}

