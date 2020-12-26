#include <iostream>
using namespace std;

int t, n;
int star[1000], blank[1000];

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i=1; i<1000; i++)
			blank[i] = 1e9, star[i] = -1e9;
		for (int i=1, b=n-1, s=1; b>=0; i++, b--, s+=2)
		{
			blank[i] = b;
			star[i] = s;
		}
		for (int i=2*n-3, b=n-1, s=1; b>=0; i--, b--, s+=2)
		{
			blank[i] = min(blank[i], b);
			star[i] = max(star[i], s);
		}
		for (int i=1; i<=2*n-3; i++)
		{
			for (int j=1; j<=blank[i]; j++) cout << ' ';
			for (int j=1; j<=star[i]; j++) cout << '*';
			cout << '\n';
		}
	}
}