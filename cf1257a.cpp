#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		cout << min(n-1,abs(a-b)+x) << '\n';
	}
}
