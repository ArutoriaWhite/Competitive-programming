#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define fi first
#define se second
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
const int INF=0x7f7f7f7f, MIN = 0xc0c0c0c0, N = 8;

Pii from[N][N];
int dep[N][N], rx, ry, tx, ty, r;
queue<Pii> q;
map<Pii,string> s;
string res[100];

int bfs()
{
	q.push({rx,ry});
	dep[rx][ry] = 0;
	while (!q.empty())
	{
		int x = q.front().fi, y = q.front().se;
		q.pop();
		if (x==tx && y==ty)
			return dep[x][y];
		for (int i=-1; i<=1; i++)
			for (int j=-1; j<=1; j++)
				if (i || j)
				{
					int vx=x+i, vy=y+j;
					if (vx<0 || vy<0 || vx>=N || vy>=N || dep[vx][vy] >= 0) continue;
					from[vx][vy] = {x,y};
					dep[vx][vy] = dep[x][y] + 1;
					q.push({vx,vy});
				}
	}
	return 0;
}
int main()
{
	akiyama;
	char c1, c2, c3, c4;
	cin >> c1 >> c2 >> c3 >> c4;
	rx = c1-'a', ry = c2-'1', tx = c3-'a', ty = c4-'1';
	mem(dep,-1);
	mem(from,-1);
	cout << bfs() << '\n';
	s[{-1,0}]="L", s[{1,0}]="R", s[{0,1}]="U", s[{0,-1}]="D";
	s[{-1,1}]="LU", s[{-1,-1}]="LD", s[{1,1}]="RU", s[{1,-1}]="RD";
	for (int x=tx,y=ty,fx,fy; x!=rx||y!=ry; x=fx,y=fy)
	{
		fx = from[x][y].fi, fy = from[x][y].se;
		res[r++] = s[{x-fx,y-fy}];
	}
	for (int i=r-1; i>=0; i--)
		cout << res[i] << '\n';
}

