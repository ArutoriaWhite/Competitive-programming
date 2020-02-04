#include <iostream>
using namespace std;

long long f (int n)
{
	if (n==0) return 1;
	if (n<10) return n;
	return max(f(n/10)*(n%10), f(n/10-1)*9);
}

int main()
{
	int n;
	cin >> n;
	cout << f(n) << '\n';
}
