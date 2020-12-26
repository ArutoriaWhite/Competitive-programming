#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int n, m;
struct Node {int v=0x3f3f3f3f, cnt=0;} st[N<<1];
inline Node merge (Node a, Node b)
{
	Node res;
	res.v = min(a.v, b.v);
	if (res.v==a.v) res.cnt += a.cnt;
	if (res.v==b.v) res.cnt += b.cnt;
	return res;
}
inline void build()
{
	for (int i=0; i<n; i++)
		cin >> st[i+n].v, st[i+n].cnt=1;
	for (int i=n-1; i; i--) st[i]=merge(st[i<<1],st[i<<1|1]);
}
inline void modify (int p, int x)
{
	for (st[p+=n].v=x,st[p].cnt=1; p>1; p>>=1)
		st[p>>1] = merge(st[p], st[p^1]);
}
inline Node query (int l, int r)
{
	Node res;
	for (l+=n,r+=n; l<r; l>>=1,r>>=1)
	{
		if (l&1) res = merge(res, st[l++]);
		if (r&1) res = merge(res, st[--r]);
	}
	return res;
}

signed main()
{
	XinAi
	cin >> n >> m;
	build();
	for (int i=0,a,b,c; i<m; i++)
	{
		cin >> a >> b >> c;
		if (a==1) modify(b,c);
		else
		{
			Node res=query(b,c);
			cout << res.v << ' ' << res.cnt << '\n';
		}
	}
}
