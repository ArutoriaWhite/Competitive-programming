#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
#define maxN 1000

struct area
{
	int u, d, r, l;
};

struct point
{
	int x, y;
};

int to[maxN];
point icons[maxN], mous[maxN];
area wins[maxN];
int ri, rm, rw;

inline bool inArea( area a, point p)
{
	return (a.l<=p.x && p.x<=a.r)&&(a.d<=p.y & p.y<=a.u);
}
inline double dis( point pa, point pb)
{
	int m = (pa.x-pb.x), n = (pa.y-pb.y);
	return sqrt(m*m+n*n);
}

int main()
{
	char t;
	ri = rm = rw = 0;
	while (cin >> t)
	{
		if (t=='#') break;
		if (t=='I')
		{
			int tx, ty;
			cin >> tx >> ty;
			icons[ri++] = point{tx,ty};
		}
		else if (t=='R')
		{
			int l, d, r, u;
			cin >> l >> d >> r >> u;
			wins[rw++] = area{u,d,r,l};
		}
		else
		{
			int x, y;
			cin >> x >> y;
			mous[rm++] = point{x,y};
		}
	}
	for (int i=0; i<ri; i++)
		to[i] = i+1;
	for (int i=0,j=to[i]; j!=0; i=j,j=to[j])
	{
		for (int k=0; k<rw; k++)
		{
			if (inArea(wins[k],icons[j-1]))
			{
				to[i] = to[j];
			}
		}
	}

	for (int i=0; i<rm; i++)
	{
		bool flag=1;
		for (int j=0; j<rw&&flag; j++)
		{
			if ( inArea(wins[j],mous[i]))
			{
				flag=0;
				cout << (char)('A'+i) << '\n';
			}
		}
		if (flag)
		{
			double mindis=0x3f3f3f3f;
			int ans[50], r=0;
			for (int k=to[0]; k!=0; k=to[k])
			{
				double d = dis(mous[i],icons[k-1]);
				if (d<mindis)
				{
					mindis = d;
					r=0;
					ans[r++] = k;
				}
				else if (abs(mindis-d)<1e-6)
				{
					ans[r++] = k;
				}
			}

			for (int j=0; j<r; j++)
				cout << setw(3) << ans[j];
			cout << '\n';
		}
	}
}




