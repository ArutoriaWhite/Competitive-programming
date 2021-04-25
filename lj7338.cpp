#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

/*
可以將相鄰兩個一個突成紅、一個塗成蘭，存不存在方法將 2*N 方格上指定
塗紅? (其他不管)
n <= 1e5
---

當一個節點需要變成紅色
往四周建邊
若不存在拓樸排序
則無解
否則有解

1. build edge (firt row 1~n, second row 1+n ~ n+n)
2. topology sort
*/

const int N = 3e6+10;
vector<int> G[N];
int n, t, ind[N];

int topo()
{
	queue<int> q;
	int ans = 0;
	memset(ind,0,sizeof(ind));
	rep(i,1,2*n)
	{
		for (auto v: G[i])
		{
			ind[v]++;
		}
	}
	rep(i,1,2*n)
	{
		if (ind[i] == 0)
		{
			q.push(i);
			ans++;
		}
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto v: G[u])
		{
			ind[v]--;
			if (ind[v] == 0)
			{
				ans ++;
				q.push(v);
			}
		}	
	}
	if (ans != 2*n) return 1;
	return 0;
}

int dfs (int u)
{
	if (G[u].size() == 0) return 1;
	for (auto v: G[u])
	{

	}
}

signed main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		
		rep(i,1,2*n) G[i].clear();
		
		rep(i,1,2)
		{
			rep(j,1,n)
			{
				char c; cin >> c;

				if (c == '1')
				{
					if (i == 1)
					{
						G[j].pb(j+n);
						if (j > 1)
							G[j].pb(j-1);
						if (j < n)
							G[j].pb(j+1);
					}
					else
					{
						G[j+n].pb(j);
						if (j > 1)
							G[j+n].pb(j-1+n);
						if (j < n)
							G[j+n].pb(j+1+n);
					}
				}
			}
		}	

		cout << (dfs()? "RP":"++") << '\n';
	}
}


