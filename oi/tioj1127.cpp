#include <iostream>
using namespace std;
const int N = 42;

int dp[N][7], q;

inline void build()
{
	dp[1][3] = dp[1][0] = 1;
	for (int n=2; n<N; n++)
	{
		dp[n][0] = dp[n-1][7] + dp[n-1][1] + dp[n-1][4];
		dp[n][1] = dp[n-1][0] + dp[n-1][6];
		dp[n][2] = dp[n-1][5];
		dp[n][3] = dp[n-1][4];
		dp[n][4] = dp[n-1][0] + dp[n-1][3];
		dp[n][5] = dp[n-1][2];
		dp[n][6] = dp[n-1][1];
		dp[n][7] = dp[n-1][0];
	}
}

int main()
{
	build();
	while (cin >> q)
	{
		cout << dp[q][0] << '\n';
	}
}
