#include<iostream>
#include<string.h>
using namespace std;
#define maxN 30
#define ti(x) (x-'a'+1)

int to[maxN], pre[maxN];

int main()
{
	string s;
	while (getline(cin,s))
	{
		memset(to,0,sizeof(to));
		memset(pre,0,sizeof(pre));
		int j=0;
		for (int i=0,len=s.size(); i<len; i+=2)
		{
			to[j] = ti(s[i]);
			j = to[j];
		}
		getline(cin,s);
		for (int i=0,len=s.size(); i<len; i+=4)
		{
			int a=ti(s[i]), b=ti(s[i+3]);
			pre[b] |= (1<<a);
		}

		char a, b;
		while (cin >> a >> b)
		{
			cout << (pre[ti(b)])&(1<<a) << '\n';
		}
	}

}
