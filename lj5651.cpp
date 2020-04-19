#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define exi(x,s) (s.find(x)!=s.end())
#define fi first
#define se second
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1e5+10;

int pre[N], n, m, q, vis[N];
vector<Pii> adj[N];

void dfs (int u, int p)
{
	for (auto e: adj[u])
		if (!vis[e.fi] && e.fi!=p)
		{
			pre[e.fi] = pre[u]^e.se;
			vis[e.fi] = 1;
			dfs(e.fi,u);
		}
}

int main()
{
	cin >> n >> m >> q;
	for (int i=0,u,v,w; i<m; i++)
	{
		cin >> u >> v >> w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	dfs(1,0);
	for (int i=0,x,y; i<q; i++)
		cin >> x >> y, cout << (pre[x]^pre[y]) << '\n';
}
