#include <iostream>
#define DE cout << " ::"
using namespace std;

int n;
string s;

inline int enumAlph()
{
	int res = n-1;
	for (int i=n-2; n-(i+1)<=i; i--)
	{
		int l, r, flag=1;
		for (l=i-1,r=i+1; l>=0&&r<n; l--,r++)
		{
			if (s[l]!=s[r])
			{
				flag=0;
				break;
			}
		}
		if (flag) res = min(res,2*i-n+2);
	}
	return res;
}
inline int enumMid()
{
	int res = n-1;
	for (int i=n-1; n-i<=i; i--)
	{
		int l, r, flag=1;
		for (l=i-1,r=i; r<n&&l>=0; l--,r++)
		{
			if (s[l]!=s[r])
			{
				flag=0;
				break;
			}
		}
		if (flag) res = min(2*i-n,res);
	}
	return res;
}

int main()
{
	cin >> n >> s;
	if (n==1) cout << "0\n";
	else cout << min(enumAlph(),enumMid()) << '\n';
}
