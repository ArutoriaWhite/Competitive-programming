#include<iostream>
using namespace std;
const int N = 1e6, M = 1000000007;

int dp[N][3][2], n;

inline void init()
{
	n=1;
	for (int i=0; i<3; i++)
		for (int j=0; j<2; j++)
			dp[0][i][j] = 1;
}

int f (int q)
{
	while (n<=q)
	{
		int (*pre)[2] = dp[n-1], (*res)[2] = dp[n++];
		res[0][0] = ((pre[0][0] + pre[1][0])%M + pre[0][1])%M;
		res[1][0] = ((pre[0][0] + pre[2][0])%M + pre[0][1])%M;
		res[2][0] = (pre[0][0] + pre[0][1])%M;
		
		res[0][1] = (pre[0][1] + pre[1][1])%M;
		res[1][1] = (pre[0][1] + pre[2][1])%M;
		res[2][1] = pre[0][1];
	}
	return dp[q][0][0];
}

int main()
{
	init();
	int n;
	while (cin >> n)
	{
		cout << f(n) << '\n';
	}
}
