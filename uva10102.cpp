#include <iostream>
#include <cstring>
#define DE cout << " ::"
using namespace std;
const int N = 110, M = 1e5;

int colo[N][N], qx[M], qy[M], qd[M], f, r, res, n;
int used[N][N], u;
int fow[][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

inline bool can (int x, int y)
{
	return (0<=x&&x<n)&&(0<=y&&y<n)&&(used[x][y]<u);
}
void bfs (int rx, int ry)
{
	f=r=0;
	qx[r] = rx, qy[r] = ry, qd[r++] = 0;
	used[rx][ry] = u;
	while (f<r)
	{
		int ux=qx[f], uy=qy[f], d=qd[f++];
		if (colo[ux][uy] == 3)
		{
			res = max(res,d);
			return;
		}
		for (int i=0; i<4; i++)
		{
			int vx = ux+fow[i][0], vy = uy+fow[i][1];
			if (!can(vx,vy)) continue;
			used[vx][vy] = u;
			qx[r] = vx, qy[r] = vy, qd[r++] = d+1;
		}
	}
}
inline void init()
{
	memset(used,0,sizeof(used));
	u = 0, res = -1;
}

int main()
{
	while (cin >> n)
	{
		init();
		string s;
		for (int y=0; y<n; y++)
		{
			cin >> s;
			for (int x=0; x<n; x++)
				colo[x][y] = s[x]-'0';
		}
		
		for (int x=0; x<n; x++)
			for (int y=0; y<n; y++)
				if( colo[x][y] == 1)
					u++, bfs(x,y);
		cout << res << '\n';
	}
}
