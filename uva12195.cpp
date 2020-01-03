#include<iostream>
using namespace std;

int mp[300];

int main()
{
	mp['W']=64, mp['H']=32, mp['Q']=16;
	mp['E']=8, mp['S']=4, mp['T']=2, mp['X']=1;
	
	string s;
	while (cin >> s)
	{
		if (s=="*") break;
		
		int res=0, sum=0;
		for (int i=1; i<s.size(); i++)
		{
			if (s[i]=='/')
			{
				if (sum==64)
					res++;
				sum=0;
			}
			else
				sum += mp[s[i]];
		}
		cout << res << '\n';
	}
}
