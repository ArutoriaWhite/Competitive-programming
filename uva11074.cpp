#include<iostream>
using namespace std;

int n, s, t, l;
inline void line ()
{
	for (int j=0; j<t; j++)
	{
		for (int i=0; i<l; i++)
			cout << '*';
		cout << '\n';		
	}
}

inline void squ ()
{
	for (int i=0; i<s; i++)
	{
		for (int j=0; j<l; j++)
		{
			if (j%(s+t)<t) cout << '*';
			else cout << '.';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int u=0;
	bool fir=1;
	while (cin >> s >> t >> n)
	{
		if (s==0 && t==0 && n==0) return 0;
		cout << "Case " << ++u << ":\n";
		
		l=(s+t)*n+t;
		for (int i=0; i<n; i++)
		{
			if (i==0) line();
			squ();
			line();
		}
		cout << "\n";
	}
}
