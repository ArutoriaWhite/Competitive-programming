#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> Pii;
const int N = 30;

char G[N][N];
string res, s[N][N];
int mx, my, vis[N][N], vis2[N][N], tow[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void upd (string &a, string &b)
{
	if (b.size() < a.size()) return;
	if (a.size() < b.size())
	{
		a = b;
		return;
	}
	for (int i=a.size()-1; i>=0; i--)
	{
		if (a[i] < b[i])
		{
			a = b;
			return;
		}
		if (a[i] > b[i]) return;
	}
}
bool forb (int x, int y)
{
	return (x>mx || x<1 || y>my || y<1 || G[x][y]=='#');
}
int valu (int rx, int ry)
{
	memcpy(vis2,vis,sizeof(vis));
	queue<int> qx, qy;
	qx.push(rx), qy.push(ry);
	int ans=0;
	while (!qx.empty())
	{
		int x = qx.front();
		int y = qy.front();
		qx.pop(), qy.pop();
		ans++;
		for (int i=0; i<4; i++)
		{
			int vx = x+tow[i][0];
			int vy = y+tow[i][1];
			if (forb(vx,vy) || vis2[vx][vy]) continue;
			vis2[vx][vy] = 1;
			qx.push(vx);
			qy.push(vy);
		}
	}
	return ans;
}
void dfs (int x, int y, int rx, int ry, int d)
{
	s[x][y] = "";
	int v = valu(x,y);
	if (v+d < res.size()) return;
	if (v+d == res.size() && G[rx][ry]<res.back()) return;
	vis[x][y] = 1;
	for (int i=0; i<4; i++)
	{
		int vx = x+tow[i][0], vy = y+tow[i][1];
		if (forb(vx,vy) || vis[vx][vy]) continue;
		dfs(vx,vy,rx,ry,d+1);
		upd(s[x][y],s[vx][vy]);
	}
	vis[x][y] = 0;
	s[x][y] += G[x][y];
	upd(res,s[x][y]);
}

int main()
{
	Eriri
	while (cin >> my >> mx && (my||mx))
	{
		res = "";
		for (int y=1; y<=my; y++)
			for (int x=1; x<=mx; x++)
				cin >> G[x][y];
		for (int x=1; x<=mx; x++)
			for (int y=1; y<=my; y++)
				if (!forb(x,y))
					dfs(x,y,x,y,0);
		for (int i=res.size()-1; i>=0; i--)
			cout << res[i];
		cout << '\n';
	}
}
