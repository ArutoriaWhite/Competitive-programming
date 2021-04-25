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

const int N = 50;

vector<pii> to; // {id,to};
vector<int> G[N], path;
int n, vis[N], rt, ind[N];

int cmp (int i, int j)
{
	return to[i].ff < to[j].ff;
}
void add (int u, int v)
{
	int z; cin >> z;
	G[u].pb(to.size());
	to.pb({z,v});
	G[v].pb(to.size());
	to.pb({z,u});
}
void dfs (int u = rt)
{
	for (auto eid: G[u])
	{
		int v = to[eid].ss;
		int id = to[eid].ff;
		if (vis[id]) continue;
		vis[id] = 1;
		dfs(v);
		path.pb(id);
	}	
}

signed main()
{
	int u, v;
	while (cin >> u >> v, u&&v)
	{
		to.clear(), path.clear();
		memset(vis,0,sizeof(vis));
		memset(ind,0,sizeof(ind));
		for (int i=0; i<N; i++) G[i].clear();

		add(u,v), rt = min(u,v);
		while (cin >> u >> v, u&&v)
			add(u,v);
		int flag = 0;
		for (int i=0; i<N; i++)
			if (ind[i]&1)
				flag = 1;
		if (flag)
			cout << "Round trip does not exist.\n";
		else
		{
			for (int i=0; i<N; i++) sort(G[i].begin(), G[i].end(), cmp);
			dfs();
			for (int i=1; i<path.size(); i++)
				cout << path[i] << "\n "[i+1<path.size()];
		}
	}
}
