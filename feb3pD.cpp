#include <iostream>
using namespace std;
typedef long long LL;

LL k, ql, qr, n;

inline LL query (LL l, LL r, LL k)
{
	if (ql<=l && r<=qr) return k;
	if (r<ql ||
}
inline LL qpow (LL x, LL y)
{
	for (LL res=1,t[]={1,x}; y>=0; res*=t[y&1],t[1]*=t[1],y>>=1)
		if (y==0) return res;
}

int main ()
{
	cin >> k >> l >> r;
	n = qpow(2,__lg(k)+1)-1;
	cout << query(l,r,k) << '\n';
}
