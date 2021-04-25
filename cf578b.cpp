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

const int N = 2e5+10;

int n, k, x, a[N];
int pre[N], suf[N];

signed main()
{
	pui
	cin >> n >> k >> x;
	rep(i,1,n) cin >> a[i];

	rep(i,1,n)
	{
		pre[i] = pre[i-1] | a[i];
	}
	for (int i=n; i>0; i--)
	{
		suf[i] = suf[i+1] | a[i];
	}

	int ans = 0, owo = 1;
	rep(i,1,k) owo *= x;

	rep(i,1,n)
	{
		ans = max(ans, a[i]*owo|pre[i-1]|suf[i+1]);
	}
	cout << ans << '\n';
}
