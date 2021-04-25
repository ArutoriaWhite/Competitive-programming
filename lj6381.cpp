#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

struct Edge {int v, w, l;};
vector<Edge> G[N];
vector<pii> dp[N];
int vis[N], n, m, k, ans;

int mnp[200000];
void sieve()
{
	for (int i=2; i<200000; i++)
	{
		if (mnp[i] == 0)
		{
			mnp[i] = i;
			for (int j=i*2; j<200000; j+=i)
				if (!mnp[j])
					mnp[j] = i;
		}
	}
}
void distract (int x, vector<pii> &res)
{
	int owo = 0;
	while (x > 1)
	{
		owo = mnp[x];
		x /= owo;
		if (res.empty() || res.back().ff!=owo)
			res.pb({owo,1});
		else
			res.back().ss++;
	}
}
int legal (int i, int j)
{
	vector<pii> disi, disj;
	distract(i,disi);
	distract(j,disj);

	int p = 0, q = 0, n = disi.size(), m = disj.size();

	while (p<n || q<m)
	{
		de(p), de(q), dd;
		if (p<n && q<m && disi[p].ff==disj[q].ff)
		{
			if ((disi[p].ss + disj[q].ss)%k) return 0;
			p++, q++;
		}
		else if (q>=m || (p<n && disi[p].ff < disj[q].ff))
		{
			if ((disi[p].ss%k)) return 0;	
			p++;
		}
		else if (p>=n || (q<m && disj[q].ff < disi[p].ff))
		{
			if ((disj[q].ss%k)) return 0;
			q++;
		}
	}
	return 1;
}

void dfs (int u)
{
	if (vis[u]) return;
	vis[u] = 1;

	for (auto e: G[u])
	{
		int mxdp = 0;
		int v = e.v;
		int w = e.w;
		int l = e.l;	
		for (auto pr: dp[v])
		{
			int lim = pr.ff;
			int val = pr.ss;
			if (legal(w,lim))
				mxdp = max(mxdp, val+l);
		}
		dp[u].pb({w,mxdp});
		ans = max(ans, mxdp);
	}
}

void test()
{
	int x, y;
	while (cin >> x >> y >> k)
	{
		vector<pii> d;
		distract(x,d);
		for (auto p: d)
			de(p.ff), de(p.ss), dd;
		vector<pii> w;
		distract(y,w);
		for (auto q: w)
			de(q.ff), de(q.ss), dd;
		de(legal(x,y)), dd
	}
}

signed main()
{
	sieve();
	//test();
	cin >> n >> m >> k;
	rep(i,1,m)
	{
		int u, v, w, l;
		cin >> u >> v >> w >> l;
		G[u].pb({v,w,l});
	}
	
	rep(i,1,n)
		dfs(i);
	cout << ans << '\n';	
}
