#include<iostream>
using namespace std;
#define int long long 

int ctoi( char c)
{
	if ('0'<=c&&c<='9') return c-'0';
	else return c-'A'+10;
}

int stoi( string s, int n)
{
	int res = 0;
	for (int i=0; i<s.size(); i++)
	{
		if (i==0 && s[0]=='0' && s[1]=='x') i+=2;
		res *= n, res += ctoi(s[i]);
	}
	return res;
}

char itoc( int n)
{
	if (0<=n&&n<=9) return '0'+n;
	else return (n-10+'A');
}

string rev;
void itos( int n, int k)
{
	if (n==0)
	{
		rev = "0";
		return;
	}
	rev = "";
	while (n>0)
	{
		rev += itoc(n%k);
		n/=k;
	}
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	while (cin >> s)
	{
		if (s[0] == '-') return 0;
		if (s[1] == 'x') cout << stoi(s,16) << '\n';
		else
		{
			cout << "0x";
			itos(stoi(s,10),16);
			for (int i=rev.size()-1; i>=0; i--)
				cout << rev[i];
			cout << '\n';
		}
	}
}

