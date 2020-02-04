#include <iostream>
using namespace std;
const int N = 25;

int sum[N][N], n, dp[N];

inline void gen()
{
	for (int y=2; y<=n; y++)
		sum[1][y] = sum[1][1]+y;
	for (int x=2,t[]={1,-1}; x<=n; x++)
		for (int y=1; y<=n; y++)
			sum[x][y] = ((sum[x-1][y]*17)%103)*t[(x+y)&1];
	for (int x=1; x<=n; x++)
		for (int y=1; y<=n; y++)
			sum[x][y] += sum[x][y-1];
}

inline int query (int x, int i, int j)
{
	return sum[x][j]-sum[x][i-1];
}

inline int mcs (int i, int j)
{
	for (int x=1; x<=n; x++)
		dp[x] = max(dp[x-1]+query(x,i,j), query(x,i,j));
	int res = -1e9;
	for (int x=1; x<=n; x++)
		res = max(dp[x],res);
	return res;
}

inline int max_matr()
{
	int res = -1e9;
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
			res = max(res, mcs(i,j));
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> sum[1][1])
	{
		gen();
		cout << max_matr() << '\n';
	}
}

