#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

string s[N];

int read (int &i) //in the beging i is new,  in the end i == the last char has been read
{
	if (s[i][0]=='f')
	{
		int x = read(++i);
		return 2*x-3;
	}
	else if (s[i][0]=='g')
	{
		int x = read(++i);
		int y = read(++i);
		return 2*x + y - 7;
	}
	else if (s[i][0]=='h')
	{
		int x = read(++i);
		int y = read(++i);
		int z = read(++i);
		return 3*x - 2*y + z;
	}
	else
		return atoi(s[i].c_str());
	}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int i = 0;
	while (cin >> s[i]) i++;
	cout << read(i=0) << '\n';
}
