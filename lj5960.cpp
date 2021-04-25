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

/*
xi - xj <= w
xi <= xj+w
connect xj to xi by w
claim xi <= 0, then decrease xi if too big
   */

const int N = 5e3+10;

int dis[N], cnt[N], n, m;
vector<pii> G[N]; //{w,to};
queue<pii> pq;

int spfa() // return 1 if exist negative cycle
{
	rep(i,1,n) G[0].pb({0,i});
	rep(i,0,n) pq.push({0,i});
	
	while (pq.size())
	{
		int i = pq.front().ss;
		int d = pq.front().ff;
		pq.pop();
		if (cnt[i] >= n) return 1;
		for (auto v: G[i])
		{
			int to = v.ss;
			int w = v.ff;
			if (dis[to] > w+d)
			{
				dis[to] = w+d;
				pq.push({dis[to],to});
				cnt[to]++;
			}
		}
	}
	return 0;
}

signed main()
{
	pui
	cin >> n >> m;
	rep(i,1,m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[v].pb({w,u});	
	}
	if (spfa()) cout << "NO" << endl;
	else
	{
		rep(i,1,n) cout << dis[i] << ' ';
		cout << endl;
	}
}
