#include<iostream>
#include<unordered_set>
using namespace std;
const int N = 3000+10, M = 1e8;

int tow[][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int res[N], n, m, k;
bool used[N][N];
unordered_set<int> vis[N][N];
int qx[M], qy[M], qp[M], f, r;

inline bool out (int x, int y)
{
	return x<=0 || y<=0 || x>n || y>m;
}

inline void bfs()
{
	while (f<r)
	{
		int x = qx[f], y=qy[f], p=qp[f]; f++;
		used[x][y] = 1;
		res[p]++;
		
		for (int j=0; j<4; j++)
		{
			int vx = x+tow[j][0], vy = y+tow[j][1];
			if (out(vx,vy) || used[vx][vy]) continue;
			if (vis[vx][vy].count(p)) continue;
			vis[vx][vy].insert(p);
			qx[r] = vx, qy[r] = vy, qp[r] = p, r++;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	f=r=0;
	cin >> n >> m >> k;
	for (int i=1; i<=k; i++)
	{
		cin >> qx[r] >> qy[r];
		qp[r] = i;
		r++;
	}
	
	bfs();
	
	for (int i=1; i<=k; i++)
		cout << res[i] << '\n';
}
