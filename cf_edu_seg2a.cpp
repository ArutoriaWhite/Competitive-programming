#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define print(x) cout << #x << ' ' << x.l << ' ' << x.m << ' ' << x.r << ' ' << x.sum << '\n'
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int n, m;
struct Node {int l=0,m=0,r=0,sum=0;} st[N<<1];

inline Node newNode (int x)
{
	if (x<0) return {0,0,0,x};
	else return {x,x,x,x};
}
inline Node merge (Node a, Node b)
{
	Node res;
	res.sum = a.sum + b.sum;
	res.l = max(a.l, a.sum+b.l);
	res.r = max(b.r, b.sum+a.r);
	res.m = max(res.l, max(res.r, max(a.m, max(b.m, a.r+b.l))));
	return res;
}
inline void build ()
{
	for (int i=0,a; i<n; i++)
		cin >> a, st[i+n]=newNode(a);
	for (int i=n-1; i; i--) st[i]=merge(st[i<<1],st[i<<1|1]);
}
inline void setto (int p, int x)
{
	for (st[p+=n]=newNode(x); p>1; p>>=1)
	{
		int l = min(p,p^1), r = max(p,p^1);
		st[p>>1] = merge(st[l], st[r]);
	}
}
inline Node query ()
{
	 Node L, R;
	 for (int l=n,r=2*n; l<r; l>>=1,r>>=1)
	 {
		 if (l&1) L = merge(L,st[l++]);
		 if (r&1) R = merge(st[--r],R);
	 }
	 return merge(L,R);
}

signed main()
{
	XinAi
	cin >> n >> m;
	build();
	cout << query().m << '\n';
	for (int i=0,p,x; i<m; i++)
	{
		cin >> p >> x;
		setto(p,x);
		cout << query().m << '\n';
	}
}
