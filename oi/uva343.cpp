#include<iostream>
using namespace std;
#define ll long long

int ctoi( char c)
{
	if ('A'<=c&&c<='Z') return (c-'A'+10);
	else return (c-'0');
}
ll stoi( string s, int n)
{
	ll res = 0;
	for ( int i=0,len=s.size(); i<len; res+=ctoi(s[i]),i++)
		res*=n;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string a, b;
	while (cin >> a >> b)
	{
		int n=2, m=2;
		for (int i=0; i<a.size(); i++)
			n = max( n, ctoi(a[i])+1);
		for (int i=0; i<b.size(); i++)
			m = max( m, ctoi(b[i])+1);
		
		bool flag=1;
		for (int i=n; i<=36&&flag; i++)
			for (int j=m; j<=36&&flag; j++)
				if (stoi(a,i) == stoi(b,j))
					cout << a << " (base " << i << ") = "
					     << b << " (base " << j << ")\n", flag=0;
		if (flag) cout << a << " is not equal to " << b << " in any base 2..36\n";
	}
}
