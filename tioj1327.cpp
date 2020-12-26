#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int t, n, x[N], y[N], idx[N], p[N];
struct Edge {int u, v, w;};
vector<Edge> err;

int find (int u){ return (p[u]==u? u:p[u]=find(p[u])); }
void gen_edg()
{
	err.clear();
	rep(i,1,n) idx[i] = i;
	sort(idx+1,idx+1+n,[](int i, int j){return pii(x[i],y[i]) < pii(x[j],y[j]);});
	rep(i,1,n-1)
		if (x[idx[i]] == x[idx[i+1]])
			err.pb({idx[i],idx[i+1],y[idx[i+1]]-y[idx[i]]});
	sort(idx+1,idx+1+n,[](int i, int j){return pii(y[i],x[i]) < pii(y[j],x[j]);});
	rep(i,1,n-1)
		if (y[idx[i]] == y[idx[i+1]])
			err.pb({idx[i],idx[i+1],x[idx[i+1]]-x[idx[i]]});
}
int krus()
{
	int res=0;
	rep(i,1,n) p[i] = i;
	sort(err.begin(), err.end(), [](Edge i, Edge j){return i.w<j.w;} );
	for (auto e: err)
	{
		int u = e.u, v = e.v, w = e.w;
		if (find(u) == find(v)) continue;
		p[find(u)] = find(v);
		res += w;
	}
	return res;
}

signed main()
{
	ShinraTensei
	cin >> t;
	while (t--)
	{
		cin >> n;
		rep(i,1,n) cin >> x[i] >> y[i];
		gen_edg();
		cout << krus() << '\n';
	}
}
