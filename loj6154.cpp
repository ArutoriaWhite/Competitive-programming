#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb emplace_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = 1e5+10;

vector<int> from[N];
int n, m, path[N], cnt[N], sn, mt;

int fpath (int u)
{
	if (path[u] == -1)
	{
		path[u] = 1;
		for (auto p: from[u])
		{
			path[u] = path[u] + fpath(p);
		}
	}
	return path[u];
}
int fcnt (int u)
{
	if (cnt[u] == -1)
	{
		cnt[u] = 0;
		for (auto p: from[u])
		{
			cnt[u] = fcnt(p) + fpath(p);
		}
	}
	return cnt[u];
}

int main()
{
	mem(cnt,-1), mem(path,-1);
	cin >> n >> m;
	for (int i=0,x,y; i<m; i++)
		cin >> x >> y, from[y].pb(x);
	for (int i=1; i<=n; i++)
	{
		sn = sn + fcnt(i);
		mt = mt + fpath(i);
	}
	de(sn), de(mt);
}
