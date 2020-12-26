#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define shaaark ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 5010, M = N*N;

vector<int> G[N];
int n, m;
int used[N], w[N], idx[N], nowdg[N];
int p[N], sz[N], mn[N];

int find (int x){ return (p[x]==x? x:p[x]=find(p[x])); }
void U (int u, int v)
{
	sz[find(v)] += sz[find(u)];
	p[find(u)] = find(v);
}
inline void init()
{
	rep(i,1,n) G[i].clear();
	memset(used,0,sizeof(used));
	memset(w,0,sizeof(w));
	memset(nowdg,0,sizeof(nowdg));

}
void get_per()
{
	rep(i,1,n)
	{
		int mnode=-1;
		rep(j,1,n)
			if (mnode==-1 || w[j]<w[mnode]) mnode=j;
		for (auto v: G[mnode]) w[v]--;
		idx[n-i+1] = mnode;
		w[mnode]=1e9;
	}
}

signed main()
{
	shaaark
	while (cin >> n >> m)
	{
		init();
		for (int i=0,u,v; i<m; i++)
		{
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			w[u]++, w[v]++;
		}
		get_per();
		rep(i,1,n) p[i]=i, sz[i]=1;

		int ans=0;
		rep(i,1,n)
		{
			int u = idx[i];
			used[u]=1;
			for (auto v: G[u])
			{
				if (used[v])
				{
					if(find(u)!=find(v)) U(u,v);
					nowdg[u]++;
					nowdg[v]++;
				}
			}
			rep(i,1,n) mn[i]=1e9;
			rep(i,1,n) mn[find(i)] = min(mn[find(i)], nowdg[i]);
			rep(i,1,n) ans = max(ans, mn[find(i)]*sz[find(i)]);
		}
		cout << ans << '\n';		
	}

}