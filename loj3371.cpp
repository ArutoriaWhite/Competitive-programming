#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
#define int long long
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
const int N = 5e5+10, INF = (1L<<31)-1;

vector<pii> adj[N];
int dis[N], n, m, s;
priority_queue<pii,vector<pii>,greater<pii>> pq;

inline void dijks()
{
	pq.push({0,s});
	dis[s] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second, d = pq.top().first;
		pq.pop();
		if (dis[u] < d) continue;
		for (auto v: adj[u])
			if (dis[v.second] > d+v.first)
				dis[v.second] = d+v.first, pq.push({dis[v.second],v.second});
	}
}

signed main()
{
	for (int i=0; i<N; i++)
		dis[i] = INF;
	cin >> n >> m >> s;
	for (int i=0,u,v,w; i<m; i++)
	{
		cin >> u >> v >> w;
		adj[u].pb({w,v});
	}
	dijks();
	for (int i=1; i<=n; i++)
		cout << dis[i] << "\n "[i+1<=n];
}
