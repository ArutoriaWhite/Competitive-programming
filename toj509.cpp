#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define mem(a,x) memset(a,x,sizeof(a))
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << '\n'
typedef long long ll;
using namespace std;

int templ[20][20], colo[20][20], nx1, nx2, my=15, mx=6, res=0;
int vis[20][20], u, tow[][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void print();

inline bool fall()
{
	bool flag=0;
	for (int x=1; x<=mx; x++)
		for (int y=2,ky; y<=my; y++)
		{
			for (ky=y; ky>=2&&colo[x][ky-1]==0; ky--);
			swap(colo[x][y], colo[x][ky]);
			flag |= (ky!=y);
		}
	return flag;
}

inline bool can (int x, int y, int uc)
{
	return (1<=x&&x<=mx) && (1<=y) && (colo[x][y]==uc) && (vis[x][y]<u);
}
int size (int x, int y)
{
	vis[x][y] = u;
	int res = 1;
	for (int i=0; i<4; i++)
	{
		int vx = x+tow[i][0], vy = y+tow[i][1];
		if (can(vx,vy,colo[x][y]))
			res += size(vx,vy);
	}
	return res;
}
void erase (int x, int y)
{
	vis[x][y] = u;
	for (int i=0; i<4; i++)
	{
		int vx = x+tow[i][0], vy = y+tow[i][1];
		if (can(vx,vy,colo[x][y])) erase(vx,vy);
	}
	colo[x][y] = 0;
}
inline bool clear()
{
	bool flag=0;
	for (int x=1; x<=mx; x++)
		for (int y=1; y<=my; y++)
			if (colo[x][y]!=0 && (++u) && size(x,y)>=4)
				flag=1, ++u, erase(x,y);
	return flag;
}

inline int run (int x1, int y1, int x2, int y2)
{
	memcpy(colo,templ,sizeof(colo));
	colo[x1][y1] = nx1, colo[x2][y2] = nx2;
	int comb = 0;
	for (fall(); clear(); fall()) comb++;
	return comb;
}

int main()
{
	akiyama;
	cin >> nx1, nx2=nx1%10, nx1/=10;
	char c;
	for (int y=12; y>=1; y--)
		for (int x=1; x<=6; x++)
			cin >> c, templ[x][y] = c-'0';
	for (int x=1; x<=mx; x++)
	{
		res = max(res, run(x,13,x,14));
		res = max(res, run(x,14,x,13));
	}
	for (int x=1; x<mx; x++)
	{
		res = max(res, run(x,13,x+1,13));
		res = max(res, run(x+1,13,x,13));
	}
	cout << res << '\n';
}
