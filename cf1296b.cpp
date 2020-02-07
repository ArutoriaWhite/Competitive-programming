#include <iostream>
using namespace std;
const double M = 1.11111111111;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		double x;
		cin >> x;
		cout << (int)(x*M) << '\n';
	}
}
