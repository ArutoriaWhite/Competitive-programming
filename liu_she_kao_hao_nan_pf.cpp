#include<iostream>
using namespace std;
const int N = 3e3+10, M = 1e8;

int n, m, k, res[N];
int dep[N][N], las[N][N], tow[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int qx[M], qy[M], qp[M], f, r;

inline bool out (int x,int y)
{
	return x<=0 || y<=0 || x>n || y>m;
}	

inline void bfs()
{
	while (f<r)
	{
		int x=qx[f], y=qy[f], p=qp[f], d=dep[x][y]; f++;
		res[p]++;
		
		for (int i=0; i<4; i++)
		{
			int vx=x+tow[i][0], vy=y+tow[i][1], vd=d+1;
			if (!out(vx,vy) && (dep[vx][vy]==0 || (dep[vx][vy]==vd&&las[vx][vy]!=p)))
			{
				dep[vx][vy] = vd;
				las[vx][vy] = p;
				qx[r] = vx, qy[r] = vy, qp[r] = p, r++;		
			}
		}
	}
}

int main()
{
	f=r=0;
	cin >> n >> m >> k;
	for (int i=1; i<=k; i++)
	{
		cin >> qx[r] >> qy[r];
		qp[r] = i;
		dep [qx[r]][qy[r]] = 1;
		r++;
	}
	
	bfs();
	
	for (int i=1; i<=k; i++)
		cout << res[i] << '\n';
}
