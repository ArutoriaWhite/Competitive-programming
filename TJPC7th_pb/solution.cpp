#include <iostream>
using namespace std;

int main ()
{
	int n;
	long long k;
	cin >> n >> k;
	for (int i=1; i<=n; i++)
	{
		long long x;
		cin >> x;
		x = (x+10)*2*(x+10)*2;
		if (x > k)
		{
			cout << "BURST!!!" << '\n';
			break;
		}
		else cout << x << '\n';
	}
}