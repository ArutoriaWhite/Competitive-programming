#include<iostream>
using namespace std;

int main()
{
	int g, k;
	string s;
	while (cin >> g)
	{
		if (g==0) return 0;

		cin >> s;
		k = s.size()/g;
		
		for (int len=s.size(),i=k; i<=len; i+=k)
		{
			for (int j=i-1; j>=i-k; j--)
			{
				cout << s[j];
			}
		}
		cout << '\n';
	}
}
