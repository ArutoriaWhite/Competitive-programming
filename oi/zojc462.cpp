#include<iostream>
#include<algorithm>
using namespace std;
#define maxN 100010
#define DE cout << " ::"

string s;
bool up[maxN];
int len, k;

int main() {
	
	cin >> k >> s;
	len = s.size();
	for( int i=0; i<len; i++)
	{
		up[i] = ('A'<=s[i]&&s[i]<='Z');
	}
	
	int mxs=0, pos=0;
	for( int i=0; i<len; i++)
	{
		bool flag=1;
		int u=up[i], s=0, tmp;
		while (flag)
		{
			int j;
			for( j=i; j<i+k; j++)
			{
				if (up[j]!=u || j>=len)
				{
					flag=0;
					break;
				}
			}
			if (flag)
			{
				s+=k;
				u=!u;
				i=j;
			}
		}
		DE << i << ' ' << s << '\n';
		if (s>mxs)
		{
			mxs = s;
			pos = i;
		}
	}
	cout << mxs << '\n';
	DE << pos;
	return 0;
}
