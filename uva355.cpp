#include<iostream>
using namespace std;
#define ll long long

inline int ctoi( char c)
{
	if ('A'<=c&&c<='Z') return (c-'A'+10);
	else return (c-'0');
}
inline char itoc( int n)
{
	if (0<=n&&n<=9) return '0'+n;
	else return 'A'+n;
}

inline ll stoi( string s, int n)
{
	ll res = 0;
	for (int i=0; i<s.size(); i++)
		res *= n, res += ctoi(s[i]);
	return res;
}

string res;
inline void itos( int x, int n)
{
	res = "";
	if (x==0) res = "0";
	else
	{
		while (x>0)
		{
			res += itoc(x%n);
			x/=n;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	string s;

	while (cin >> m >> n >> s)
	{
		int k=2;
		for (int i=0; i<s.size(); i++)
			k = max(k,ctoi(s[i])+1);
		if (k>m)
			cout << s << " is an illegal base " << m << " number\n";
		else
		{
			itos (stoi(s,m), n);
			cout << s<< " base " << m << " = ";
			for (int i=res.size()-1; i>=0; i--)
				cout << res[i];
			cout << " base " << n << "\n";
		}
	
	}
	return 0;
}
