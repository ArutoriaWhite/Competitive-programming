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

const int N = 1e5+10;

int lzm[N<<2], lza[N<<2], tr[N<<2], a[N], len[N<<2];
int n, m, p;

void upd (int u, int mul, int add)
{
	tr[u] = (tr[u]*mul + add*len[u])%p;
	lzm[u] = lzm[u]*mul%p;
	lza[u] = lza[u]*mul%p;
	lza[u] = (lza[u]+add)%p;
}
inline void push (int u)
{
	upd(u*2,lzm[u],lza[u]);
	upd(u*2+1,lzm[u],lza[u]);
	lzm[u] = 1, lza[u] = 0;
}
inline void pull (int u)
{
	tr[u] = (tr[u<<1] + tr[u<<1|1])%p;						
}
void modify (int ql, int qr, int mul, int add, int u=1, int l=1, int r=n)
{
	if (ql<=l && r<=qr) upd(u,mul,add);
	else if (ql>r || l>qr) return;
	else
	{
		push(u);
		int m = (l+r)/2;
		modify(ql,qr,mul,add,u*2,l,m);
		modify(ql,qr,mul,add,u*2+1,m+1,r);
		pull(u);
	}
}	
int query (int ql, int qr, int u=1, int l=1, int r=n)
{
	if (ql<=l && r<=qr) return tr[u];
	else if (ql>r || l>qr) return 0;
	else
	{
		push(u);
		int m = (l+r)/2;
		return (query(ql,qr,u*2,l,m) + query(ql,qr,u*2+1,m+1,r))%p;
	}
}
void build (int u=1, int l=1, int r=n)
{
	lza[u] = 0, lzm[u] = 1, len[u] = r-l+1;
	if (l == r) tr[u] = a[l]%p;
	else
	{
		int m = (l+r)/2;
		build(u*2,l,m);
		build(u*2+1,m+1,r);
		pull(u);
	}
}

signed main()
{
	pui
	cin >> n >> m >> p;
	rep(i,1,n) cin >> a[i];
	build();
	while (m--)
	{
		int o, x, y, k;
		cin >> o >> x >> y;
		if (o==1 && cin >> k)
			modify(x,y,k,0);
		else if (o==2 && cin >> k)
			modify(x,y,1,k);
		else
			cout << query(x,y) << endl;
	}
}

