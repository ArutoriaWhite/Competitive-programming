#include<iostream>
#include<string.h>
using namespace std;

int q[10000], ap[100000000];

inline void init()
{
	memset(q,0,sizeof(q));
	memset(ap,-1,sizeof(ap));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, d;
	while (cin >> n >> d)
	{
		init();
		int b=0, e=0;
		
		cout << n << "/" << d << " = ";
		
		for (int i=0; e==0; i++,n=(n%d)*10)
		{
			q[i] = n/d;
			int r = (n%d);
			if (ap[r] != -1)
			{
				b = ap[r]+1;
				e = i;
			}
			else
			{
				ap[r] = i;
			}
		}
		
		for (int i=0; i<=e&&(i-b<50); i++)
		{
			if (i==b) cout << '(';
			cout << q[i];
			if (i==0) cout << '.';
			if (i==e) cout << ')';
		}
		if (e-b+1>50) cout << "...)";
		cout << '\n';
		cout << "   " << (e-b+1) << " = number of digits in repeating cycle\n\n";
	}
}
