#include<iostream>
using namespace std;

int ouo[200], r;

inline void print()
{
	for (int i=0; i<r; i++)
		cout << " ::" << ouo[i];
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int T;
	cin >> T;
	getline(cin,s);
	while (T--)
	{
		getline(cin,s);
		bool flag=1;
		r=0;
		for (int i=0; i<s.size(); i++)
		{
			if (s[i] == '(')
			{
				ouo[r++] = 1;
			}
			else if (s[i] == '[')
			{
				ouo[r++] = 2;
			}
			else if (s[i] == ')')
			{
				if(r>0 && ouo[r-1]==1)
				{
					
					r--;
				}
				else
				{
					flag=0;
					break;
				}
			}
			else if (s[i] == ']')
			{
				if (r>0 && ouo[r-1] == 2)
				{
					r--;
				}
				else
				{
					flag=0;
					break;
				}
			}
		}
		if (r==0 && flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
