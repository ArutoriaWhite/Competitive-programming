#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = 110;

int dp[N][N], fow[][2] = {{1,0},{-1,0},{0,1},{0,-1}}, h[N][N], mx, my, res;

inline bool can (int x, int y, int ph)
{
	return (0<=x&&x<mx)&&(0<=y&&y<my)&&(h[x][y]<ph);
}

int sol (int x, int y)
{
	if (dp[x][y] == -1)
	{
		dp[x][y] = 1;
		for (int i=0; i<4; i++)
		{
			int vx=x+fow[i][0], vy=y+fow[i][1];
			if (can(vx,vy,h[x][y]))
				dp[x][y] = max (dp[x][y], sol(vx,vy)+1);
		}
	}
	return dp[x][y];
}

int main()
{
	mem(dp,-1);
	cin >> my >> mx;
	for (int y=0; y<my; y++)
		for (int x=0; x<mx; x++)
			cin >> h[x][y];
	
	for (int x=0; x<mx; x++)
		for (int y=0; y<my; y++)
			res = max(res,sol(x,y));
	 cout << res << '\n';
}


