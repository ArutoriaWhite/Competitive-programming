#include<iostream>
using namespace std;

string keyboard = "=-0987654321`\\][POIUYTREWQ';LKJHGFDSA/.,MNBVCXZ";

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while (getline(cin,s))
	{
		for (int i=0,len=s.size(); i<len; i++)
		{
			bool flg=1;
			for (int j=0,len_k=keyboard.size(); j<len_k&&flg; j++)
			{
				if (keyboard[j]==s[i])
				{
					cout << keyboard[j+1];
					flg=0;
				}
			}
			if (flg)
			{
				cout << s[i];
			}
		}
		cout << '\n';
	}
}
