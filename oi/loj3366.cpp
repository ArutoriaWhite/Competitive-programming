#include <bits/stdc++.h>
using namespace std;
const int M = 2e5+10, N = 5010;

struct Edge {int a, b, w;} edges[M];
int p[N], n, m, res;

inline void init()
{
	for (int i=0; i<N; i++) p[i] = i;
}
inline bool cmp (const Edge &x, const Edge &y)
{
	return x.w < y.w;
}

// disjoint set
int find (int x)
{
	if (x==p[x]) return x;
	return p[x] = find(p[x]);
}
inline void uni (int x, int y)
{
	p[find(x)] = find(y);
}
inline bool connect ()
{
	for (int i=2; i<=n; i++)
		if (find(i)!=find(i-1)) return 0;
	return 1;
}
inline void kruskal()
{
	for (int i=0; i<m; i++)
	{
		int u = edges[i].a, v = edges[i].b, w=edges[i].w;
		if (find(u) == find(v)) continue;
		uni(u,v);
		res +=w;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	init();
	cin >> n >> m;
	for (int i=0,a,b,w; i<m; i++)
		cin >> a >> b >> w, edges[i] = {a,b,w};
	sort(edges,edges+m,cmp);
	kruskal();
	if (connect()) cout << res << '\n';
	else cout << "orz\n";
}
