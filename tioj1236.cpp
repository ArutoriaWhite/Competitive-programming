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
const int N = 210;

vector<int> G[N];
vector<pii> E; //{to, capacity}
int n, m, ind[N], oud[N];
int op, ed;

void add (int u, int v, int w) //add edge (after process)
{
	G[u].pb(E.size());
	E.pb({v,w});
	G[v].pb(E.size());
	E.pb({u,0});
}

struct DICNIC
{
	int lv[N], his[N];
	int bfs ()
	{
		// if cannot reach ed return 0
		// make lv table	
		queue<int> q;
		memset(lv,0x3f,sizeof(lv));
		q.push(op);
		lv[op] = 0;
		
		while (!q.empty())
		{
			int u = q.front(); q.pop();
			for (auto eid: G[u])
			{
				int v = E[eid].ff;
				int w = E[eid].ss;
				if (w <= 0) continue;
				if (lv[u]+1 < lv[v])
				{
					lv[v] = lv[u]+1;
					q.push(v);
				}
			}
		}	
		return lv[ed]<1e9;
	}
	int dfs (int u=op, int cf=9e18)
	{
		if (u == ed) return cf;
		
		for (int &i=his[u];	i<G[u].size(); i++)
		{
			int eid = G[u][i];
			int v = E[eid].ff;
			int w = E[eid].ss;
			if (w <= 0) continue;
			if (lv[v] != lv[u]+1) continue;
			int nf = dfs(v,min(cf,w));
			if (nf > 0)
			{
				E[eid].ss -= nf;
				E[eid^1].ss += nf;
				return nf;
			}
		}
		return 0;
	}
	int flow()
	{
		int ans = 0, f = 0;
		while (bfs())
		{
			memset(his,0,sizeof(his));
			while(f=dfs())
				ans += f;
		}
		return ans;
	}
} dicnic;

signed main()
{
	pui
	cin >> n;
	op = 0;
	ed = 2*n+1;
	rep(i,1,n)
	{
		int w; cin >> w;
		add(i,i+n,w);
	}
	cin >> m;
	rep(i,1,m)
	{
		int a, b;
		cin >> a >> b;
		add(a+n,b,9e18);
		oud[a]++, ind[b]++;
	}
	rep(i,1,n)
		if (ind[i] == 0)
			add(op,i,9e18);
	rep(i,1,n)
		if (oud[i] == 0)
			add(i+n,ed,9e18);
	cout << dicnic.flow() << '\n';
}
