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
const int N = 1e4+10;

vector<int> G[N];
int t, n;
int msz[N], sz[N];

void dfs (int u, int p)
{
	sz[u]=1;
	for (auto v: G[u])
		if (v!=p)
			dfs(v,u), sz[u] += sz[v];
}
void dfs2 (int u, int p)
{
	for (auto v: G[u])
		if (v!=p) dfs2(v,u), msz[u]=max(msz[u],sz[v]);
	msz[u] = max(msz[u], sz[1]-sz[u]);
}
signed main()
{
	XinAi
	cin >> t;
	while (t--)
	{
		cin >> n;
		rep(i,0,n) G[i].clear();
		memset(msz,0,sizeof(msz));
		memset(sz,0,sizeof(sz));
		for (int i=1,x,y; i<n; i++)
		{
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1,0);
		dfs2(1,0);
		vector<int> cent;
		int m=0x3f3f3f3f;
		//rep(i,1,n) de(i), de(sz[i]), de(msz[i]), dd;
		rep(i,1,n)
		{
			if (msz[i]<m) cent.clear(), cent.push_back(i), m=msz[i];
			else if (msz[i]==m) cent.push_back(i);
		}
		if (cent.size()==1)
		{
			cout << cent[0] << ' ' << G[cent[0]][0] << '\n';
			cout << cent[0] << ' ' << G[cent[0]][0] << '\n';
		}
		else
		{
			cout << cent[0] << ' ' << cent[1] << '\n';
			cout << cent[1] << ' ' << (G[cent[0]][0]==cent[1]? G[cent[0]][1] : G[cent[0]][0]) << '\n';
		}
	}
}
