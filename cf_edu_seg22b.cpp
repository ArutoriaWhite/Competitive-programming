#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define shaaark ios::sync_with_stdio(0), cin.tie(0);
#define int long long
#define MID ((l+r)>>1)
using namespace std;
const int N = 1e5+10, M = 1e9+7;

struct ST
{
	int st[N<<2], lz[N<<2];
	void upd (int u, int x)
	{
		st[u] = (st[u]*x)%M;
		lz[u] = (lz[u]*x)%M;		
	}
	inline void pull (int u)
	{
		st[u] = (st[u<<1]+st[u<<1|1])%M;
	}
	inline void push (int u)
	{
		upd(u<<1,lz[u]), upd(u<<1|1,lz[u]), lz[u] = 1;
	}
	inline void build (int u, int l, int r)
	{
		lz[u] = 1;
		if (l == r) st[u] = 1;
		else
		{
			build(u<<1,l,MID);
			build(u<<1|1,MID+1,r);
			pull(u);
		}
	}
	inline void rmul (int u, int l, int r, int ql, int qr, int x)
	{
		if (ql>r || l>qr) return;
		if (ql<=l && r<=qr) upd(u,x);
		else
		{
			push(u);
			rmul(u<<1,l,MID,ql,qr,x), rmul(u<<1|1,MID+1,r,ql,qr,x);
			pull(u);
		}
	}
	inline int query (int u, int l, int r, int ql, int qr)
	{
		if (ql>r || l>qr) return 0;
		if (ql<=l && r<=qr) return st[u];
		else
		{
			push(u);
			return (query(u<<1,l,MID,ql,qr) + query(u<<1|1,MID+1,r,ql,qr))%M;
		}
	}
} st;

signed main()
{
	shaaark
	int n, m;
	cin >> n >> m;
	st.build(1,1,n);
	for (int i=0,t,l,r,x; i<m; i++)
	{
		cin >> t >> l >> r;
		if (t==1) cin >> x, st.rmul(1,1,n,l+1,r,x);
		else cout << st.query(1,1,n,l+1,r) << '\n';
	}
}