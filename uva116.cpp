#include<iostream>
using namespace std;
#define DE cout << " ::"
int const maxM = 12, maxN = 110;

int n, m, t, used[maxM][maxN], w[maxM][maxN], dp[maxM][maxN];

int f (int x, int y)
{
	if (x==m)
		return 0;
	if (used[x][y]<t)
	{
		used[x][y] = t;
		int u = f(x+1,(y-1+n)%n), mid = f(x+1,y), d = f(x+1,(y+1)%n);
		dp[x][y] = min(min(u,d),mid) + w[x][y];
	}
	return dp[x][y];
}

int main()
{
	while (cin >> n >> m)
	{
		t++;
		for (int y=0; y<n; y++)
			for (int x=0; x<m; x++)
				cin >> w[x][y];
		
		int res = 1e9;
		for (int y=0; y<n; y++)
			res = min(res,f(0,y));
		DE << res << '\n';
			
	}
}
