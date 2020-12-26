#include <bits/stdc++.h>
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int M = 34943;

int num;

signed main()
{
	XinAi
	string s;
	while (getline(cin,s), s!="#")
	{
		if (s == "")
		{
			cout << "00 00\n";
			continue;
		}
		num=0;
		int n = s.size();
		for (int i=0; i<n; i++)
		{
			num <<= 8;
			num += s[i];
			num %= M;
		}
		num <<= 8;
		num %=M;
		num <<= 8;
		num %=M;
		int i = M-num;
		cout << setw(2) << setfill('0') << uppercase << hex << (i>>8) << ' ' << setw(2) << setfill('0') << i-((i>>8)<<8) << '\n';
	}
}
