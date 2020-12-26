#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

vector<int> G[N];
int sz[N], n;

void dfs (int u, int p)
{
	sz[u] = 1;
	for (auto v: G[u])
		if (v!=p) dfs(v,u), sz[u] += sz[v];
}
void del (int u, int p)
{
	for (auto v: G[u])
		if (v!=p && sz[v]%2==0) del(v,u);
	cout << u << '\n';
	for (auto v: G[u])
		if (v!=p && sz[v]%2==1) del(v,u);
}

signed main()
{
	cin >> n;
	if (n%2==0)
	{
		cout << "NO\n";
		return 0;
	}
	rep(i,1,n)
	{
		int p;
		cin >> p;
		if (p==0) continue;
		G[p].push_back(i);
		G[i].push_back(p);
	}
	dfs(1,0);
	cout << "YES\n";
	del(1,0);
}
