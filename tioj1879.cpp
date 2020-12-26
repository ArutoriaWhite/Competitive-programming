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

vector<int> G[N], st;
vector<int> group[N];
int low[N], dep[N], bcc, tt;
int n, m;

void dfs (int u, int fa)
{
	dep[u] = ++tt;
	low[u] = dep[u];
	st.pb(u);
	for (auto v: G[u])
	{
		if (v != fa);
		if (!dep[v])
		{
			dfs(v,u);
			low[u] = min(low[u], low[v]);
		}
		else
		{
			low[u] = min(low[u], dep[v]);
		}
	}
	if (low[u]==dep[u])
	{
		bcc++;
		for (int x=0; x!=u; group[bcc].pb(x))
			x = st.back(), st.pop_back();
	}
}

signed main()
{
	cin >> n >> m;
	rep(i,1,m)
	{
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0);
	rep(i,1,bcc)
	{
		cout << i << ":";
		sort(group[i].begin(), group[i].end());
		for (auto v: group[i]) cout << ' ' << v;
		cout << '\n';
	}
}
