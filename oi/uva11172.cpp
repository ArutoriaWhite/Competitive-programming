#include <iostream>
using namespace std;

int a, b, T;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		if (a>b) cout << ">\n";
		else if (a<b) cout << "<\n";
		else if (a==b) cout << "=\n";
	}
}

