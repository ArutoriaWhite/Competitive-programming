#include <iostream>
using namespace std;

int n, res;
string s;

int main()
{
	cin >> n >> s, s+='0';
	for (int i=0,a=0; i<=n; i++)
	{
		if (s[i]=='0') res*=10, res += a, a=0;
		else a++;
	}
	cout << res << '\n';
}
