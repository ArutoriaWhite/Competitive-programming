#include <iostream>
#define int long long
using namespace std;

string arr[110];
int n;

inline int fac (int x)
{
	return x*(x-1);
}

signed main()
{
	cin >> n;
	for (int y=0; y<n; y++)
		cin >> arr[y];

	int res=0;
	for (int x=0; x<n; x++)
	{
		int a=0;
		for (int y=0; y<n; y++)
			if (arr[y][x]=='C')
				a++;
		if (a>1) res += fac(a)/2;
	}
	for (int y=0; y<n; y++)
	{
		int a=0;
		for (int x=0; x<n; x++)
			if (arr[y][x]=='C')
				a++;
		if (a>1) res += fac(a)/2;
	}
	cout << res << '\n';
}
