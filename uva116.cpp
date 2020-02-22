#include <iostream>
#include <cstring>
using namespace std;
const int N = 110, M = 20;

int dp[N][M], w[N][M], from[N][M], mx, my;
int minv, minw, miny;

inline void solv()
{
	memset(dp,0,sizeof(dp));
	for (int y=0; y<my; y++)
		dp[mx-1][y] = w[mx-1][y];
	for (int x=mx-1; x>=0; x--)
		for (int y=0; y<my; y++)
		{
			dp[x][y] = 1e9;
			for (int k=-1; k<=1; k++)
			{
				int vy = (y+k+my)%my;
				if (dp[x+1][vy]<dp[x][y])
				{
					from[x][y] = vy;
					dp[x][y] = dp[x+1][vy];
				}
				else if (dp[x+1][vy] == dp[x][y])
					if (from[x][y] > vy) from[x][y] = vy;
			}
			dp[x][y] += w[x][y];
		}
}

inline void print_dp()
{
	for (int y=0; y<my; y++)
		for (int x=0; x<mx; x++)
			cout << "::" << dp[x][y] << "\n "[x+1<mx];
}

int main()
{
	while (cin >> my >> mx)
	{
		for (int y=0; y<my; y++)
			for (int x=0; x<mx; x++)
				cin >> w[x][y];
		solv();
		minv = 1e9, miny=1e9;
		for (int y=0; y<my; y++)
			if (dp[0][y] < minv)
				minv = dp[0][y], miny=y;
		for (int x=0; x<mx; miny = from[x][miny], x++)
			cout << miny+1 << "\n "[x+1<mx];
		cout << minv << '\n';
	}
}
