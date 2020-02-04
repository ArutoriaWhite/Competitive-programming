#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int res=0;
	for (long long i=1; i<=n; i++)
		for (long long j=i; j<=n; j++)
		{
			double c = sqrt(i*i+j*j);
			if (i+j>c && c<=n && (int)c == c)
				res++;
		}
	cout << res << '\n';
}

