#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

int w[N], c[N], n;
vector<int> G[N];

inline int cmp (int i, int j)
{
	return c[i]-w[i] > c[j]-w[j];
}

void dfs (int u)
{
	for (auto v: G[u])
		dfs(v);

	sort(G[u].begin(), G[u].end(), cmp);
	
	int rest = 0, &cost = c[u];
	for (auto v: G[u])
	{
		int off = min(c[v], rest);
		cost += c[v]-off;
		rest += c[v]-w[v]-off;
	}
	cost += w[u] - min(w[u], rest);
}

signed main()
{
	pui
	cin >> n;
	rep(i,2,n)
	{
		int p; cin >> p;
		G[p].pb(i);
	}
	rep(i,1,n) cin >> w[i];

	dfs(1);

	rep(i,1,n)
	{
		cout << c[i] << ' ';
	}
	cout << '\n';
}
