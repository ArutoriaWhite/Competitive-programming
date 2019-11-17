#include<iostream>
using namespace std;
#define maxN (100000+10)
#define L(x) (x<<1)
#define R(x) ((x<<1)|1)

//st
int l[maxN], r[maxN], val[maxN];

inline void pull( int x)
{
	val = min(val[L(x)],val[R(x)];
}

inline void build( int i, int al, int ar)
{
	l[i] = al, r[i] = ar;
	if (l==r)
	{
		cin >> val[i];
	}
	else
	{
		int m = (l+r)>>1;
		build(L(x),l,m);
		build(R(x),m+1,r);
		pull(i);
	}
}

inline void query( int i, int al, int ar)
{
	if (al<=l[i] && r[i]<=ar) return val[i];
	int m = (l[i]+r[i])>>1;
	if (al
}

