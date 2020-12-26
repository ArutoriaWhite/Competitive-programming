#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 20010, M = 130010;

vector<pii> G[N];
struct Edg {int u, v, w;} e[M];
vector<Edg> rem;
int n, m, p[N];

int find (int x){return (p[x]==x? x : p[x]=find(p[x]));}
int krus()
{
	sort(e,e+m,[](Edg i, Edg j){return i.w<j.w;});
	for (int i=0; i<=n; i++) p[i]=i;
	int res=0;
	for (int i=0; i<m; i++)
	{
		int u=e[i].u, v=e[i].v, w=e[i].w;
		if (find(u) == find(v))
		{
			rem.push_back(e[i]);
			continue;
		}
		p[find(u)] = find(v);
		res += w;
		G[u].push_back({w,v});
		G[v].push_back({w,u});
	}
	return res;
}
int vis[N], fa[N][30], val[N][30], d[N];
void dfs (int u)
{
	vis[u] = 1;
	for (int i=1; i<30; i++)
	{
		fa[u][i] = fa[fa[u][i-1]][i-1];
		val[u][i] = max(val[u][i-1], val[fa[u][i-1]][i-1]);
	}
	for (auto v: G[u])
	{
		if (!vis[v.S])
		{
			fa[v.S][0] = u;
			val[v.S][0] = v.F;
			d[v.S] = d[u]+1;
			dfs(v.S);
		}
	}
}
int query (int a, int b)
{
	int res=0;
	if (d[a]<d[b]) swap(a,b);
	for (int t=d[a]-d[b],i=0; t; t>>=1,i++)
		if (t&1) res=max(res,val[a][i]),a=fa[a][i];
	if (a == b) return res;
	int s=29;
	while (s >= 0)
	{
		if (fa[a][s] == fa[b][s]) s--;
		else
		{
			res = max(res, val[a][s]);
			res = max(res, val[b][s]);
			a = fa[a][s];
			b = fa[b][s];
		}
	}
	res = max(res, val[a][0]);
	res = max(res, val[b][0]);
	return res;
}
void init()
{
	for (int i=0; i<N; i++) G[i].clear();
	rem.clear();
	memset(vis,0,sizeof(vis));
	memset(val,0,sizeof(val));
}


signed main()
{
	XinAi
	int t;
	cin >> t;
	while (t--)
	{
		init();
		cin >> n >> m;
		for (int i=0; i<m; i++)
		{
			cin >> e[i].u >> e[i].v >> e[i].w;
			e[i].u++;
			e[i].v++;
		}
		int mst = krus();
		dfs(1);
		int sec=9e18;
		for (auto ee: rem)
		{
			int q = query(ee.u, ee.v);
			if (q == ee.w) continue;
			else sec = min(sec, mst-q+ee.w);
		}
		cout << sec-mst << '\n';
	}
}
/*
1
3 4
0 1 3
2 1 4
0 2 6
1 2 5
*/
