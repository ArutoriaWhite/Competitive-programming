#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	while (getline(cin,s))
	{
		int a=0;
		for (int i=0; i<s.size(); i++)
		{
			if ('0'<=s[i]&&s[i]<='9')
				a+=s[i]-'0';
			else if (s[i]=='!')
				cout << '\n';
			else
			{
				if (s[i]=='b') s[i]=' ';
				for (int j=0; j<a; j++)
					cout << s[i];
				a=0;
			}
		}
		cout << '\n';
	}
}
