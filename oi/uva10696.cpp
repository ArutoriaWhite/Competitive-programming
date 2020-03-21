#include<iostream>
using namespace std;
#define maxN 100000

int dp[maxN];

int f( int n)
{
	if (n<=100)
	{
		if (dp[n]==0)
			dp[n] = f(f(n+11));
		return dp[n];
	}
	else return n-10;
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n==0) return 0;
		cout << "f91(" << n << ")" << " = " << f(n) << '\n';
	}
}
