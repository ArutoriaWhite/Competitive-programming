#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1010;

vector<pii> G[N];
int dis[N], n, m, op, ed;

void dijks()
{
	mem(dis,-1);
	queue<int> q;
	dis[op] = 0;
	q.push(op);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (auto v: G[u])
		{
			if (dis[v.ss]<0 || dis[v.ss] > dis[u]+v.ff)
			{
				dis[v.ss] = dis[u]+v.ff;
				q.push(v.ss);
			}
		}
	}
}

signed main()
{
	ShinraTensei;
	while (cin >> n >> m >> op >> ed)
	{
		rep(i,1,n) G[i].clear();
		rep(i,1,m)
		{
			int u, v, w;
			cin >> u >> v >> w;
			G[u].pb({w,v});
			G[v].pb({w,u});
		}
		dijks();
		if (dis[ed] < 0) cout << "He is very hot\n";
		else cout << dis[ed] << '\n';
	}
}
