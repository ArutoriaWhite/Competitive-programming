#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		double res = 0;
		for (int i=1; i<=n; i++)
			res += log10(i);
		cout << (int)(res)+1 << '\n';
	}
}
