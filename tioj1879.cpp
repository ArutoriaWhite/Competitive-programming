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
const int N = 1e4+10;

vector<int> G[N], To, grp[N], st;
int low[N], dep[N], bcc, tstamp;
int n, m;

void dfs (int u, int p)
{
	dep[u] = low[u] = ++tstamp;
	st.pb(u);
	
	for (auto eid: G[u])
	{
		if ((eid^1) == p) continue;

		int v = To[eid];
		
		if (dep[v])
		{
			low[u] = min(low[u], dep[v]);
		}
		else
		{
			dfs(v,eid);
			low[u] = min(low[u], low[v]);
		}
	}

	if (low[u] == dep[u])
	{
		++bcc;
		for (int x=-1; x!=u; st.pop_back())
		{
			x = st.back();
			grp[bcc].pb(x);
		}
		sort(grp[bcc].begin(), grp[bcc].end());
	}
}

signed main()
{
	cin >> n >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		G[u].pb(To.size()), To.pb(v);
		G[v].pb(To.size()), To.pb(u);
	}

	dfs(0,-1);

	sort(grp+1, grp+1+bcc);
	rep(i,1,bcc)
	{
		cout << i << ':';
		for (auto x: grp[i])
			cout << ' ' << x;
		cout << '\n';
	}
}
