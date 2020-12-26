#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define SZ(x) ((int)x.size())
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

vector<int> G[N];
int pa[N][30];

void dfs (int u, int p)
{
	
}
int climb (int u, int k)
{
	
}
int lca (int a, int b)
{
	
}
int query (int s, int t, int k)
{
	if (d[s]>d[t]) swap(s,t);
	int pp = lca(s,t);
	if (d[t]-d[pp] + d[s]-d[pp] < k) return -1;
	if (pp==s) return climb(t,k);
	else
	{
		
	}
}

signed main()
{
	cin >> n >> q;
	for (int i=1,u,v; i<n; i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for (int i=0,s,t,k; i<q; i++)
	{
		cin >> s >> t >> k;
		cout << query(s,t,k) << '\n';
	}
}

