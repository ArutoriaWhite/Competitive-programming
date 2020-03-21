#include <bits/stdc++.h>
using namespace std;

inline long long fac (int x)
{
	long long res = 1;
	for (int i=1; i<=x; i++)
	{
		res *= i; 
	}
	return res;
}
int main()
{
	long long n, k;
	while (cin >> k >> n)
	{
		long long c = fac(n*k)/fac(n)/fac(n*k-n);
		cout << c/((k-1)*n+1) << '\n';
	}
}
