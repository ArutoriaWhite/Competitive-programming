#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define exi(x,s) (s.find(x)!=s.end())
#define fi first
#define se second
#define Uset unordered_set
#define Umap unordered_map
#define int long long
#define Pq priority_queue
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0;
const int N = 110;

int a[N][N], mx, my, rx, ry;
int vis[N][N], res, fow[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
queue<int> qx, qy;

void dfs (int x, int y)
{
	res += a[x][y];
	vis[x][y] = 1;
	int vx=-1, vy=-1, l = INF;
	for (int i=0; i<4; i++)
	{
		int tx = x+fow[i][0], ty = y+fow[i][1];
		if (1<=tx&&tx<=mx && 1<=ty&&ty<=my)
			if (!vis[tx][ty] && a[tx][ty] < l)
				l = a[tx][ty], vx = tx, vy = ty;
	}
	if (vx>0 && vy>0)
		dfs(vx,vy);
}

signed main()
{
	// s
	cin >> my >> mx;
	for (int y=1; y<=my; y++)
		for (int x=1; x<=mx; x++)
			cin >> a[x][y];
	int low = INF;
	for (int y=1; y<=my; y++)
		for (int x=1; x<=mx; x++)
			if (a[x][y] < low)
			{
				low = a[x][y];
				rx = x, ry = y;
			}
	dfs(rx,ry);
	cout << res << '\n';
}
