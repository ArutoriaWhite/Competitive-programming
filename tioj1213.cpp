#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define SZ(x) ((int)x.size())
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

vector<pii> G[N];
int h1[N], h2[N], n;

void upd (int u, int h)
{
	if (h>=h1[u]) h2[u]=h1[u],h1[u]=h;
	else if (h>h2[u]) h2[u]=h;
}
void dfs (int u, int p)
{
	for (auto v: G[u])
	{
		if (v.S == p) continue;
		dfs(v.S,u);
		upd(u,h1[v.S]+v.F);
	}
}

signed main()
{
	XinAi
	while (cin>>n, n)
	{
		memset(h1,0,sizeof(h1));
		memset(h2,0,sizeof(h2));
		rep(i,1,n) G[i].clear();
		for (int i=1,u,v,w; i<n; i++)
		{
			cin >> u >> v >> w;
			G[u].push_back({w,v});
			G[v].push_back({w,u});
		}
		dfs(1,0);
		int ans=0;
		rep(i,1,n) ans = max(ans, h1[i]+h2[i]);
		cout << ans << '\n';
	}
}
