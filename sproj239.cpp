#include<iostream>
#include<vector>
using namespace std;
const int maxN = 1e5+10;

int n, min_val, min_id;
vector<int> gra[maxN];

inline void init()
{
	for (int i=0; i<=n; i++)
		gra[i].clear();
	min_val = 1e9;
}

int dfs( int u, int p)
{
	int deg = -1, s = 1;
	for (auto v: gra[u])
	{
		if (v==p) continue;
		int ouo = dfs(v,u);
		deg = max( ouo, deg );
		s += ouo;
	}
	deg = max( n-s, deg );
	if ( deg < min_val || (deg==min_val && u<min_id) )
	{
		min_val = deg;
		min_id = u;
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--)
	{
		init();
		cin >> n;
		for (int i=0; i<n-1; i++)
		{
			int a, b;
			cin >> a >> b;
			gra[a].push_back(b);
			gra[b].push_back(a);
		}
		dfs(0,-1);
		cout << min_id << '\n';
	}
}
