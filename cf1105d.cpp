#include <bits/stdc++.h>
using namespace std;
const int M = 1e7, N = 1e3+10;

struct ele {int x, y, colo, d;};
ele q[M];
int mX, mY, p, s[10], sc[10], vis[N][N], f, r;
int tow[][2] = { {-1,0}, {1,0}, {0,1}, {0,-1}};

void expand (const ele);

// debug
template <typename T>
void DE (initializer_list<T> args)
{
	cout << ":: ";
	for (auto x: args)
		cout << setw(3) << x;
	cout << '\n';
}
void expand_test()
{
	int c, x, y;
	DE({"mx","my","c","x","y","s"});
	cin >> mX >> mY >> c >> x >> y >> s[c];
	expand({x,y,c,0});
}

inline bool cmp (const ele &a, const ele &b)
{
	return a.colo<b.colo;
}
inline bool can (int x, int y, int c)
{
	return 0<=x&&x<mX && 0<=y&&y<mY && (vis[x][y]==c || vis[x][y]==0);
}
void expand (const ele rt)
{
	queue<ele> qe;
	qe.push(rt), vis[rt.x][rt.y] = rt.colo, sc[rt.colo]++;
	while (!qe.empty())
	{
		int x=qe.front().x, y=qe.front().y;
		int c=qe.front().colo, d=qe.front().d;
		qe.pop();
		sc[c]++;
		DE({x,y,c,d});
		if (d == s[c])
		{
			DE({"jumped"});
			q[r++] = {x,y,c,0};
			continue;
		}
		qe.pop();
		for (int i=0; i<4; i++)
		{
			int vx=x+tow[i][0], vy=y+tow[i][1];
			qe.push( {vx,vy,c,d+1} );
			vis[vx][vy] = c;
		}
	}
}
void bfs ()
{
	while (f<r)
		expand(q[f++]);
}

int main()
{
	expand_test();
	cin >> mY >> mX >> p;
	for (int i=1; i<=p; i++)
		cin >> s[i];
	char c;
	for (int y=0; y<mY; y++)
	{
		for (int x=0; x<mX; x++)
		{
			cin >> c;
			vis[x][y] = (c=='#'? -1:0);
			if ('0'<=c&&c<='9') q[r++] = {x,y,c-'0'};
		}
	}
	sort(q,q+r,cmp);
	bfs();
	for (int i=1; i<=p; i++)
		cout << sc[i] << "\n "[i+1<=p];
}
