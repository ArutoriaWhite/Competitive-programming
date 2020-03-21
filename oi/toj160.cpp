#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 110;

int dis[N][N], n, m, T, Q;
struct edge { int to, w; };
struct cmp
{
	bool operator() (const edge &a, const edge &b){return a.w>b.w;}
};
priority_queue<edge,vector<edge>,cmp> pq;
vector<edge> adj[N];

inline void dijks (int rt)
{
	pq.push({rt,0}), dis[rt][rt] = 0;
	while (!pq.empty())
	{
		int u = pq.top().to, d = pq.top().w; pq.pop();
		if (dis[rt][u]<d) continue;
		for (auto v: adj[u])
		{
			if (dis[rt][v.to]==-1 || dis[rt][v.to]>d+v.w)
			{
				dis[rt][v.to] = d+v.w;
				pq.push({v.to,d+v.w});
			}
		}
	}
}

inline void init()
{
	memset(dis,-1,sizeof(dis));
	for (int i=0; i<N; i++)
		adj[i].clear();
	while (!pq.empty()) pq.pop();
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while (T--)
	{
		init();
		cin >> n >> m;
		for (int i=0,f,t,w; i<m; i++)
		{
			cin >> f >> t >> w;
			adj[f].push_back( {t,w} );
		}
		for (int i=1; i<=n; i++)
			dijks(i);

		cin >> Q;
		for (int i=0,f,r; i<Q; i++)
		{
			cin >> f >> r;
			cout << dis[f][r] << '\n';
		}
	}
}
