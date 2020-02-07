#include <iostream>
using namespace std;
typedef long long LL;

LL k, ql, qr, n;

inline LL qpow (LL x, LL y)
{
	for (LL res=1, t[]={1,x}; y>=0; res*=t[y&1],t[1]*=t[1],y>>=1)
		if (y==0) return res;
}
inline LL query (LL l, LL r, LL k)
{
	if (ql<=l&&r<=qr) return k;
	else if (qr<l || r<ql) return 0;
	LL m = (l+r)>>1;
	return query(l,m-1,k>>1) + query(m+1,r,k>>1) + (k&1)*(ql<=m&&m<=qr);
}

int main()
{
	cin >> k >> ql >> qr;
	n = qpow(2,__lg(k)+1)-1;
	cout << query(1,n,k) << '\n';
}
