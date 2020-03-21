#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10, LOG = 13;
 
struct mod { int x, y, g; } mods[N];
vector<int> adj[N];
int id[N][N];
int sce[N], anc[N][LOG], tin[N], tout[N], t, n, m;

inline bool cmp (mod a, mod b) { return a.g < b.g; }

inline void dfs (int u, int p, int d)
{
	tin[u] = ++t;
	anc[u][0] = p;
	for (int j=1; (1<<j)<d; j++)
		anc[u][j] = anc[ anc[u][j-1] ][j-1];
	for (auto v: adj[u])
		if (v != p)
			dfs(v,u,d+1);
	tout[u] = ++t;
}
inline bool isanc (int a, int x)
{
	return (a==-1)? (1) : (tin[a]<=tin[x]&&tout[x]<=tout[a]);
}
inline int lca (int a, int b)
{
	if (isanc(a,b)) return a;
	if (isanc(b,a)) return b;
	int s = LOG-1;
	while (s>=0)
	{
		if (isanc(anc[a][s],b)) s--;
		else a = anc[a][s];
	}
	return anc[a][0];
}

inline void upd (int x, int a, int g)
{
	for (int i=x,j=anc[x][0]; i!=a; i=j,j=anc[j][0])
		sce[ id[i][j] ] = g;
}
inline void modify (const mod &q)
{
	int a = lca(q.x,q.y);
	upd(q.x, a, q.g), upd(q.y, a, q.g);
}
inline int query (int x, int a)
{
	int res = 1e9;
	for (int i=x,j=anc[x][0]; i!=a; i=j,j=anc[j][0])
		res = min( res, sce[id[i][j]]);
	return res;
}
inline bool check_all ()
{
	for (int i=0; i<m; i++)
	{
		int x=mods[i].x, y=mods[i].y;
		int a = lca(x,y);
		if (min(query(x,a),query(y,a))!=mods[i].g)
			return 0;
	}
	return 1;
}
inline void init ()
{
	memset(anc,-1,sizeof(anc));
}
 
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	init();
	cin >> n;
	for (int i=0,a,b; i<n-1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		id[a][b] = id[b][a] = i;
	}
	dfs(1,-1,0);
	cin >> m;
	for (int i=0,x,y,g; i<m; i++)
		cin >> x >> y >> g, mods[i] = {x,y,g};
	sort(mods,mods+m,cmp);
	for (int i=0; i<m; i++)
		modify(mods[i]);
	if (check_all())
		for (int i=0; i<n-1; i++)
			cout << max(1,sce[i]) << "\n "[i+1<n];
	else cout << -1 << '\n';
}
