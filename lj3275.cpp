#include <bits/stdc++.h>
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

const int N = 2e5+10;

struct E {int ff, ss, nx;} e[N]; // {w,to}
int dis[N], cnt[N], n, m, ucnt, head[N];

inline void add (int u, int w, int v)
{
	e[++ucnt] = {w,v,head[u]};
	head[u] = ucnt;
}
inline int spfa() //return 1 if exist negative cycle
{
	int T = clock();
	rep(i,1,n) add(0,1,i);
	
	queue<int> q;
	q.push(0);
	while (q.size())
	{
		int i = q.front();
		q.pop();
		
		if (cnt[i] >= n || clock()-T > 0.97*CLOCKS_PER_SEC) return 1;
		if (cnt[i] >= n) return 1;

		for (int eid=head[i]; eid; eid=e[eid].nx)
		{
			int v = e[eid].ss;
			int w = e[eid].ff;
			if (dis[v] < w+dis[i])
			{
				dis[v] = w+dis[i];
				q.push(v);
				cnt[v]++;
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
		int a, b, w;
		cin >> w >> a >> b;
		if (w == 1) add(b,0,a), add(a,0,b);
		if (w == 2) add(a,1,b);
		if (w == 3) add(b,0,a);
		if (w == 4) add(b,1,a);
		if (w == 5) add(a,0,b);
	}	
	if (spfa()) cout << -1 << endl;
	else 
	{
		long long ans = 0;
		rep(i,1,n) ans += dis[i];
		cout << ans << endl;
	}
}
