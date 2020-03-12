#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
const int INF=0x7f7f7f7f, N = 1e4+10, M = 5e4+10, LOGN = 15;

struct edge {int a, b, w;};
edge edges[M];
vector<pii> adj[N]; // to, w
int n, m, dis[N], minv[N][LOGN], par[N][LOGN], vis[N];

inline void init()
{
	for (int i=0; i<N; i++) dis[i] = i;
	mem(minv,INF);
	mem(par,-1);
}
// dis
inline int find (int x)
{
	return (dis[x]==x? x : dis[x]=find(dis[x]));
}
inline void U (int x, int y)
{
	dis[find(x)] = find(y);
}

void kruskal ()
{
	sort(edges,edges+m,[](edge x, edge y){return x.w>y.w;});
	for (int i=0; i<m; i++)
	{
		edge &e = edges[i];
		if (find(e.a) == find(e.b)) continue;
		U(e.a,e.b);
		adj[e.a].pb({e.b,e.w}), adj[e.b].pb({e.a,e.w});
	}
}

void dfs (int u, int p, int v, int d)
{
	vis[u] = 1;
	par[u][0] = p, minv[u][0] = v;
	for (int j=1; (1<<j)<=d; j++)
	{
		par[u][j] = par[ par[u][j-1] ][j-1];
		minv[u][j] = min( minv[u][j-1], minv[par[u][j-1]][j-1]);
	}
	for (auto e: adj[u])
		if (e.first != p)
			dfs (e.first, u, e.second, d+1);
}
inline bool isanc (int a, int x)
{

}
inline int lca (int a, int b)
{

}
inline int query (int a, int b)
{
	if (find(a) != find(b)) return -1;
}

void test()
{
	for (int i=1; i<=n; i++)
	{
		de(i);
		for (auto e: adj[i]) de(e.first);
		dend;
	}
}
void test_dfs()
{
	for (int i=1; i<=n; i++)
	{
		de(i);
		for (int j=0; j<LOGN; j++) de(minv[i][j]), dend;
	}
}

int main()
{
	akiyama;
	init();
	cin >> n >> m;
	for (int i=0,a,b,w; i<m; i++)
		cin >> a >> b >> w, edges[i] = {a,b,w};
	kruskal();
	for (int i=1; i<=n; i++)
		if (!vis[i]) dfs(i,0,INF,0);
} 
