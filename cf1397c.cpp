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

signed main()
{
	int n;
	cin >> n;
	rep(i,1,n) cin >> a[i];
	if (n==1)
	{
		cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n' << -a[1] << '\n';
	}
	else
	{
		cout << 1 << ' ' << 1 << '\n' << -a[1] << '\n';
		a[1] = 0;
		cout << 2 << ' ' << n << '\n';
		rep(i,2,n) cout << a[i]*(n-1) << ' ', a[i] += a[i]*(n-1);
		cout << '\n';
		cout << 1 << ' ' << n << '\n';
		rep(i,1,n) cout << -a[i] << ' ';
		cout << '\n';
	}
}
