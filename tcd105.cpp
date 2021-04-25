#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int n, m, rt;
int l[N<<1], r[N<<1], ind[N<<1], q[110];
long long w[N<<1];

void build (int u)
{
	if (l[u]==0 || r[u]==0) return;
	build(l[u]);
	build(r[u]);
	w[u] = w[l[u]]+w[r[u]];
}
int add (int u, int x)
{
	w[u] += x;
	if (l[u]==0 || r[u]==0)
		return u;
	if (w[l[u]] <= w[r[u]])
		return add(l[u],x);
	else
		return add(r[u],x);

}

signed main()
{
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> w[i+n];
	for (int i=0; i<m; i++)
		cin >> q[i];
	for (int i=0,u; i<n-1; i++)
	{
		cin >> u >> l[u] >> r[u];
		ind[l[u]]++, ind[r[u]]++;
	}

	for (int i=1; i<n; i++)
		if (ind[i] == 0)
			rt = i;

	build(rt);

	for (int i=0; i<m; i++)
		cout << add(rt,q[i]) << ' ';
	cout << '\n';
}
/*
 * 4 5
 * 0 0 0 0 
 * 1 2 3 4 5
 * 1 2 7
 * 2 3 6
 * 3 4 5
 *  */
