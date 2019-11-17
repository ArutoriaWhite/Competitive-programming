#include<iostream>
using namespace std;
#define maxN (1000000+10)
#define L(x) (x<<1)
#define R(x) ((x<<1)|1)

//st
int l[maxN], r[maxN], val[maxN];

inline void pull( int x)
{
	val[x] = min(val[L(x)],val[R(x)]);
}

inline void build( int i, int al, int ar)
{
	l[i] = al, r[i] = ar;
	if (l[i]==r[i])
	{
		cin >> val[i];
	}
	else
	{
		int m = (l[i]+r[i])>>1;
		build(L(i),l[i],m);
		build(R(i),m+1,r[i]);
		pull(i);
	}
}

inline int query( int i, int ql, int qr)
{
	if (ql<=l[i] && r[i]<=qr) return val[i];

	int m = (l[i]+r[i])>>1, res = 1e9;
	if (ql<=m) res = min( query(L(i),ql,qr), res);
	if (qr>m)  res = min( query(R(i),ql,qr), res);
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	build(1,1,n);
	for (int i=0; i<n; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << query(1,l,r)+1 << '\n';
	}
}

