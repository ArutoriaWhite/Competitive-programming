#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = 6e3+10;

int dp[N][2], vis[N][2], w[N], n, res = -1e9;
vector<int> adj[N];

int f (int u, int b)
{
	if (!vis[u][b])
	{
		vis[u][b] = 1;
		int s1=0, s2=0;
		for (auto v: adj[u])
			s1 += f(v,0), s2 += f(v,1);
		if (b==1) dp[u][b] = s1+w[u];
		else dp[u][b] = max(s1,s2);
	}
	return dp[u][b];
}

int main()
{
	akiyama;
	cin >> n;
	for (int i=1; i<=n; i++) cin >> w[i];
	for (int i=0,p,s; i<n-1; i++)
		cin >> s >> p, adj[p].pb(s);
	for (int i=1; i<=n; i++)
	{
		res = max(f(i,1),res);
		res = max(f(i,0),res);
	}
	cout << res << '\n';
	cin >> w[0] >> w[1];
}
