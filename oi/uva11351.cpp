#include<iostream>
using namespace std;

int f (int n, int k)
{
	if (n==1) return 0;
	else return ((k-1)%n+f(n-1,k)+1)%n;
}

int main()
{
	int T;
	cin >> T;
	for (int i=1; i<=T; i++)
	{
		int n, k;
		cin >> n >> k;
		cout << "Case " << i << ": " << f(n,k)+1 << "\n";
	}
}
