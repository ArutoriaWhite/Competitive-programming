#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		cout << "Case " << t << ": ";
		
		string s;
		cin >> s;
		char pre;
		for (int i=0,len=s.size(); i<len; i++)
		{
			if ('A'<=s[i]&&s[i]<='Z')
			{
				pre = s[i];
			}
			else
			{
				int n, j;
				for (n=0,j=i; '0'<=s[j]&&s[j]<='9'; j++)
				{
					n*=10;
					n+=s[j]-'0';
				}
				for (int k=0; k<n; k++)
				{
					cout << pre;
				}
				i=j-1;
			}
		}
		cout << '\n';
	}
	return 0;
}

