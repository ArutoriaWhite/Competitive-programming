#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define int long long
using namespace std;

int t, n;

signed main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		int ans = 0;
		rep(i,1,n)
		{
			int x;
			cin >> x;
			ans ^= x;
		}
		cout << (ans? "Yes":"No") << '\n';
	}
}
