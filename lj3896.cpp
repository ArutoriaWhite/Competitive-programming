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

const int N = 1e4+10, Q = 110, V = 1e7+10;

vector<pii> G[N];
int q[Q], ans[Q], n, m;

signed main()
{
	cin >> n >> m;
	rep(i,2,n)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].pb({v,w});
		G[v].pb({u,w});
	}
	rep(i,1,n) cin >> q[i];

	solve(getRoot
}

