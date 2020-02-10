#include <iostream>
#include <vector>
using namespace std;
const int N = 5e4+10;

int w[N], par[N], n, m, ans;
vector<int> adj[N];

inline int query (int x)
{
	int res=0;
	for (int i=x; i>0; i=par[i]) res += w[i];
	return res;
}

void dfs (int u, int p)
{
	par[u] = p;
	for (auto v: adj[u])
		if (v!=p) dfs(v,u);
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i=0,u,v; i<n-1; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	for (int i=1; i<=n; i++)
		cin >> w[i];
	
	char opr;
	for (int i=0,x,y; i<m; i++)
	{
		cin >> opr;
		if (opr == 'C')
			cin >> x >> y, w[x]=y;
		if (opr == 'G')
			cin >> x, ans += query(x);
	}
	cout << ans << '\n';
}
