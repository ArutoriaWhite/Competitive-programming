#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int a[N], n;

int qpow (int x, int k)
{
	int res = 1;
	while (k)
	{
		if (k&1) res = res*x;
		k >>= 1;
		x = x*x;
	}
	return res;
}
int cost (int k)
{
	int res = 0;
	rep(i,1,n)
		res += abs(a[i] - qpow(k,i-1));
	return res;
}

signed main()
{
	XinAi
	cin >> n;
	rep(i,1,n) cin >> a[i];
	sort(a+1, a+1+n);
	if (n > 33)
	{
		cout << min(cost(1), cost(0)) << '\n';
	}
	else
	{
		int i=0;
		while (qpow(i+1,n-1) <= a[n]) i++;
		cout << min(cost(i), cost(i+1)) << '\n';
	}
}
