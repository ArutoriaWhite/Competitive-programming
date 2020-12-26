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
int h1[N], h2[N], rad, n;

inline void upd (int u, int h)
{
	if (h>=h1[u]) h2[u]=h1[u], h1[u]=h;
	else if (h>=h2[u]) h2[u] = h;
}
void dfs (int u)
{
	for (auto v: G[u])
		dfs(v), upd(u,h1[v]+1);
	rad = max(rad, h1[u]+h2[u]);
}

signed main()
{
	XinAi
	cin >> n;
	string s;
	stringstream ss;
	getline(cin,s);
	for (int i=0; i<n; i++)
	{
		getline(cin,s);
		ss.clear();
		ss.str(s);
		int u;
		while (ss >> u && u>=0)
		{
			G[i].push_back(u);
		}
	}
	dfs(0);
	cout << rad << '\n';
}
