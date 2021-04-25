#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define endl '\n'
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 510;

int n, k, vis[N<<1], hus[N<<1];
vector<int> G[N];

int dfs (int i)
{
	if (vis[i]) return 0;
	vis[i] = 1;
	for (auto v: G[i])
	{
		if (vis[v]) continue;
		if (hus[v] == 0 || dfs(hus[v]))
		{
			hus[v] = i;
			return 1;
		}
	}
	return 0;
}

int match ()
{
	int ans = 0;
	rep(i,1,n)
	{
		memset(vis,0,sizeof(vis));
		if (dfs(i)) ans++;
	}
	return ans;
}

signed main()
{
	cin >> n >> k;
	while (k--)
	{
		int x, y;
		cin >> x >> y;
		G[x].pb(y+n);
	}
	cout << match() << endl;
}
