#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6+10;

int n, q;
int p[N], sz[N], dep[N], max_son[N], top[N];
vector<int> adj[N];

void dfs_max (int u)
{
	sz[u] = 1, max_son[u] = -1;
	for (auto v: adj[u])
	{
		dep[v] = dep[u]+1;
		dfs_max(v);
		sz[u] += sz[v];
		if (max_son[u]==-1 || sz[max_son[u]]<sz[v]) max_son[u] = v;
	}
}
void link()
{
	for (int u=0; u<n; u++)
		if (u==0 || u!=max_son[p[u]])
			for (int v=u; v!=-1; v=max_son[v]) top[v] = u;
}
inline int lca (int a, int b)
{
	while (top[a]!=top[b])
		if (dep[top[a]]<dep[top[b]]) b = p[top[b]];
		else a = p[top[a]];
	return (dep[a]<dep[b])? (a):(b);
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int u=1; u<n; u++)
		cin >> p[u], adj[p[u]].push_back(u);
	dfs_max(0), link();
	for (int i=0,x,f,a; i<q; i++)
	{
		cin >> x;
		for (int j=0; j<x; j++)
		{
			cin >> f;
			if (j==0) a = f;
			else a = lca(a,f);
		}
		cout << a << '\n';
	}
}
