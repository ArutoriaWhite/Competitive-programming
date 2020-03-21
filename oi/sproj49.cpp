#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
const int maxN = 1e5+10;

int n, m, t=0;
vector<int> to[maxN];
int res[maxN], vis[maxN];

inline void init()
{
	for (int i=0; i<=n; i++)
		to[i].clear();
	memset(res,0,sizeof(res));
}

int dfs( int u)
{
	vis[u] = t;
	res[u] = 1;
	for (auto v: to[u])
		res[u] += dfs(v);
	return res[u];
}

void gen()
{
	for (int i=1; i<=n; i++)
		if (vis[i]<t)
			dfs(i);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	for (t=1; t<=T; t++)
	{
		cin >> n >> m;
		init();
		
		for (int i=0; i<m; i++)
		{
			int x, y;
			cin >> x >> y;
			to[x].push_back(y);
		}
		
		gen();
		
		int q;
		cin >> q;
		while (q--)
		{
			int x;
			cin >> x;
			cout << res[x] << '\n';
		}
	}
}
