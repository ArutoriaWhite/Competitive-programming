#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

/*
每個 pair 需要 cost 1
但如果是 1/1 只需要總共 cost m
問多少 cost
*/
const int N = 1000;
int a[N], n, tp, m, q[N];

signed main()
{
	cin >> n >> m >> tp;
	
	rep(i,1,n) cin >> a[i];
	rep(i,1,n) cin >> q[i];

	int cnt = 0;
	rep(i,1,n)
	{
		if (a[i] && q[i])
		{
			cnt++;
		}
	}
	if (cnt >= m)
	{
		cout << n-cnt+m << '\n';
	}
	else
	{
		cout << n << '\n';
	}
}
