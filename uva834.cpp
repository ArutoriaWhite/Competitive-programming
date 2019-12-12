#include<iostream>
using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		int cnt=0;
		while (b!=0)
		{
			if (cnt == 0) cout << '[';
			else if (cnt==1) cout << ';';
			else cout << ',';
			cout << (a/b);
			int tmp = a;
			a = b;
			b = tmp%b;
			cnt++;
		}
		cout << "]\n";
	}
}
