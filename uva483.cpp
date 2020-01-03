#include<iostream>
using namespace std;

string p;
inline void print()
{
	for (int i=p.size()-1; i>=0; i--)
		cout << p[i];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	while (getline(cin,s))
	{
		p="";
		for (int i=0; i<=s.size(); i++)
		{
			if (i==s.size())
			{
				print();
				cout << '\n';
				break;
			}
			else if (s[i] == ' ')
			{
				print();
				cout << ' ';
				p="";
			}
			else
				p += s[i];
		}
	}
}
