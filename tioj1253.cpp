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
const int N = 1010;

int n, k, hus[N], vis[N], u;
vector<int> G[N];

int find_wife (int u)
{
	for (auto v: G[u])
	{
		if (vis[v]) continue;
		vis[v] = 1;
		if (!hus[v] || find_wife(hus[v]))
		{
			hus[v] = u;
			return 1;
		}
	}
	return 0;
}

int konig()
{
	int ans=0;
	mem(hus,0);
	rep(i,1,n)
	{
		mem(vis,0);
		if (find_wife(i)) ans++;
	}
	return ans;
}

signed main()
{
	while (cin >> n >> k, n||k)
	{
		rep(i,1,n) G[i].clear();
		while (k--)
		{
			int u, v;
			cin >> u >> v;
			G[u].pb(v);
		}
		cout << "Case #" << ++u << ":" << konig() << "\n";
	}
}
