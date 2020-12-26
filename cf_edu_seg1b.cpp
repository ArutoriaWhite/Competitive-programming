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

int st[N<<1], n, m;

inline void build()
{
	for (int i=0; i<n; i++) cin >> st[i+n];
	for (int i=n-1; i; i--) st[i] = min(st[i<<1],st[i<<1|1]);
}
inline void setto (int p, int x)
{
	for (st[p+=n]=x; p>1; p>>=1)
		st[p>>1] = min(st[p], st[p^1]);
}
inline int query (int l, int r)
{
	int res = 0x3f3f3f3f;
	for (l+=n,r+=n; l<r; l>>=1,r>>=1)
	{
		if (l&1) res = min(res, st[l++]);
		if (r&1) res = min(res, st[--r]);
	}
	return res;
}
signed main()
{
	XinAi;
	cin >> n >> m;
	build();
	for (int i=0,a,b,c; i<m; i++)
	{
		cin >> a >> b >> c;
		if (a==1) setto(b,c);
		else cout << query(b,c) << '\n';
	}
}
