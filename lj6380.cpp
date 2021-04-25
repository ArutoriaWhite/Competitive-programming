#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;
int a, b, p[N], res[N];

signed main()
{
	cin >> a >> b;
	rep(i,1,b)
	{
		char c;
		cin >> c;
		p[i] = c-'0';	
	}
	if (a == 10 && p[1]==1)
	{
		cout << -1 << '\n';
		return 0;
	}
	int curmod = 0;
	rep(i,1,b)
	{
		if (i == 1)
		{
			if (p[i] == 1)
			{
				res[i] = a;
			}
			else
			{
				res[i] = 1;
			}
		}
		else
		{
			if (p[i] == 1)
			{
				if (curmod%a == 0) res[i] = 0;
				else res[i] = a-curmod%a;	
			}
			else
			{
				if (curmod%a == 0) res[i] = 1;
				else res[i] = 0;
			}
		}
		curmod = (curmod+res[i])*10%a;
	}
	rep(i,1,b)
	{
		cout << res[i];
	}
	cout << '\n';
}
