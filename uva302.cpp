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

vector<int> path;
vector<pii> G[N]; // {eid,to}
int vis[N*N], deg[N], rt;

void dfs (int i=rt)
{
	for (auto e: G[i])
	{
		int eid = e.ff;
		int to = e.ss;
		if (vis[eid]) continue;
		vis[eid] = 1;
		dfs(to);
		path.pb(eid);
	}	
}
void add (int u, int v)
{
	int z; cin >> z;
	G[u].pb({z,v});
	G[v].pb({z,u});
	deg[u]++, deg[v]++;	
}

signed main()
{
	int u, v;
	while (cin >> u >> v, u&&v)
	{
		memset(vis,0,sizeof(vis));
		memset(deg,0,sizeof(deg));
		for (int i=0; i<N; i++) G[i].clear();
		path.clear();

		add(u,v), rt = min(u,v);
		while (cin >> u >> v, u&&v)
			add(u,v);
		
		int exi=1;
		for (int i=1; i<N; i++)
			if (deg[i]&1)
				exi = 0;

		if (exi)
		{
			for (int i=1; i<N; i++)
				sort(G[i].begin(), G[i].end());
			dfs();
			for (int i=path.size()-1; i>=0; i--)
				cout << path[i] << "\n "[i-1>=0];
		}
		else cout << "Round trip does not exist.\n";
		cout << endl;
	}
}
