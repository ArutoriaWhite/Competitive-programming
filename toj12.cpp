#include<iostream>
#define lowbit(x) (x&-x)
using namespace std;
const int N  = 3e3+10;

int BIT[N][N], mX, mY, q;

inline void add (int x, int y, int k)
{
	for ( ;y<=mY; y+=lowbit(y))
		for (int tx=x; tx<=mX; tx+=lowbit(tx))
			BIT[tx][y] += k;
}
inline int sum (int r, int d)
{
	int s = 0;
	for (int y=r; y>0; y-=lowbit(y))
		for (int tx=d; tx>0; tx-=lowbit(tx))
			s += BIT[y][tx];
	return s;
}
inline int query (int l, int r, int u, int d)
{
	return sum(r,d) - sum(r,u-1) - sum(l-1,d) + sum(l-1,u-1);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> mY >> mX;
	for (int y=1,p; y<=mY; y++)
		for (int x=1; x<=mX; x++)
			cin >> p, add(x,y,p);
	
	cin >> q;
	while (q--)
	{
		char opr;
		cin >> opr;
		if (opr=='C')
		{
			int x, y, k;
			cin >> y >> x >> k;
			add(x,y,k-query(x,x,y,y));
		}
		else
		{
			int l, r, u, d;
			cin >> u >> l >> d >> r;
			cout << query(l,r,u,d) << '\n';
		}
	}
	return 0;
}
