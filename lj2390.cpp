#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 5e4+10;
int t, n, a[N];

inline int cmp (int i, int j)
{
	return i>j;
}

signed main()
{
	cin >> t >> n;
	rep(i,1,n) cin >> a[i];

	int ans = 0;

	sort(a+1,a+1+n);
	rep(i,1,n)
	{
		if (a[i] > 0) break;
		int tmp = t + a[i]*2;
		int x = upper_bound(a+1,a+1+n,tmp)-a;
		ans = max(ans, x-i);
	}
	
	sort(a+1,a+1+n,cmp);
	rep(i,1,n)
	{
		if (a[i] < 0) break;
		int tmp = t - a[i]*2;
		int x = upper_bound(a+1,a+1+n,-tmp,cmp)-a;
		ans = max(ans, x-i);
	}

	cout << ans << '\n';
}
