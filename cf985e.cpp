#include <bits/stdc++.h>
#define int long long 
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define endl '\n'
#define ff first
#define ss second
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 5e5+10;

int n, k, d, a[N], dp[N], sum[N];

signed main()
{
	cin >> n >> k >> d;
	rep(i,1,n) cin >> a[i];

	sort(a+1,a+1+n);

	rep(i,k,n)
	{
		int l = lower_bound(a+1,a+1+n,a[i]-d)-a-1;
		int r = i-k;
		dp[i] = (l==0? 1: sum[r]-sum[l-1]>0);
		sum[i] = sum[i-1]+dp[i];
//		de(i), de(a[i]), de(l), de(r), de(dp[i]), dd;
	}
	cout << (dp[n]? "YES":"NO") << endl;
}
