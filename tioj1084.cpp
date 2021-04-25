#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define pui ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2050;
vector<int> G[510], to, st;
int vis[N], m;

void dfs (int u)
{
	for (auto eid: G[u])
	{
		if (vis[eid] || vis[eid^1])
			continue;
		vis[eid] = 1;
		dfs(to[eid]);
	}
	st.pb(u);
}

inline int cmp (int i, int j)
{
	return to[i] < to[j];
}

signed main()
{
	pui
	while (cin >> m && m)
	{
		rep(i,1,500) G[i].clear();
		to.clear();
		memset(vis,0,sizeof(vis));
		st.clear();

		rep(i,1,m)
		{
			int u, v;
			cin >> u >> v;
			G[u].pb(to.size());
			to.pb(v);
			G[v].pb(to.size());
			to.pb(u);
		}
		int mnnode=-1, s=-1;
		rep(i,1,500)
		{
			if (G[i].size()==0) continue;
			if (mnnode<0 || i<mnnode)
				mnnode = i;
			if (G[i].size()&1)
				if (s<0 || i<s)
					s = i;
			sort(G[i].begin(), G[i].end(), cmp);
		}
		int op = (s>0? s:mnnode);
		dfs(op);
		for (int i=st.size()-1; i>=0; i--)
			cout << st[i] << '\n';
		cout << '\n';
	}
}
