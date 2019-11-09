#include<iostream>
using namespace std;

int main()
{
	int n, a;
	while (cin >> n)
	{
		if (n==0) return 0;
		if (n&1) a=n>>1;
		else a=n>>1-1;
		cout << ((((1+n-2)*(n-2))>>1) - a)/6 << '\n';
	}

}
