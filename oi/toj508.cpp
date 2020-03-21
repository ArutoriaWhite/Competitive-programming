#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define INF = 0x7f
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define DE(x) cout << #x << '=' << x << '\n';
typedef long long ll;
using namespace std;
const int N = 1e3+10;

int dp[N][N], h[N][N], tow[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}, mx, my, res;

int sol (int x, int y)
{
	if (dp[x][y] == -1)
	{
		if (h[x][y] == 0) return 1;
		else
		{
			dp[x][y] = 0;
			for (int i=0; i<4; i++)
			{
				int vx = x+tow[i][0], vy = y+tow[i][1];
				if (0<=vx&&vx<mx && 0<=vy&&vy<my && (h[vx][vy] == h[x][y]-1))
					dp[x][y] += sol(vx,vy);		
			}
		}
	}
	return dp[x][y];
}

int main()
{
	akiyama;
	mem(dp,-1);
	cin >> my >> mx;

	char c;
	for (int y=0; y<my; y++)
		for (int x=0; x<mx; x++)
			cin >> c, h[x][y] = c-'0';
	for (int x=0; x<mx; x++)
		for (int y=0; y<my; y++)
			if (h[x][y] == 9)
				res += sol(x,y);
	cout << res << '\n';
}
