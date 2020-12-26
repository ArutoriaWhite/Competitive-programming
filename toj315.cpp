#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define int long long
using namespace std;
typedef pair<int,int> pii;

int qpow (int a, int b, int m)
{
	__int128 res=1;
	for (__int128 x=a; b; b>>=1,x=(x*x)%m)
		if (b&1) res = (res*x)%m;
	return res;
}

signed main()
{
	XinAi
	int t, a, b, m;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> m;
		cout << qpow(a,b,m) << '\n';
	}
}
