#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define isUp(c) ('A'<=c&&c<='Z')
#define isLow(c) ('a'<=c&&c<='z')
#define (c) ('0'<=c&&c<='9')
using namespace std;
typedef map<string,int> msi;
const int INF=0x7f7f7f7f;

string s;
int i, n;

inline string read_ch()
{
	string res;
	res += s[i];
	if (isLow(s[i+1])) i++, res+=s[i];
	return res;
}
inline int read_num()
{
	int res = 0;
	for (i++; i<n && isNum(s[i]); res*=10,res+=s[i]-'0',i++);
	i--;
	return max(res,1);
}

msi read_block()
{
	msi res;
	for ( ; i<n && s[i]!=')'; i++)
	{
		if (isUp(s[i]))
		{
			string ch = read_ch();
			int cnt = read_num();
			res[ch] += cnt;
		}
		else if (s[i] == '(')
		{
			i++;
			msi m = read_block();
			int x = read_num();
			for (auto kvp: m)
				res[get<0>(kvp)] += get<1>(kvp)*x;
		}
	}
	return res;
}

int main()
{
	akiyama;
	cin >> s, n=s.size();
	cout << s << '\n';
	msi res = read_block();
	for (auto kvp: res)
	{
		cout << get<0>(kvp) << ':' << get<1>(kvp) << '\n';
	}
}
