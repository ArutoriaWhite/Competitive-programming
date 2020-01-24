#include <iostream>
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define P(x) (x>>1)
#define A(x) (x^1)
#define int long long
typedef long long LL;
using namespace std;
const int N = 5e5;

LL st[N<<1], tag[N<<1], n, m;

inline void build()
{
	for (int i=0; i<n; i++) cin >> st[i+n];
	for (int i=n-1; i>0; i--) st[i] = st[L(i)]+st[R(i)];
}
inline void upd (int p, int x, int h) //修改某個節點並上 tag
{
	st[p] += x<<h;
	if (p<n) tag[p] +=x;
}
inline void push (int p) //從根節點往下, 把 tag 一個一個往下推
{
	for (int h=__lg(n); h>=0; h--)
	{
		int a = p>>h;
		if (tag[P(a)]==0) continue;
		upd(a,tag[P(a)],h);
		upd(A(a),tag[P(a)],h);
		tag[P(a)] = 0;
	}
}
inline void pull(int p) // 從底部往上, 把更新後的值往上拉 
{
	for (int h=1; p>1; p>>=1,h++) st[P(p)] = st[p] + st[A(p)] + (tag[P(p)]<<h);
}
inline void modify (int l, int r, int x)
{
	push(l+=n), push((r+=n)-1);
	for (int tl=l,tr=r,h=0; tl<tr; tl>>=1,tr>>=1,h++)
	{
		if (tl&1) upd(tl++, x, h);
		if (tr&1) upd(--tr, x, h);
	}
	pull(l), pull(r-1);
}
inline LL query (int l, int r)
{
	push(l+n), push(r+n-1);
	LL res = 0;
	for (l+=n,r+=n; l<r; l>>=1,r>>=1)
	{
		if (l&1) res += st[l++];
		if (r&1) res += st[--r];
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	build();
	
	cin >> m;
	for (int i=0,o,l,r,x; i<m; i++)
	{
		cin >> o >> l >> r;
		if (o==1) cin >> x, modify(l-1,r,x);
		else cout << query(l-1,r) << '\n';
	}
}
