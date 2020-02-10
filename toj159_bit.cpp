#include <bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
const int N = 5e4+10;

vector<int> adj[N];
int w[N], bit[N<<2], n, m, tin[N], tout[N], t, res;

void dfs (int u, int p)
{
	tin[u] = ++t;
	for (auto v: adj[u])
		if (v!=p) dfs(v,u);
	tout[u] = ++t;
}
inline void modify (int p, int x)
{
	for (int k=(n<<1)+10; p<=k; bit[p]+=x,p+=lowbit(p));
}
inline void upd (int v, int x)
{
	modify(tin[v],x-w[v]);
	modify(tout[v],-x+w[v]);
	w[v] = x;
}
inline int sum (int i)
{
	for (int res=0; i>=0; res+=bit[i],i-=lowbit(i))
		if (i<=0) return res;
}

int main()
{
	cin >> n >> m;
	for (int i=0,u,v; i<n-1; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	for (int i=1,x; i<=n; i++)
		cin >> x, upd(i,x);
	char opr;
	for (int i=0,x,y; i<m; i++)
	{
		cin >> opr;
		if (opr == 'C')
			cin >> x >> y, upd(x,y);
		else
			cin >> x, res += sum(tin[x]);
	}
	cout << res << '\n';
}
