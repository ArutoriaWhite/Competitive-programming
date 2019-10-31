#include<iostream>
using namespace std;

int main()
{
	string sub, s;
	while (cin >> sub >> s)
	{
		int lsub=sub.size(), len=s.size(), i=0;
		for (int j=0; j<len&&i<lsub; j++)
		{
			if (s[j]==sub[i])
			{
				i++;
			}
		}
		
		if (i<lsub)
		{
			cout << "No\n";
		}
		else
		{
			cout << "Yes\n";
		}
	}
}
