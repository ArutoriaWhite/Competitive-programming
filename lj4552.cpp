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

int a[N], dif[N], p, q, n;

signed main()
{
	pui
	cin >> n;
	rep(i,1,n) cin >> a[i];

	rep(i,1,n)
	{
		dif[i] = a[i] - a[i-1];
	}

	rep(i,2,n)
	{
		if (dif[i] < 0) q += -dif[i];
		else p += dif[i];
	}

	cout << max(p, q) << '\n';
	cout << abs(p-q) + 1 << '\n';
}
