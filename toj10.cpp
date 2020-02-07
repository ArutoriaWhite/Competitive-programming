#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+10;

int n, w[N], dep[N], par[N], edg[N], T;
struct edge { int to, wg, i; };
vector<edge> adj[N];

void dfs (int u, int p)
{
	for (const auto &v: adj[u])
	{
		if (v.to==p) continue;
		edg[v.i] = v.to;
		par[v.to] = u;
		w[v.to] = v.wg;
		dep[v.to] = dep[p]+1;
		dfs(v.to,u);
	}
	return;
}
inline int query (int x, int y)
{
	int res = -1e9;
	while (x!=y)
	{
		if (dep[x]>dep[y])
			res = max(res,w[x]), x=par[x];
		else
			res = max(res,w[y]), y=par[y];
	}
	return res;
}
inline void modify (int p, int x)
{
	w[edg[p]] = x;
}
inline void init()
{
	for (auto v: adj) v.clear();
	for (auto v: adj) v.reserve(n+10);
	dep[1]=0;
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n;
		init();
		for (int i=1,a,b,c; i<=n-1; i++)
		{
			cin >> a >> b >> c;
			adj[a].push_back( {b,c,i} );
			adj[b].push_back( {a,c,i} );
		}
		dfs(1,-1);

		string opr;
		int x, y;
		while (cin >> opr)
		{
			if (opr[0] == 'Q')
				cin >> x >> y, cout << query(x,y) << '\n';
			else if (opr[0] == 'C')
				cin >> x >> y, modify(x,y);
			else break;
		}
	}
}
