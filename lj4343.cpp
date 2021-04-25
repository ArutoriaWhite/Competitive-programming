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

int n, k, a[N];

int calc (int lim)
{
	int cur = 0, res = 0;
	rep(i,1,n)
	{
		cur += a[i];
		if (cur < 0)
			cur = 0;
		else if (cur >= lim)
			cur = 0, res++;
	}
	return res;
}

int lwb ()
{
	int i = 0, s = 1e15;
	while (s > 0)
	{
		if (calc(i+s) > k)
			i += s;
		else
			s >>= 1;
	}
	return i;
}
int upb ()
{
	int i = 0, s = 1e15;
	while (s > 0)
	{
		if (calc(i+s) >= k)
			i += s;
		else
			s >>= 1;
	}
	return i;
}

signed main()
{
	pui
	cin >> n >> k;
	rep(i,1,n) cin >> a[i];
	int l = lwb(), u = upb();
	if (l == u) cout << -1 << '\n';
	else cout << l+1 << ' ' << u << '\n';
}
