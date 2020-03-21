#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<string.h>
using namespace std;

const int maxN=1e5+10, maxM=1e6+10, INF=0x3f3f3f3f;
typedef pair<int,int> pii;

struct edge
{
	int a, b, w;
} edges[maxM];
int n, m;
vector<pii> adj[maxN];


// disjoint set
int par[maxN];
inline void init_dis()
{
	for (int i=0; i<maxN; i++)
		par[i] = i;
}
inline int find (int x)
{
	return (par[x]==x)? (x) : (par[x]=find(par[x]));
}
inline void uni (int x, int y)
{
	par[find(x)] = find(y);
}

	
// Kruskal
inline bool cmp( edge &a, edge &b)
{
	return a.w > b.w;
}
void krus ()
{
	init_dis();
	sort( edges, edges+m, cmp);
	for (int i=0,j=0; i<(n-1)&&j<m; j++)
	{
		edge &x = edges[j];
		if (find(x.a) == find(x.b)) continue;
		i++;
		uni(x.a,x.b);
		adj[x.a].push_back( {x.b,x.w} );
		adj[x.b].push_back( {x.a,x.w} );
	}
}


// dfs build
int tin[maxN], tout[maxN], t=0;
int p[maxN][35], minval[maxN][35];

inline void init_dfs()
{
	memset( p, -1, sizeof(p));
	memset( minval, INF, sizeof(minval));
}
void dfs (int u, int wx, int px, int d)
{
	tin[u] = t++;

	p[u][0]=px, minval[u][0]=wx;
	for (int i=1; (1<<i)<=d; i++)
	{
		p[u][i] = p[ p[u][i-1] ][i-1];
		minval[u][i] = min( minval[u][i-1], minval[p[u][i-1]][i-1] );
	}

	for (auto v: adj[u])
	{
		if (v.first == px) continue;
		dfs( v.first, v.second, u, d+1);
	}


	tout[u] = t++;
}

// lca
inline bool isAnc( int a, int b)
{
	return a<0 || tin[a]<tin[b] && tout[b]<tout[a];
}
inline int lca (int x, int i, bool f) // jump from a to b's anc
{
	int m=INF, s=30;
	while (s>=0)
	{
		if (isAnc(p[x][s],i))
		{
			s--;
		}
		else
		{
			m = min( minval[x][s], m);
			x = p[x][s];
		}
	}
	if (f)
		m = min( minval[x][0], m);
	return m;
}	
inline int query (int a, int b)
{
	if (!isAnc(a,b) && isAnc(b,a))
		return lca(a,b,0);
	if (!isAnc(b,a) && isAnc(a,b))
		return lca(b,a,0);

	return min( lca(a,b,1), lca(b,a,1));
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = {a,b,w};
	}
	krus();

	init_dfs();
	dfs(0,INF,-1,0);

	int q;
	cin >> q;
	for (int i=0; i<q; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << query(a,b) << '\n';
	}
}
